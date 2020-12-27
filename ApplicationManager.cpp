#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions\AddBuff.h"
#include "Actions\AddORgate2.h"
#include "Actions\AddNOR2.h"
#include "Actions\AddNOR3.h"
#include "Actions\AddXOR2.h"
#include "Actions\AddXOR3.h"
#include "Actions\AddAND3.h"
#include "Actions\AddXNOR2.h"
#include "Actions\Next.h"
#include "Actions\Previous.h"
#include "Actions\SimulateMode.h"
#include "Actions\DesignMode.h"
#include "Actions\DisplayCompBar.h"
#include "Actions\CloseCompBar.h"
ApplicationManager::ApplicationManager()
{
	CompCount = 0;

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


		case ADD_CONNECTION:
			//TODO: Create AddConection Action here
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
		for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(OutputInterface);

}

////////////////////////////////////////////////////////////////////

void ApplicationManager::Simulate()
{
	for (int i = 0; i < CompCount; i++)
		CompList[i]->Operate();

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