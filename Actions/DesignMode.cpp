#include "DesignMode.h"
#include "..\ApplicationManager.h"
DesignMode::DesignMode(ApplicationManager* pApp) : Action(pApp)
{
}
DesignMode :: ~DesignMode()
{
}
void DesignMode::ReadActionParameters()
{
}
void DesignMode::Execute()
{
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();
	//Switch to the simulation mode
	pOut->CreateDesignToolBar();
}
void DesignMode::Undo()
{
}
void DesignMode::Redo()
{
}