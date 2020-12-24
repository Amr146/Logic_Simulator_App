#include "DisplayCompBar.h"
#include "../ApplicationManager.h"
DisplayCompBar :: DisplayCompBar(ApplicationManager* pApp)  :Action(pApp) 	//constructor
{
}
void DisplayCompBar::ReadActionParameters()
{
}

//Execute action
void DisplayCompBar::Execute()
{
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();
	//Displaying the component bar
	UI.displayCompBar = true;
	pOut->CreateDesignToolBar();
}

//To undo this action
void DisplayCompBar::Undo()
{
}

//To redo this action
void DisplayCompBar::Redo()
{
}