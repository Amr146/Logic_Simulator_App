#include "Simulation.h"
#include "..\ApplicationManager.h"


Simulation::Simulation(ApplicationManager* pApp) : Action(pApp)
{
}
Simulation :: ~Simulation()
{
}
void Simulation :: ReadActionParameters()
{
	
	//Get a Pointer to the Input
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	//Wait for User Input
	pOut->PrintMsg("Select the Switch to change its status");
	pIn->GetPointClicked(x, y);

	target = pManager->GetClickedComponent(x, y);

	pOut->ClearStatusBar();
	

}
void Simulation :: Execute()
{

	ReadActionParameters();
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();
	if(target!=NULL && dynamic_cast<Switch*>(target))
		target->change_status();
	
	pManager->Simulate();
	
}

void Simulation :: Undo()
{
}
void Simulation :: Redo()
{
}