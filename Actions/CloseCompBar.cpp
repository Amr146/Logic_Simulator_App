#include "CloseCompBar.h"
#include "../ApplicationManager.h"
CloseCompBar :: CloseCompBar(ApplicationManager* pApp) :Action(pApp) 	//constructor
{
}
void CloseCompBar :: ReadActionParameters()
{
}

//Execute action
void CloseCompBar::Execute()
{
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();
	//Closing the component bar
	UI.displayCompBar = false;
	pOut->CreateDesignToolBar();
}

//To undo this action
void CloseCompBar::Undo()
{
}

//To redo this action
void CloseCompBar::Redo()
{
}