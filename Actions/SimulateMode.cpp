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
	pOut->CreateSimulationToolBar();

	pManager->Simulate();
}
void SimulateMode :: Undo()
{
}
void SimulateMode :: Redo()
{
}