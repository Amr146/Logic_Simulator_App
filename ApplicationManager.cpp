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
#include "Actions\Paste.h"
#include "Actions\SimulateMode.h"
#include "Actions\DesignMode.h"
#include "Actions\DisplayCompBar.h"
#include "Actions\CloseCompBar.h"
#include "Actions\ADD_CONNECTION.h"
#include "Actions\AddLable.h"
#include "Actions\EditLabel.h"
#include "Actions\Simulation.h"
#include "Actions\Save.h"
#include "Actions\Load.h"
#include "Actions\Exit.h"

ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	ConnectionCount = 0;
	LastID = 0;
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
	if (pComp == dynamic_cast<Connection*>(pComp))
		ConnectionCount++;
	else
	{
		if (pComp->getID() != 0)
			LastID = pComp->getID();
		else
			pComp->setID(++LastID);
	}
}
////////////////////////////////////////////////////////////////////

Component* ApplicationManager::get_Component(int n)
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->getID() == n)
			return CompList[i];
	}
	return NULL;
}

bool ApplicationManager::is_com(int &x, int &y ,int &k, int&pin , bool b)
{
	for(int i=0;i<CompCount;i++)
	{
		if( CompList[i]->is_comp(x,y,pin,b))
		{
			k= CompList[i]->getID();
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

		case ADD_Label:
			pAct= new AddLabel(this);
			break;

		case EDIT_Label:
			pAct= new EditLabel(this);
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
		case PASTE:
			pAct = new Paste(this);
			break;

		case SIM_MODE:
			pAct = new SimulateMode(this);
			break;

		case SAVE:
			pAct = new Save(this);
			break;

		case LOAD:
			pAct = new Load(this);
			break;
				
		case Change_Switch:
			pAct = new Simulation(this);
			break;

		case DSN_MODE:
			pAct = new DesignMode(this);
			break;

		case EXIT:
			pAct = new Exit(this);
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
	
		for(int i=0; i<CompCount; i++){
			CompList[i]->Draw(OutputInterface);
			if(CompList[i]->getLabel() != ""){
				GraphicsInfo GfxInfo = CompList[i]->get_graphicinfo();
				if(dynamic_cast<Connection*>(CompList[i]) != NULL){
					GfxInfo.x1 = CompList[i]->get_graphicinfo().x1+ 7 + (CompList[i]->get_graphicinfo().x2 - CompList[i]->get_graphicinfo().x1)/4;
					GfxInfo.y1 = CompList[i]->get_graphicinfo().y2 - 10;
				}else{
					GfxInfo.y1 -= UI.AND2_Height/2;
				}
				GetOutput()->PrintLabel(GfxInfo, CompList[i]->getLabel());
			}
		}
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

}

///////////////////////////////////////////////////////////////////

bool ApplicationManager::fullyconnected()
{
	for (int i=0; i<CompCount ;i++)
	{
		if(!CompList[i]->fullconnected())
			return false;
	}

	return true;
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
			if (target == dynamic_cast<Connection*>(target))
				ConnectionCount--;
			CompList[i] = CompList[CompCount-1];
			CompList[CompCount - 1] = target;
			delete CompList[CompCount - 1];
			CompList[CompCount - 1] = NULL;
			
		    CompCount--;

			break;
		}
	}
}
////////////////////////////////////////////////////////////////////
void ApplicationManager :: deleteAll()
{
	for (int i = 0; i < CompCount; i++)
	{
		SetSelected(CompList[i]);
		ExecuteAction(DEL);
		i--;
	}
	LastID = 0;
}
////////////////////////////////////////////////////////////////////
Component* ApplicationManager::GetSelected()
{
	return Selected;
}
/////////////////////////////////////////////////////////////////////
void ApplicationManager :: SetClipboard(Component* target, Mode m, ActionType AT)
{
	if(m == Copy)
		Clipboard = target;
	ClipboardMode = m;
	ClipboardType = AT;
}
////////////////////////////////////////////////////////////////////
Component* ApplicationManager :: GetClipboard(Mode &m, ActionType &AT)
{
	AT = ClipboardType;
	m = ClipboardMode;
	return Clipboard;
}
////////////////////////////////////////////////////////////////////
int ApplicationManager :: CompCountWithoutConn()
{
	return (CompCount - ConnectionCount);
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
void ApplicationManager::SaveAll(ofstream& saveFile)
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i] != dynamic_cast<Connection*>(CompList[i]))
		{
			CompList[i]->Save(saveFile);
		}
	}
	saveFile << "Connections" <<endl;
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i] == dynamic_cast<Connection*>(CompList[i]))
		{
			CompList[i]->Save(saveFile);
		}
	}
	saveFile << "-1" << endl;
}
////////////////////////////////////////////////////////////////////


ApplicationManager::~ApplicationManager()
{
	deleteAll();
	delete OutputInterface;
	delete InputInterface;
	
}