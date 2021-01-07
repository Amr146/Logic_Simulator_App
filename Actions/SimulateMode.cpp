#include "SimulateMode.h"
#include "..\ApplicationManager.h"
SimulateMode::SimulateMode(ApplicationManager* pApp) : Action(pApp)
{
}
SimulateMode :: ~SimulateMode()
{
}
void SimulateMode :: ReadActionParameters()
{
}
void SimulateMode :: Execute()
{
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();
	//Switch to the simulation mode
	
	if(pManager->fullyconnected())
	{
		pOut->CreateSimulationToolBar();
		pManager->Simulate();
	}
	else
	{
		pOut->PrintMsg("The circuit is NOT fully or correctly connected");
	}
}

void SimulateMode :: Undo()
{
}
void SimulateMode :: Redo()
{
}