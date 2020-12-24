#include "Previous.h"
#include "..\ApplicationManager.h"
Previous::Previous(ApplicationManager* pApp) :Action(pApp)
{
}
Previous :: ~Previous()
{
}
void Previous::ReadActionParameters()
{
}
void Previous::Execute()
{
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();
	//Switch to previous gates group
	UI.gatesGroup--;
	pOut->CreateDesignToolBar();
}
void Previous::Undo()
{}

void Previous::Redo()
{}