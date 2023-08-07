#region License
/* 
 * Copyright (C) 1999-2023 John Källén.
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

using Reko.Gui.ViewModels.Dialogs;
using Reko.Scanning;
using System;

namespace Reko.UserInterfaces.WindowsForms.Forms
{
    internal class FindStringsDialogInteractor
    {
        private FindStringsDialog dlg;
        private readonly FindStringsViewModel viewModel;

        public FindStringsDialogInteractor()
        {
            this.viewModel = new FindStringsViewModel();
        }

        public void Attach(FindStringsDialog dlg)
        {
            this.dlg = dlg;
            dlg.Load += Dialog_Load;
        }

        private void Dialog_Load(object sender, EventArgs e)
        {
            dlg.StringKindList.SelectedIndex = 0;
            dlg.CharacterSizeList.SelectedIndex = 0;
        }

        public StringFinderCriteria GetCriteria() => viewModel.GetCriteria(
            dlg.CharacterSizeList.SelectedIndex,
            dlg.StringKindList.SelectedIndex,
            dlg.MinLength);
    }
}