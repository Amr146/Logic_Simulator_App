#include "Save.h"
#include "../ApplicationManager.h"
#include<fstream>
#include<direct.h>
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
}

//Execute action
void Save::Execute()
{
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();

	ReadActionParameters(); //Reading the parameters for the action 
	ofstream Savefile("Save\\" + fileName + ".txt"); //creating or overwritting the save file
	if (Savefile.is_open()) //check if the savefile was created successfully 
	{
		pManager->SaveAll(Savefile); //calling the saving function in application manager
		Savefile.close(); //closing the savefile
		pOut->PrintMsg("Save Completed");
	}
	else
	{
		if (mkdir("Save") == 0) //create the Save Directory and check if created successfully
		{
			ofstream Savefile("Save\\" + fileName + ".txt"); //creating the save file
			pManager->SaveAll(Savefile); //calling the saving function in application manager
			Savefile.close(); //closing the savefile
			pOut->PrintMsg("Save Completed");
		}
		else
			pOut->PrintMsg("Save Faild");
	}
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