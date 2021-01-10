#include "Save.h"
#include "../ApplicationManager.h"
#include<fstream>
Save::Save(ApplicationManager* pApp) :Action(pApp)
{

}
void Save::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Please Write the name of the circuit to Save");

	//Wait for User Input
	fileName = pIn->GetSrting(pOut);
	//Clear Status Bar
	pOut->ClearStatusBar();

	CompCount =pManager->CompCountWithoutConn();
}

//Execute action
void Save::Execute()
{
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();
	ofstream Savefile("Save\\" + fileName + ".txt");
	Savefile << CompCount << endl;
	pManager->SaveAll (Savefile);
	Savefile.close();
	pOut->PrintMsg("Save Completed");
}

//To undo this action
void Save::Undo()
{

}

//To redo this action
void Save::Redo()
{

}

Save :: ~Save()
{

}