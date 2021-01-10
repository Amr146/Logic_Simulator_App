#include "Exit.h"
#include "../ApplicationManager.h"

Exit::Exit(ApplicationManager* pApp):Action(pApp)
{

}
void Exit::ReadActionParameters()
{

}

//Execute action
void Exit::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	std::string c;
	pOut->PrintMsg("Do you want to save the Current Circuit, please enter either 'y' or 'n'");
	c = pIn->GetSrting(pOut);
	while (true)
		if (c[0] == 'y')
		{
			pManager->ExecuteAction(SAVE);
			break;
		}
		else if (c[0] != 'n')
		{
			pOut->PrintMsg("Do you want to save the Current Circuit, please enter either 'y' or 'n'");
			continue;
		}
		else
			break;
}

//To undo this action
void Exit::Undo()
{

}

//To redo this action
void Exit::Redo()
{

}
Exit::~Exit()
{

}