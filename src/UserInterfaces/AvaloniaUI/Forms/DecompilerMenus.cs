#region License
/* 
 * Copyright (C) 1999-2021 John Källén.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#endregion

// This file is automatically generated. DO NOT MAKE CHANGES TO IT, as they will be overwritten next time the 
// project compiles.
// This file was generated from reko/src/GUI/decompiler-menus.xml using the reko/src/UserInterfaces/AvaloniaUI/Forms/decompiler-menus.xslt
// stylesheet. The intent of this file is to automatically generate the menus for the Windows Decompiler based on 
// the XML file. This saves developer effort when menu item verbs are added, removed, or changed.

using Reko.Gui;
using Reko.UserInterfaces.AvaloniaUI.Controls;
using System;
using System.Collections;
using System.ComponentModel.Design;

namespace Reko.UserInterfaces.AvaloniaUI.Forms
{
    public class DecompilerMenus : MenuSystem   
    {
#if NOT_YET    
	public readonly System.Windows.Forms.MenuStrip MainMenu;
	public readonly System.Windows.Forms.ContextMenuStrip CtxMemoryControl;
	public readonly System.Windows.Forms.ContextMenuStrip CtxDisassembler;
	public readonly System.Windows.Forms.ContextMenuStrip CtxBrowser;
	public readonly System.Windows.Forms.ContextMenuStrip CtxProcedureList;
	public readonly System.Windows.Forms.ContextMenuStrip CtxProcedure;
	public readonly System.Windows.Forms.ContextMenuStrip CtxAddressSearch;
	public readonly System.Windows.Forms.ContextMenuStrip CtxCodeView;
	public readonly System.Windows.Forms.ToolStrip MainToolbar;
	public readonly System.Windows.Forms.ToolStrip ProjectBrowserToolbar;

#endif 
        public DecompilerMenus(ICommandTarget target) : base(target)
        {}
#if NOT_YET          
        {
			SortedList slMainMenu = CreatePriorityList();
			SortedList slFileMenu = CreatePriorityList();
			SortedList slEditMenu = CreatePriorityList();
			SortedList slViewMenu = CreatePriorityList();
			SortedList slActionMenu = CreatePriorityList();
			SortedList slToolsMenu = CreatePriorityList();
			SortedList slWindowsMenu = CreatePriorityList();
			SortedList slHelpMenu = CreatePriorityList();
			SortedList slTextEncodingMenu = CreatePriorityList();
			SortedList slCtxMemoryControl = CreatePriorityList();
			SortedList slCtxDisassembler = CreatePriorityList();
			SortedList slCtxBrowser = CreatePriorityList();
			SortedList slCtxProcedureList = CreatePriorityList();
			SortedList slCtxProcedure = CreatePriorityList();
			SortedList slCtxAddressSearch = CreatePriorityList();
			SortedList slCtxCodeView = CreatePriorityList();
			SortedList slMainToolbar = CreatePriorityList();
			SortedList slProjectBrowserToolbar = CreatePriorityList();
			
			// Create groups
			
			SortedList slGrpMain = CreatePriorityList();
			slMainMenu.Add(0, slGrpMain);
			SortedList slGrpFile = CreatePriorityList();
			slFileMenu.Add(0, slGrpFile);
			SortedList slGrpFileMru = CreatePriorityList();
			slFileMenu.Add(0, slGrpFileMru);
			SortedList slGrpFileEnd = CreatePriorityList();
			slFileMenu.Add(1000, slGrpFileEnd);
			SortedList slGrpEdit = CreatePriorityList();
			slEditMenu.Add(0, slGrpEdit);
			SortedList slGrpView = CreatePriorityList();
			slViewMenu.Add(0, slGrpView);
			SortedList slGrpLowLevel = CreatePriorityList();
			slViewMenu.Add(0, slGrpLowLevel);
			SortedList slGrpViewScanned = CreatePriorityList();
			slViewMenu.Add(0, slGrpViewScanned);
			SortedList slGrpTextEncoding = CreatePriorityList();
			slTextEncodingMenu.Add(0, slGrpTextEncoding);
			SortedList slGrpActions = CreatePriorityList();
			slActionMenu.Add(0, slGrpActions);
			SortedList slGrpActionsScanned = CreatePriorityList();
			slActionMenu.Add(0, slGrpActionsScanned);
			SortedList slGrpActionsRewritten = CreatePriorityList();
			slActionMenu.Add(0, slGrpActionsRewritten);
			SortedList slGrpTools = CreatePriorityList();
			slToolsMenu.Add(0, slGrpTools);
			SortedList slGrpWindows = CreatePriorityList();
			slWindowsMenu.Add(0, slGrpWindows);
			SortedList slGrpHelp = CreatePriorityList();
			slHelpMenu.Add(0, slGrpHelp);
			SortedList slGrpMemoryControl = CreatePriorityList();
			slCtxMemoryControl.Add(0, slGrpMemoryControl);
			SortedList slGrpDisassemblerNav = CreatePriorityList();
			slCtxDisassembler.Add(0, slGrpDisassemblerNav);
			SortedList slGrpDisassemblerShow = CreatePriorityList();
			slCtxDisassembler.Add(0, slGrpDisassemblerShow);
			SortedList slGrpDisassemblerEdit = CreatePriorityList();
			slCtxDisassembler.Add(0, slGrpDisassemblerEdit);
			SortedList slGrpCodeView = CreatePriorityList();
			slCtxCodeView.Add(0, slGrpCodeView);
			SortedList slGrpCodeViewMode = CreatePriorityList();
			slCtxCodeView.Add(0, slGrpCodeViewMode);
			SortedList slGrpBrowser = CreatePriorityList();
			slCtxBrowser.Add(0, slGrpBrowser);
			SortedList slGrpBrowserProc = CreatePriorityList();
			SortedList slGrpToolbarFileOps = CreatePriorityList();
			slMainToolbar.Add(0, slGrpToolbarFileOps);
			SortedList slGrpToolbarActions = CreatePriorityList();
			slMainToolbar.Add(0, slGrpToolbarActions);
			SortedList slGrpBrowserToolbar = CreatePriorityList();
			slProjectBrowserToolbar.Add(0, slGrpBrowserToolbar);
			SortedList slGrpProcedure = CreatePriorityList();
			slCtxProcedure .Add(0, slGrpProcedure);
			SortedList slGrpProcedureListDebug = CreatePriorityList();
			slCtxProcedureList .Add(0, slGrpProcedureListDebug);
			SortedList slGrpAddressSearchView = CreatePriorityList();
			slCtxAddressSearch.Add(0, slGrpAddressSearchView);
			SortedList slGrpAddressSearch = CreatePriorityList();
			slCtxAddressSearch.Add(0, slGrpAddressSearch);
    
			// Create commands in containers.
            
            CommandMenuItem slFileOpen = new CommandMenuItem("_Open...", new Guid(CmdSets.Reko), CmdIds.FileOpen);
            slFileOpen.IsDynamic = false;
            slFileOpen.ImageIndex = 0;
            
            CommandMenuItem slFileOpenAs = new CommandMenuItem("Op_en As...", new Guid(CmdSets.Reko), CmdIds.FileOpenAs);
            slFileOpenAs.IsDynamic = false;
            
            CommandMenuItem slFileSave = new CommandMenuItem("_Save", new Guid(CmdSets.Reko), CmdIds.FileSave);
            slFileSave.IsDynamic = false;
            slFileSave.ImageIndex = 1;
            
            CommandMenuItem slFileNewScript = new CommandMenuItem("New script file...", new Guid(CmdSets.Reko), CmdIds.FileNewScript);
            slFileNewScript.IsDynamic = false;
            
            CommandMenuItem slFileAddBinary = new CommandMenuItem("Add _binary file...", new Guid(CmdSets.Reko), CmdIds.FileAddBinary);
            slFileAddBinary.IsDynamic = false;
            
            CommandMenuItem slFileAddMetadata = new CommandMenuItem("Add _metadata file...", new Guid(CmdSets.Reko), CmdIds.FileAddMetadata);
            slFileAddMetadata.IsDynamic = false;
            
            CommandMenuItem slFileAddScript = new CommandMenuItem("Add _script file...", new Guid(CmdSets.Reko), CmdIds.FileAddScript);
            slFileAddScript.IsDynamic = false;
            
            CommandMenuItem slFileAssemble = new CommandMenuItem("Add asse_mbler file...", new Guid(CmdSets.Reko), CmdIds.FileAssemble);
            slFileAssemble.IsDynamic = false;
            
            CommandMenuItem slFileCloseProject = new CommandMenuItem("Close projec_t", new Guid(CmdSets.Reko), CmdIds.FileCloseProject);
            slFileCloseProject.IsDynamic = false;
            
            CommandMenuItem slFileMru = new CommandMenuItem("", new Guid(CmdSets.Reko), CmdIds.FileMru);
            slFileMru.IsDynamic = true;
            slGrpFileMru.Add(0, slFileMru);
            CommandMenuItem slFileExit = new CommandMenuItem("E_xit", new Guid(CmdSets.Reko), CmdIds.FileExit);
            slFileExit.IsDynamic = false;
            slGrpFileEnd.Add(0, slFileExit);
            CommandMenuItem slEditFind = new CommandMenuItem("_Find...", new Guid(CmdSets.Reko), CmdIds.EditFind);
            slEditFind.IsDynamic = false;
            slGrpEdit.Add(0, slEditFind);
            CommandMenuItem slEditCopy = new CommandMenuItem("_Copy", new Guid(CmdSets.Reko), CmdIds.EditCopy);
            slEditCopy.IsDynamic = false;
            
            CommandMenuItem slEditCopyAll = new CommandMenuItem("_Copy All", new Guid(CmdSets.Reko), CmdIds.EditCopyAll);
            slEditCopyAll.IsDynamic = false;
            
            CommandMenuItem slEditRename = new CommandMenuItem("_Rename", new Guid(CmdSets.Reko), CmdIds.EditRename);
            slEditRename.IsDynamic = false;
            slGrpEdit.Add(0, slEditRename);
            CommandMenuItem slEditRegisterValues = new CommandMenuItem("Re_gister Values", new Guid(CmdSets.Reko), CmdIds.EditRegisterValues);
            slEditRegisterValues.IsDynamic = false;
            slGrpEdit.Add(0, slEditRegisterValues);
            CommandMenuItem slEditAnnotation = new CommandMenuItem("Co_mment", new Guid(CmdSets.Reko), CmdIds.EditAnnotation);
            slEditAnnotation.IsDynamic = false;
            slGrpEdit.Add(0, slEditAnnotation);
            CommandMenuItem slEditSelectAll = new CommandMenuItem("Select _all", new Guid(CmdSets.Reko), CmdIds.EditSelectAll);
            slEditSelectAll.IsDynamic = false;
            slGrpEdit.Add(0, slEditSelectAll);
            CommandMenuItem slEditProperties = new CommandMenuItem("P_roperties", new Guid(CmdSets.Reko), CmdIds.EditProperties);
            slEditProperties.IsDynamic = false;
            
            CommandMenuItem slViewProjectBrowser = new CommandMenuItem("Project _browser", new Guid(CmdSets.Reko), CmdIds.ViewProjectBrowser);
            slViewProjectBrowser.IsDynamic = false;
            slGrpView.Add(0, slViewProjectBrowser);
            CommandMenuItem slViewProcedureList = new CommandMenuItem("_Procedure list", new Guid(CmdSets.Reko), CmdIds.ViewProcedureList);
            slViewProcedureList.IsDynamic = false;
            slGrpView.Add(0, slViewProcedureList);
            CommandMenuItem slViewMemory = new CommandMenuItem("_Memory", new Guid(CmdSets.Reko), CmdIds.ViewMemory);
            slViewMemory.IsDynamic = false;
            slGrpLowLevel.Add(0, slViewMemory);
            CommandMenuItem slViewDisassembly = new CommandMenuItem("_Disassembly", new Guid(CmdSets.Reko), CmdIds.ViewDisassembly);
            slViewDisassembly.IsDynamic = false;
            slGrpLowLevel.Add(0, slViewDisassembly);
            CommandMenuItem slTextEncodingChoose = new CommandMenuItem("_Choose...", new Guid(CmdSets.Reko), CmdIds.TextEncodingChoose);
            slTextEncodingChoose.IsDynamic = false;
            slGrpTextEncoding.Add(0, slTextEncodingChoose);
            CommandMenuItem slViewCallGraph = new CommandMenuItem("_Call graph", new Guid(CmdSets.Reko), CmdIds.ViewCallGraph);
            slViewCallGraph.IsDynamic = false;
            slGrpLowLevel.Add(0, slViewCallGraph);
            CommandMenuItem slOpenLink = new CommandMenuItem("_Open", new Guid(CmdSets.Reko), CmdIds.OpenLink);
            slOpenLink.IsDynamic = false;
            
            CommandMenuItem slOpenLinkInNewWindow = new CommandMenuItem("Open in ne_w window", new Guid(CmdSets.Reko), CmdIds.OpenLinkInNewWindow);
            slOpenLinkInNewWindow.IsDynamic = false;
            
            CommandMenuItem slViewGoToAddress = new CommandMenuItem("_Go to Address...", new Guid(CmdSets.Reko), CmdIds.ViewGoToAddress);
            slViewGoToAddress.IsDynamic = false;
            slGrpViewScanned.Add(0, slViewGoToAddress);
            CommandMenuItem slViewFindAllProcedures = new CommandMenuItem("Find all _procedures", new Guid(CmdSets.Reko), CmdIds.ViewFindAllProcedures);
            slViewFindAllProcedures.IsDynamic = false;
            slGrpViewScanned.Add(0, slViewFindAllProcedures);
            CommandMenuItem slViewShowAllFragments = new CommandMenuItem("Show _all fragments", new Guid(CmdSets.Reko), CmdIds.ViewShowAllFragments);
            slViewShowAllFragments.IsDynamic = false;
            slGrpViewScanned.Add(0, slViewShowAllFragments);
            CommandMenuItem slViewShowUnscanned = new CommandMenuItem("Show _unscanned fragments", new Guid(CmdSets.Reko), CmdIds.ViewShowUnscanned);
            slViewShowUnscanned.IsDynamic = false;
            slGrpViewScanned.Add(0, slViewShowUnscanned);
            CommandMenuItem slViewFindPattern = new CommandMenuItem("Find selected _pattern...", new Guid(CmdSets.Reko), CmdIds.ViewFindPattern);
            slViewFindPattern.IsDynamic = false;
            slGrpViewScanned.Add(0, slViewFindPattern);
            CommandMenuItem slViewFindStrings = new CommandMenuItem("Find _strings...", new Guid(CmdSets.Reko), CmdIds.ViewFindStrings);
            slViewFindStrings.IsDynamic = false;
            slGrpViewScanned.Add(0, slViewFindStrings);
            CommandMenuItem slViewFindWhatPointsHere = new CommandMenuItem("Find _what points here", new Guid(CmdSets.Reko), CmdIds.ViewFindWhatPointsHere);
            slViewFindWhatPointsHere.IsDynamic = false;
            slGrpViewScanned.Add(0, slViewFindWhatPointsHere);
            CommandMenuItem slViewAsCode = new CommandMenuItem("View as _code", new Guid(CmdSets.Reko), CmdIds.ViewAsCode);
            slViewAsCode.IsDynamic = false;
            slGrpAddressSearchView.Add(0, slViewAsCode);
            CommandMenuItem slViewAsStrings = new CommandMenuItem("View as _strings", new Guid(CmdSets.Reko), CmdIds.ViewAsStrings);
            slViewAsStrings.IsDynamic = false;
            slGrpAddressSearchView.Add(0, slViewAsStrings);
            CommandMenuItem slViewAsData = new CommandMenuItem("View as _data", new Guid(CmdSets.Reko), CmdIds.ViewAsData);
            slViewAsData.IsDynamic = false;
            slGrpAddressSearchView.Add(0, slViewAsData);
            CommandMenuItem slViewCfgCode = new CommandMenuItem("View _code", new Guid(CmdSets.Reko), CmdIds.ViewCfgCode);
            slViewCfgCode.IsDynamic = false;
            slGrpCodeViewMode.Add(1, slViewCfgCode);
            CommandMenuItem slViewCfgGraph = new CommandMenuItem("View control _graph", new Guid(CmdSets.Reko), CmdIds.ViewCfgGraph);
            slViewCfgGraph.IsDynamic = false;
            slGrpCodeViewMode.Add(2, slViewCfgGraph);
            CommandMenuItem slViewPcRelative = new CommandMenuItem("Show _PC relative addresses", new Guid(CmdSets.Reko), CmdIds.ViewPcRelative);
            slViewPcRelative.IsDynamic = false;
            slGrpLowLevel.Add(0, slViewPcRelative);
            CommandMenuItem slOpenInNewTab = new CommandMenuItem("Open in new tab", new Guid(CmdSets.Reko), CmdIds.OpenInNewTab);
            slOpenInNewTab.IsDynamic = false;
            slGrpCodeView.Add(0, slOpenInNewTab);
            CommandMenuItem slEditDeclaration = new CommandMenuItem("Edit declaration", new Guid(CmdSets.Reko), CmdIds.EditDeclaration);
            slEditDeclaration.IsDynamic = false;
            slGrpCodeView.Add(1, slEditDeclaration);
            CommandMenuItem slEditComment = new CommandMenuItem("Edit comment", new Guid(CmdSets.Reko), CmdIds.EditComment);
            slEditComment.IsDynamic = false;
            slGrpCodeView.Add(2, slEditComment);
            CommandMenuItem slEditLabel = new CommandMenuItem("Edit label", new Guid(CmdSets.Reko), CmdIds.EditLabel);
            slEditLabel.IsDynamic = false;
            slGrpCodeView.Add(2, slEditLabel);
            CommandMenuItem slActionRestartDecompilation = new CommandMenuItem("_Restart", new Guid(CmdSets.Reko), CmdIds.ActionRestartDecompilation);
            slActionRestartDecompilation.IsDynamic = false;
            slActionRestartDecompilation.ImageIndex = 2;
            slGrpActions.Add(0, slActionRestartDecompilation);
            CommandMenuItem slActionNextPhase = new CommandMenuItem("_Next Phase", new Guid(CmdSets.Reko), CmdIds.ActionNextPhase);
            slActionNextPhase.IsDynamic = false;
            slActionNextPhase.ImageIndex = 3;
            slGrpActions.Add(0, slActionNextPhase);
            CommandMenuItem slActionFinishDecompilation = new CommandMenuItem("Finish _Decompilation", new Guid(CmdSets.Reko), CmdIds.ActionFinishDecompilation);
            slActionFinishDecompilation.IsDynamic = false;
            slActionFinishDecompilation.ImageIndex = 4;
            slGrpActions.Add(0, slActionFinishDecompilation);
            CommandMenuItem slActionMarkProcedure = new CommandMenuItem("Mark _Procedure Entry", new Guid(CmdSets.Reko), CmdIds.ActionMarkProcedure);
            slActionMarkProcedure.IsDynamic = false;
            
            CommandMenuItem slActionCallTerminates = new CommandMenuItem("Mark call as _terminating", new Guid(CmdSets.Reko), CmdIds.ActionCallTerminates);
            slActionCallTerminates.IsDynamic = false;
            slGrpDisassemblerEdit.Add(0, slActionCallTerminates);
            CommandMenuItem slActionScanHeuristically = new CommandMenuItem("Scan _heuristically", new Guid(CmdSets.Reko), CmdIds.ActionScanHeuristically);
            slActionScanHeuristically.IsDynamic = false;
            
            CommandMenuItem slActionEditSignature = new CommandMenuItem("Edit _Signature...", new Guid(CmdSets.Reko), CmdIds.ActionEditSignature);
            slActionEditSignature.IsDynamic = false;
            
            CommandMenuItem slActionMarkType = new CommandMenuItem("Mark _Type", new Guid(CmdSets.Reko), CmdIds.ActionMarkType);
            slActionMarkType.IsDynamic = false;
            
            CommandMenuItem slActionMarkStrings = new CommandMenuItem("Mark selection as _strings", new Guid(CmdSets.Reko), CmdIds.ActionMarkStrings);
            slActionMarkStrings.IsDynamic = false;
            
            CommandMenuItem slActionAssumeRegisterValues = new CommandMenuItem("_Register values...", new Guid(CmdSets.Reko), CmdIds.ActionAssumeRegisterValues);
            slActionAssumeRegisterValues.IsDynamic = false;
            
            CommandMenuItem slToolsHexDisassembler = new CommandMenuItem("_Hex disassembler", new Guid(CmdSets.Reko), CmdIds.ToolsHexDisassembler);
            slToolsHexDisassembler.IsDynamic = false;
            slGrpTools.Add(0, slToolsHexDisassembler);
            CommandMenuItem slToolsOptions = new CommandMenuItem("_Options...", new Guid(CmdSets.Reko), CmdIds.ToolsOptions);
            slToolsOptions.IsDynamic = false;
            slGrpTools.Add(0, slToolsOptions);
            CommandMenuItem slToolsKeyBindings = new CommandMenuItem("_Key bindings...", new Guid(CmdSets.Reko), CmdIds.ToolsKeyBindings);
            slToolsKeyBindings.IsDynamic = false;
            slGrpTools.Add(0, slToolsKeyBindings);
            CommandMenuItem slWindowsCascade = new CommandMenuItem("_Cascade", new Guid(CmdSets.Reko), CmdIds.WindowsCascade);
            slWindowsCascade.IsDynamic = false;
            slGrpWindows.Add(0, slWindowsCascade);
            CommandMenuItem slWindowsTileVertical = new CommandMenuItem("Tile _Vertically", new Guid(CmdSets.Reko), CmdIds.WindowsTileVertical);
            slWindowsTileVertical.IsDynamic = false;
            slGrpWindows.Add(0, slWindowsTileVertical);
            CommandMenuItem slWindowsTileHorizontal = new CommandMenuItem("Tile _Horizontally", new Guid(CmdSets.Reko), CmdIds.WindowsTileHorizontal);
            slWindowsTileHorizontal.IsDynamic = false;
            slGrpWindows.Add(0, slWindowsTileHorizontal);
            CommandMenuItem slWindowsCloseAll = new CommandMenuItem("C_lose All Windows", new Guid(CmdSets.Reko), CmdIds.WindowsCloseAll);
            slWindowsCloseAll.IsDynamic = false;
            slGrpWindows.Add(0, slWindowsCloseAll);
            CommandMenuItem slHelpAbout = new CommandMenuItem("_About Decompiler...", new Guid(CmdSets.Reko), CmdIds.HelpAbout);
            slHelpAbout.IsDynamic = false;
            slGrpHelp.Add(0, slHelpAbout);
            CommandMenuItem slShowProcedureCallHierarchy = new CommandMenuItem("Show Call _Hierarchy", new Guid(CmdSets.Reko), CmdIds.ShowProcedureCallHierarchy);
            slShowProcedureCallHierarchy.IsDynamic = false;
            slGrpProcedure.Add(0, slShowProcedureCallHierarchy);
            CommandMenuItem slProcedureDebugTrace = new CommandMenuItem("_Debug procedure decompilation", new Guid(CmdSets.Reko), CmdIds.ProcedureDebugTrace);
            slProcedureDebugTrace.IsDynamic = false;
            slGrpProcedureListDebug.Add(0, slProcedureDebugTrace);
            CommandMenuItem slCollapseAllNodes = new CommandMenuItem("", new Guid(CmdSets.Reko), CmdIds.CollapseAllNodes);
            slCollapseAllNodes.IsDynamic = false;
            slCollapseAllNodes.ImageKey = "Collapse.ico";
            slCollapseAllNodes.ToolTipText = "Collapse All";
            slGrpBrowserToolbar.Add(0, slCollapseAllNodes);
            CommandMenuItem slCreateUserSegment = new CommandMenuItem("", new Guid(CmdSets.Reko), CmdIds.CreateUserSegment);
            slCreateUserSegment.IsDynamic = false;
            slCreateUserSegment.ImageKey = "CreateSegment.ico";
            slCreateUserSegment.ToolTipText = "Create Segment";
            slGrpBrowserToolbar.Add(0, slCreateUserSegment);
            CommandMenuItem slLoadSymbols = new CommandMenuItem("Load Symbols...", new Guid(CmdSets.Reko), CmdIds.LoadSymbols);
            slLoadSymbols.IsDynamic = false;
            slGrpBrowser.Add(0, slLoadSymbols);
			
			// Create submenus
			
            CommandMenuItem miFileMenu = new CommandMenuItem("_File");
            slGrpMain.Add(0, miFileMenu);
            CommandMenuItem miEditMenu = new CommandMenuItem("_Edit");
            slGrpMain.Add(0, miEditMenu);
            CommandMenuItem miViewMenu = new CommandMenuItem("_View");
            slGrpMain.Add(0, miViewMenu);
            CommandMenuItem miActionMenu = new CommandMenuItem("_Actions");
            slGrpMain.Add(0, miActionMenu);
            CommandMenuItem miToolsMenu = new CommandMenuItem("_Tools");
            slGrpMain.Add(0, miToolsMenu);
            CommandMenuItem miWindowsMenu = new CommandMenuItem("_Windows");
            slGrpMain.Add(0, miWindowsMenu);
            CommandMenuItem miHelpMenu = new CommandMenuItem("_Help");
            slGrpMain.Add(0, miHelpMenu);
            CommandMenuItem miTextEncodingMenu = new CommandMenuItem("_Text Encoding");
            slGrpLowLevel.Add(0, miTextEncodingMenu);
    
			// Place commands.
			
			slGrpFile.Add(0, slFileOpen);
			slGrpFile.Add(0, slFileOpenAs);
			slGrpFile.Add(0, slFileSave);
			slGrpFile.Add(0, slFileCloseProject);
			slGrpFile.Add(0, slFileNewScript);
			slGrpFile.Add(0, slFileAddBinary);
			slGrpFile.Add(0, slFileAddMetadata);
			slGrpFile.Add(0, slFileAddScript);
			slGrpFile.Add(0, slFileAssemble);
			slCtxBrowser.Add(0, slGrpBrowserProc);
			slCtxProcedureList.Add(0, slGrpBrowserProc);
			slGrpToolbarFileOps.Add(0, slFileOpen);
			slGrpToolbarFileOps.Add(0, slFileSave);
			slGrpEdit.Add(0, slEditCopy);
			slGrpEdit.Add(0, slEditProperties);
			slGrpToolbarActions.Add(0, slActionRestartDecompilation);
			slGrpToolbarActions.Add(0, slActionNextPhase);
			slGrpToolbarActions.Add(0, slActionFinishDecompilation);
			slGrpActionsScanned.Add(0, slActionMarkProcedure);
			slGrpActionsScanned.Add(0, slActionScanHeuristically);
			slGrpActionsScanned.Add(0, slActionMarkType);
			slGrpMemoryControl.Add(0, slEditCopy);
			slGrpCodeView.Add(2, slEditCopy);
			slGrpMemoryControl.Add(0, slViewGoToAddress);
			slGrpMemoryControl.Add(0, slActionMarkProcedure);
			slGrpMemoryControl.Add(0, slActionMarkType);
			slGrpMemoryControl.Add(0, slViewFindPattern);
			slGrpMemoryControl.Add(0, slViewFindWhatPointsHere);
			slGrpDisassemblerNav.Add(0, slOpenLink);
			slGrpDisassemblerNav.Add(0, slOpenLinkInNewWindow);
			slGrpDisassemblerShow.Add(0, slViewPcRelative);
			slGrpDisassemblerEdit.Add(0, slEditCopy);
			slGrpDisassemblerEdit.Add(0, slEditRename);
			slGrpDisassemblerEdit.Add(0, slEditRegisterValues);
			slGrpDisassemblerEdit.Add(0, slEditAnnotation);
			slGrpProcedure.Add(0, slActionEditSignature);
			slGrpProcedure.Add(0, slViewGoToAddress);
			slGrpActionsRewritten.Add(0, slActionEditSignature);
			slGrpBrowser.Add(0, slEditProperties);
			slGrpBrowserProc.Add(0, slViewGoToAddress);
			slGrpBrowserProc.Add(0, slViewFindWhatPointsHere);
			slGrpBrowserProc.Add(0, slShowProcedureCallHierarchy);
			slGrpBrowserProc.Add(0, slActionEditSignature);
			slGrpBrowserProc.Add(0, slActionAssumeRegisterValues);
			slGrpAddressSearch.Add(0, slViewFindWhatPointsHere);
			slGrpAddressSearch.Add(0, slActionMarkProcedure);
			slGrpAddressSearch.Add(0, slActionMarkType);
			slGrpAddressSearch.Add(0, slActionMarkStrings);
			slGrpAddressSearch.Add(0, slActionScanHeuristically);
    
      // Build accelerators.
      
        AddBinding(
           "", 
          new Guid(CmdSets.Reko), 
          CmdIds.ActionMarkType, 
          (int)(Keys.T)
        
          , (int)(Keys.Control)
        );
      
        AddBinding(
           "Reko.Gui.Windows.CombinedCodeViewInteractor", 
          new Guid(CmdSets.Reko), 
          CmdIds.EditDeclaration, 
          (int)(Keys.D)
        
          , (int)(Keys.Control)
        );
      
        AddBinding(
           "Reko.Gui.Windows.CombinedCodeViewInteractor", 
          new Guid(CmdSets.Reko), 
          CmdIds.EditComment, 
          (int)(Keys.OemSemicolon)
        );
      
        AddBinding(
           "", 
          new Guid(CmdSets.Reko), 
          CmdIds.ActionNextSearchHit, 
          (int)(Keys.F8)
        );
      
        AddBinding(
           "", 
          new Guid(CmdSets.Reko), 
          CmdIds.ActionPrevSearchHit, 
          (int)(Keys.F8)
        
          , (int)(Keys.Shift)
        );
      
        AddBinding(
           "", 
          new Guid(CmdSets.Reko), 
          CmdIds.EditCopy, 
          (int)(Keys.C)
        
          , (int)(Keys.Control)
        );
      
        AddBinding(
           "Reko.Gui.Windows.CodeViewerPane", 
          new Guid(CmdSets.Reko), 
          CmdIds.EditCopyAll, 
          (int)(Keys.C)
        
          , (int)(Keys.Control)
        );
      
        AddBinding(
           "", 
          new Guid(CmdSets.Reko), 
          CmdIds.EditSelectAll, 
          (int)(Keys.A)
        
          , (int)(Keys.Control)
        );
      
			this.MainMenu = new System.Windows.Forms.MenuStrip();
			BuildMenu(slMainMenu, MainMenu.Items);
  
			BuildMenu(slFileMenu, miFileMenu.DropDownItems);
			
			BuildMenu(slEditMenu, miEditMenu.DropDownItems);
			
			BuildMenu(slViewMenu, miViewMenu.DropDownItems);
			
			BuildMenu(slActionMenu, miActionMenu.DropDownItems);
			
			BuildMenu(slToolsMenu, miToolsMenu.DropDownItems);
			
			BuildMenu(slWindowsMenu, miWindowsMenu.DropDownItems);
			
			BuildMenu(slHelpMenu, miHelpMenu.DropDownItems);
			
			BuildMenu(slTextEncodingMenu, miTextEncodingMenu.DropDownItems);
			
			this.CtxMemoryControl = new System.Windows.Forms.ContextMenuStrip();
			BuildMenu(slCtxMemoryControl, CtxMemoryControl.Items);
  
        this.CtxMemoryControl.Opening += ctxMenu_Popup;
      
			this.CtxDisassembler = new System.Windows.Forms.ContextMenuStrip();
			BuildMenu(slCtxDisassembler, CtxDisassembler.Items);
  
        this.CtxDisassembler.Opening += ctxMenu_Popup;
      
			this.CtxBrowser = new System.Windows.Forms.ContextMenuStrip();
			BuildMenu(slCtxBrowser, CtxBrowser.Items);
  
        this.CtxBrowser.Opening += ctxMenu_Popup;
      
			this.CtxProcedureList = new System.Windows.Forms.ContextMenuStrip();
			BuildMenu(slCtxProcedureList, CtxProcedureList.Items);
  
        this.CtxProcedureList.Opening += ctxMenu_Popup;
      
			this.CtxProcedure = new System.Windows.Forms.ContextMenuStrip();
			BuildMenu(slCtxProcedure, CtxProcedure.Items);
  
        this.CtxProcedure.Opening += ctxMenu_Popup;
      
			this.CtxAddressSearch = new System.Windows.Forms.ContextMenuStrip();
			BuildMenu(slCtxAddressSearch, CtxAddressSearch.Items);
  
        this.CtxAddressSearch.Opening += ctxMenu_Popup;
      
			this.CtxCodeView = new System.Windows.Forms.ContextMenuStrip();
			BuildMenu(slCtxCodeView, CtxCodeView.Items);
  
        this.CtxCodeView.Opening += ctxMenu_Popup;
      
			this.MainToolbar = new System.Windows.Forms.ToolStrip();
			BuildToolMenu(slMainToolbar, MainToolbar.Items);
  
			this.ProjectBrowserToolbar = new System.Windows.Forms.ToolStrip();
			BuildToolMenu(slProjectBrowserToolbar, ProjectBrowserToolbar.Items);
  
		}
		
		public override MenuStrip GetMenu(int menuId)
		{	
			switch (menuId)
			{
				case MenuIds.MainMenu: return this.MainMenu;
			}
			throw new ArgumentException(string.Format("There is no menu with id {0}.", menuId));
			
		}
		
		public override ContextMenuStrip GetContextMenu(int menuId)
		{
			
			switch (menuId)
			{
				case MenuIds.CtxMemoryControl: return this.CtxMemoryControl;
				case MenuIds.CtxDisassembler: return this.CtxDisassembler;
				case MenuIds.CtxBrowser: return this.CtxBrowser;
				case MenuIds.CtxProcedureList: return this.CtxProcedureList;
				case MenuIds.CtxProcedure: return this.CtxProcedure;
				case MenuIds.CtxAddressSearch: return this.CtxAddressSearch;
				case MenuIds.CtxCodeView: return this.CtxCodeView;
			}
			throw new ArgumentException(string.Format("There is no context menu with id {0}.", menuId));
		}
    
    public override ToolStrip GetToolStrip(int menuId)
    {
      
      switch (menuId)
      {
        case MenuIds.MainToolbar: return this.MainToolbar;
        case MenuIds.ProjectBrowserToolbar: return this.ProjectBrowserToolbar;
      }
      throw new ArgumentException(string.Format("There is no tool strip with id {0}.", menuId));
    }
#endif
    }
}
  