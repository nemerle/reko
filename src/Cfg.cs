﻿using Reko.Core;
using Reko.Core.Rtl;
using System.Collections.Concurrent;
using System.Collections.Generic;

namespace Reko.ScannerV2
{
    /// <summary>
    /// The Control Flow Graph of a program.
    /// </summary>
    public class Cfg
    {
        public Cfg()
        {
            this.Blocks = new();
            this.Successors = new();
            this.Procedures = new();
            this.Stubs = new();
            this.NoDecompiles = new();
        }

        /// <summary>
        /// Maps addresses to the <see cref="Block"/>s at those addresses.
        /// </summary>
        public ConcurrentDictionary<Address, Block> Blocks { get; }

        /// <summary>
        /// Maps start ("from") addresses to <see cref="Edge"/>s leaving those
        /// addresses.
        /// </summary>
        public ConcurrentDictionary<Address, List<Edge>> Successors { get; }

        /// <summary>
        /// Maps the entry point address to <see cref="Proc"/>s.
        /// </summary>
        public ConcurrentDictionary<Address, Proc> Procedures { get; }

        /// <summary>
        /// Short sequences of instructions identified as dynamic link stubs
        /// (such as those in an ELF PLT)
        /// </summary>
        public ConcurrentDictionary<Address, ExternalProcedure> Stubs { get; }
        public ConcurrentDictionary<Address, ExternalProcedure> NoDecompiles { get; }
    }

    public record Proc(
        Address Address,
        ProvenanceType Provenance,
        IProcessorArchitecture Architecture,
        string Name);

    /// <summary>
    /// This class models a basic block consisting of <see cref="RtlInstruction"/>s.
    /// </summary>
    /// <param name="Architecture">CPU architecture used to disassemble this block.</param>
    /// <param name="Id">Invariant identifier used for this block.</param>
    /// <param name="Address">Address at which the block starts.</param>
    /// <param name="Length">The size of the basic block starting at <see cref="Address"/> and
    /// including the length of the final instruction.</param>
    /// <param name="FallThrough">The address after the block if control flow falls through.
    /// Note that this is not necessarily <see cref="Address"/> + <see cref="Length"/>, because
    /// control instructions with delay slots may require skipping one extra instruction.
    /// </param>
    /// <param name="Instructions">The instructions this block consists of.</param>
    public record Block(
        IProcessorArchitecture Architecture,
        string Id,
        Address Address,
        int Length,
        Address FallThrough,
        List<(Address, RtlInstruction)> Instructions)
    {
        /// <summary>
        /// Indicates whether this block is valid or not.
        /// </summary>
        public bool IsInvalid { get; set; }
    }

    public enum EdgeType
    {
        Jump,
        Fallthrough,
        Call,
        Return,
    }

    /// <summary>
    /// Represents an edge in the <see cref="Cfg"/>.
    /// </summary>
    /// <param name="From">The address from which the edge goes.</param>
    /// <param name="To">The address to which the edge goes.</param>
    /// <param name="Type">The type of edge.</param>
    public record Edge(
        Address From,
        Address To,
        EdgeType Type);
}
