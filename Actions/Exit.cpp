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
	while (true)
	{
		c = pIn->GetSrting(pOut); //Get user input 
		//check user input
		if (c[0] == 'y')
		{
			pManager->ExecuteAction(SAVE); //Save the current circuit
			break;
		}
		else if (c[0] != 'n') // if neither y nor n
		{
			pOut->PrintMsg("Do you want to save the Current Circuit, please enter either 'y' or 'n'");
			continue; //continue until the user enter either y or n
		}
		else // if input is n
			break; //don't save
	}
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