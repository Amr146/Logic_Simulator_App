//#include "Input.h"
#include "Output.h"

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

void Input::GetCurrentPosition(int &x, int &y)
{
	pWind->GetMouseCoord(x, y);
}

string Input::GetSrting(Output *pOut)
{
	pWind->FlushKeyQueue();
	string s;
	char c;
	do
	{
		pWind->WaitKeyPress(c); //wait for key presse
		if (c == '\015') //return the user-entered string when the user presses "ENTER".
		{
			pOut->ClearStatusBar();
			pWind->FlushMouseQueue();
			return s;
		}
		else if (c == '\010') //delet the last character entered when the user presses "BACKSPACE".
		{
			if (s.length() == 0)
				continue;
			s.pop_back();
		}
		else if (c == '\033') //return an empty string when the user presses "ESCAPE".
		{
			pOut->ClearStatusBar();
			pWind->FlushMouseQueue();
			return "";
		}
		else
		{
			s.push_back(c);  //add the pressed character to the string variable.
		}
		pOut->PrintMsg(s);   //update the text displayed in the Status bar.
	} while (true);
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.AppMode == DESIGN )	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			if (!UI.displayCompBar)
			{
				switch (ClickedItemOrder)
				{
				case ITM_ADD: return COMP_BAR;
				case ITM_CONNECTION: return ADD_CONNECTION;
				case ITM_LABEL: return ADD_Label;
				case ITM_EDIT: return EDIT_Label;
				case ITM_DELETE: return DEL;
				case ITM_COPY: return COPY;
				case ITM_CUT: return CUT;
				case ITM_PASTE: return PASTE;
				case ITM_SIM_MODE: return SIM_MODE;
				case ITM_SAVE: return SAVE;
				case ITM_LOAD: return LOAD;
				case ITM_EXIT: return EXIT;
				}
			}
			else
			{
				if (UI.gatesGroup == 1)
				{
					switch (ClickedItemOrder)
					{
					case ITM_Buff: return ADD_Buff;
					case ITM_INV: return ADD_INV;
					case ITM_AND2: return ADD_AND_GATE_2;
					case ITM_OR2: return ADD_OR_GATE_2;
					case ITM_NAND2: return ADD_NAND_GATE_2;
					case ITM_NOR2: return ADD_NOR_GATE_2;
					case ITM_XOR2: return ADD_XOR_GATE_2;
					case ITM_XNOR2: return ADD_XNOR_GATE_2;
					case ITM_NEXT: return NEXT;
					}
				}
				else
				{
					switch (ClickedItemOrder + 9)
					{
					case ITM_PREVIOUS: return PREVIOUS;
					case ITM_AND3: return ADD_AND_GATE_3;
					case ITM_NOR3: return ADD_NOR_GATE_3;
					case ITM_XOR3: return ADD_XOR_GATE_3;
					}
				}
				switch (ClickedItemOrder + 4)
				{
				case ITM_Switch: return ADD_Switch;
				case ITM_LED: return ADD_LED;
				case ITM_CLOSE: return CLOSE_COMP_BAR;

				default: return DSN_TOOL;	//A click on empty place in desgin toolbar
				}
			}
		}
	
		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}
		
		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
		
			switch (ClickedItemOrder)
			{
			case ITM_SIM: return Change_Switch;
			case ITM_DSN_MODE: return DSN_MODE;
			case ITM_TRUTH: return Create_TruthTable;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_DELETE: return DEL;
			
			default: return SIM_TOOL;	//A click on empty place in Simulation toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;
	}

}


Input::~Input()
{
}
