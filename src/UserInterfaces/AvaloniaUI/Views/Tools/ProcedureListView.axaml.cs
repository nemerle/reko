#region License
/* 
 * Copyright (C) 1999-2023 John K�ll�n.
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

using Avalonia.Controls;
using Avalonia.Interactivity;
using Avalonia.Markup.Xaml;
using Reko.UserInterfaces.AvaloniaUI.ViewModels.Tools;
using System;

namespace Reko.UserInterfaces.AvaloniaUI.Views.Tools
{
    public class ProcedureListView : UserControl
    {
        public ProcedureListView()
        {
            InitializeComponent();
        }

        private void InitializeComponent()
        {
            AvaloniaXamlLoader.Load(this);
        }

        private void procList_DoubleTapped(object sender, RoutedEventArgs e)
        {
            if (DataContext is not ProcedureListViewModel vm)
                return;
            if (sender is DataGrid procList && procList.SelectedItem is ProcedureListViewModel.ProcedureItem item)
            { 
                vm.SelectedProcedure = item;
            }
        }
    }
}
