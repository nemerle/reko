﻿using Reko.Core;
using Reko.Core.Memory;
using Reko.Core.Rtl;
using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Reko.ScannerV2
{
    /// <summary>
    /// Performs scan of a chunk of memory that wasn't reached
    /// by the <see cref="RecursiveScanner"/>, finding blocks
    /// by doing linear scan.
    /// </summary>
    public class ChunkWorker : AbstractProcedureWorker
    {
        private ShingleScanner shScanner;
        private MemoryArea mem;
        private int[] blockNos; // 0 = not owned by anyone.

        public ChunkWorker(
            ShingleScanner scanner,
            IProcessorArchitecture arch,
            MemoryArea mem,
            Address addrStart,
            int chunkUnits)
            : base(scanner)
        {
            this.shScanner = scanner;
            this.Architecture = arch;
            this.mem = mem;
            this.Address = addrStart;
            this.Length = chunkUnits;
            this.blockNos = new int[chunkUnits];
        }

        public Address Address { get; }

        public IProcessorArchitecture Architecture { get; }

        public int Length { get; }

        public void Run()
        {
            var addrNext = this.Address;
            var stepsize = Architecture.InstructionBitSize / Architecture.MemoryGranularity;
            //for (int i = 0; i < chunkUnits; i += stepsize)
            {
                var state = Architecture.CreateProcessorState();
                var trace = shScanner.MakeTrace(addrNext, state, binder).GetEnumerator();
                while (IsValid(addrNext))
                {
                    var job = AddJob(addrNext, trace, state);
                    var (block, newState) = job.ParseBlock();
                    if (block.IsValid)
                    {
                        HandleBlockEnd(block, job.Trace, newState);
                    }
                    else
                    {
                        HandleBadBlock(block.Address);
                    }
                    // Don't use block.Fallthrough, because that would
                    // skip any instructions in delay slots.
                    addrNext = block.Address + block.Length;
                }
            }
        }

        private bool IsValid(Address addr)
        {
            var offset = addr - this.Address;
            return 0 <= offset && offset < blockNos.Length &&
                blockNos[offset] == 0;
        }

        public override AbstractBlockWorker AddJob(Address addr, IEnumerator<RtlInstructionCluster> trace, ProcessorState state)
        {
            return new ShingleWorker(shScanner, this, addr, trace, state);
        }

        public override bool MarkVisited(Address addr)
        {
            var oldValue = Interlocked.Exchange(ref blockNos[addr - this.Address], 1);
            return oldValue == 0;
        }

        protected override void ProcessCall(Block block, Edge edge, ProcessorState state)
        {
            throw new NotImplementedException();
        }

        protected override void ProcessReturn()
        {
        }
    }
}
