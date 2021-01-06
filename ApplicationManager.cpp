#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions\AddBuff.h"
#include "Actions\AddNOT.h"
#include "Actions\AddORgate2.h"
#include "Actions\AddNANDgate2.h"
#include "Actions\AddNOR2.h"
#include "Actions\AddNOR3.h"
#include "Actions\AddXOR2.h"
#include "Actions\AddXOR3.h"
#include "Actions\AddAND3.h"
#include "Actions\AddXNOR2.h"
#include "Actions\AddSwitch.h"
#include "Actions\AddLED.h"
#include "Actions\Next.h"
#include "Actions\Previous.h"
#include "Actions\Select.h"
#include "Actions\DELETEE.h"
#include "Actions\copyy.h"
#include "Actions\cutt.h"
#include "Actions\SimulateMode.h"
#include "Actions\DesignMode.h"
#include "Actions\DisplayCompBar.h"
#include "Actions\CloseCompBar.h"
#include "Actions\ADD_CONNECTION.h"
ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	Selected = NULL;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
////////////////////////////////////////////////////////////////////

Component* ApplicationManager::get_Component(int n)
{
	return CompList[n];
}

bool ApplicationManager::is_com(int &x, int &y ,int &k, int&pin , bool b)
{
	for(int i=0;i<CompCount;i++)
	{
		if( CompList[i]->is_comp(x,y,pin,b))
		{
			k=i;
			return true;
		}
	}

	return false;
}

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
		case ADD_AND_GATE_2:
			pAct= new AddANDgate2(this);
			break;

	    case ADD_OR_GATE_2:
			pAct= new AddORgate2(this);
			break;

		case ADD_Buff:
			pAct= new AddBuff(this);
			break;
		case ADD_INV:
			pAct= new AddNOT(this);
			break;

		case ADD_NAND_GATE_2:
			pAct= new AddNANDgate2(this);
			break;

		case ADD_NOR_GATE_2:
			pAct= new AddNOR2(this);
			break;

		case ADD_XOR_GATE_2:
			pAct= new AddXOR2(this);
			break;
		case ADD_XNOR_GATE_2:
			pAct= new AddXNOR2(this);
			break;

		case ADD_AND_GATE_3:
			pAct= new AddAND3(this);
			break;
		case ADD_NOR_GATE_3:
			pAct= new AddNOR3(this);
			break;
		case ADD_XOR_GATE_3:
			pAct= new AddXOR3(this);
			break;

		case ADD_Switch:
			pAct= new AddSwitch(this);
			break;

		case ADD_LED:
			pAct= new AddLED(this);
			break;


		case ADD_CONNECTION:
			pAct= new AddConnection(this);
			break;

		case COMP_BAR:
			pAct = new DisplayCompBar(this);
			break;

		case CLOSE_COMP_BAR:
			pAct = new CloseCompBar(this);
			break;

		case NEXT:
			pAct = new Next(this);
			break;
	
		case PREVIOUS:
			pAct = new Previous(this);
			break;

		case SELECT:
			pAct = new Select(this);
			break;
		case DEL:
			pAct = new DELETEE(this);
			break;
		case COPY:
			pAct = new copyy (this);
			break;
		case CUT:
			pAct = new cutt (this);
			break;

		case SIM_MODE:
			pAct = new SimulateMode(this);
			break;

		case DSN_MODE:
			pAct = new DesignMode(this);
			break;

		case EXIT:
			///TODO: create ExitAction here
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	OutputInterface->ClearDrawingArea();
	int min1=0;
	int min2=1000;
	int n;
		for(int i=0; i<CompCount; i++)
		{
			for(int k=0; k<CompCount; k++)
			{
				if(CompList[k]->get_graphicinfo().x1>min1 && CompList[k]->get_graphicinfo().x1<min2 )
				{
						min2=CompList[k]->get_graphicinfo().x1;
						n=k;
				}

			}
			for(int q=0; q<CompCount; q++)
			{
				if(CompList[q]->get_graphicinfo().x1==min2)
				{
					CompList[q]->Operate();
					
				}
			}
			min1=CompList[n]->get_graphicinfo().x1;
			min2=1000;

		}
		for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(OutputInterface);

}

////////////////////////////////////////////////////////////////////

Component* ApplicationManager::GetClickedComponent(int x, int y)
{
	for (int i = 0; i < CompCount; i++)
		if (CompList[i]->InsideMe(x, y))
			return CompList[i];
	return NULL;
}

////////////////////////////////////////////////////////////////////

void ApplicationManager::Simulate()
{
	for (int i = 0; i < CompCount; i++)
		CompList[i]->Operate();

}

////////////////////////////////////////////////////////////////////
void ApplicationManager::SetSelected(Component* sel)
{
	Selected = sel;
}

void ApplicationManager:: deletecomp(Component* target)
{
	for (int i=0; i<CompCount; i++)
	{
		if (CompList[i] == target)
		{
			CompList[i] = CompList[CompCount-1];
			CompList[CompCount - 1] = target;
			delete CompList[CompCount - 1];
			CompList[CompCount - 1] = NULL;
			
		    CompCount--;
			
			break;
		}
	}
}
void ApplicationManager:: copycomp(ActionType c)
{
	
				 ApplicationManager:: ExecuteAction(c);
				 
	
}
////////////////////////////////////////////////////////////////////
Component* ApplicationManager::GetSelected()
{
	return Selected;
}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}