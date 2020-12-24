#include "Next.h"
#include "..\ApplicationManager.h"
Next :: Next(ApplicationManager* pApp) :Action(pApp)
{
}
Next :: ~Next()
{
}
void Next :: ReadActionParameters()
{
}
void Next :: Execute()
{
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();
	//Switch to the next gates group
	UI.gatesGroup++;
	pOut->CreateDesignToolBar();
}
void Next::Undo()
{}

void Next::Redo()
{}