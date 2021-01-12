#include "Load.h"
#include "../ApplicationManager.h"
#include "..\Components\AND2.h"
#include "..\Components\AND3.h"
#include "..\Components\Buff.h"
#include "..\Components\Connection.h"
#include "..\Components\LED.h"
#include "..\Components\NAND2.h"
#include "..\Components\NOR2.h"
#include "..\Components\NOR3.h"
#include "..\Components\NOT.h"
#include "..\Components\OR2.h"
#include "..\Components\Switch.h"
#include "..\Components\XNOR2.h"
#include "..\Components\XOR2.h"
#include "..\Components\XOR3.h"
#include<fstream>

Load::Load(ApplicationManager* pApp) :Action(pApp)
{

}
void Load::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Please Write the name of the circuit to Load");

	//Wait for User Input
	fileName = pIn->GetSrting(pOut);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

//Execute action
void Load::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ReadActionParameters();

	//open the file
	ifstream Savefile("Save\\" + fileName + ".txt");

	//Check if the file was open or not
	if (Savefile.is_open())
	{
		if (pManager->CompCountWithoutConn() != 0)
		{
			std::string c;
			pOut->PrintMsg("Do you want to save the Current Circuit, please enter either 'y' or 'n'");
			while (true)
			{
				c = pIn->GetSrting(pOut); //Get user input 
				//check user input
				if (c[0] == 'y')
				{
					pManager->ExecuteAction(SAVE);  //Save the current circuit
					break;
				}
				else if (c[0] != 'n') // if neither y nor n
				{
					pOut->PrintMsg("Do you want to save the Current Circuit, please enter either 'y' or 'n'");
					continue; //continue until the user enter either y or n
				}
				else // if input is n
					break; //don't save
			}
			pManager->deleteAll(); //delete the current circuit 
		}
		GraphicsInfo GInfo;
		int CT;
		std::string CompLabel;
		int ID;
		Component* pA = NULL;
		string temp;
		std::string X1;
		std::string Y1;

		Savefile >> CompCount; //get the number of components in the save file

		for (int i = 0; i < CompCount; i++)
		{
			GInfo.x1 = GInfo.y1 = 0;
			X1 = Y1 = CompLabel = "";
			//Read the information of the components
			Savefile >> CT >> ID;
			std::getline(Savefile, temp);

			//this part for handling the case in which the saved component didn't have a label
			//and also handling labels with spaces

			bool flag1 = false;
			bool flag2 = false;
			for (int i = 1; i < temp.length(); i++)
			{
				if (flag2) 
					Y1.push_back(temp[i]);
				else if (temp[i] != '\t' && !flag1)
					CompLabel.push_back(temp[i]);
				else if (temp[i] != '\t')
					X1.push_back(temp[i]);
				else if (flag1)
					flag2 = true;
				else
					flag1 = true;
			}

			GInfo.x1 = stoi(X1);
			if(Y1.length() !=0)
				GInfo.y1 = stoi(Y1);

			if (GInfo.y1 == 0)
			{
				GInfo.y1 = GInfo.x1;
				GInfo.x1 = stoi(CompLabel);
				CompLabel = "";
			}

			//optimizing the graphical info
			GInfo.x2 = GInfo.x1 + UI.AND2_Width;
			GInfo.y2 = GInfo.y1 + UI.AND2_Height;

			switch (CT) //switch case to check for the component type
			{
			case Type_AND2:
				pA = new AND2(GInfo, AND2_FANOUT);
				pA->Load(CompLabel, ID);
				pManager->AddComponent(pA);
				break;

			case Type_AND3:
				pA = new AND3(GInfo, AND2_FANOUT);
				pA->Load(CompLabel, ID);
				pManager->AddComponent(pA);
				break;

			case Type_Buff:
				pA = new Buff(GInfo, AND2_FANOUT);
				pA->Load(CompLabel, ID);
				pManager->AddComponent(pA);
				break;

			case Type_LED:
				pA = new LED(GInfo);
				pA->Load(CompLabel, ID);
				pManager->AddComponent(pA);
				break;

			case Type_NAND2:
				pA = new NAND2(GInfo, AND2_FANOUT);
				pA->Load(CompLabel, ID);
				pManager->AddComponent(pA);
				break;

			case Type_NOR2:
				pA = new NOR2(GInfo, AND2_FANOUT);
				pA->Load(CompLabel, ID);
				pManager->AddComponent(pA);
				break;

			case Type_NOR3:
				pA = new NOR3(GInfo, AND2_FANOUT);
				pA->Load(CompLabel, ID);
				pManager->AddComponent(pA);
				break;

			case Type_INV:
				pA = new NOT(GInfo, AND2_FANOUT);
				pA->Load(CompLabel, ID);
				pManager->AddComponent(pA);
				break;

			case Type_OR2:
				pA = new OR2(GInfo, AND2_FANOUT);
				pA->Load(CompLabel, ID);
				pManager->AddComponent(pA);
				break;

			case Type_Switch:
				pA = new Switch(GInfo, AND2_FANOUT);
				pA->Load(CompLabel, ID);
				pManager->AddComponent(pA);
				break;

			case Type_XNOR2:
				pA = new XNOR2(GInfo, AND2_FANOUT);
				pA->Load(CompLabel, ID);
				pManager->AddComponent(pA);
				break;

			case Type_XOR2:
				pA = new XOR2(GInfo, AND2_FANOUT);
				pA->Load(CompLabel, ID);
				pManager->AddComponent(pA);
				break;

			case Type_XOR3:
				pA = new XOR3(GInfo, AND2_FANOUT);
				pA->Load(CompLabel, ID);
				pManager->AddComponent(pA);
				break;

			default:
				break;
			}
		}
		Savefile >> CompLabel;    //To Skip the Line which includes "Connections"


		int SrcID;
		int DestID;
		int pin;
		Component* Src;
		Component* Dest;

		while (!Savefile.eof())
		{
			//Read the information of the connections
			Savefile >> SrcID >> DestID >> pin;
			if (SrcID == -1) //check if the end of the savefile have been reached
				break;
			Src = pManager->get_Component(SrcID);  //pointer to the Source component
			Dest = pManager->get_Component(DestID);  //poiter to the Destination component
			 
			//getting the graphical info
			GInfo.x1 = Src->get_graphicinfo().x1;
			GInfo.y1 = Src->get_graphicinfo().y1;
			GInfo.x2 = Dest->get_graphicinfo().x1;
			GInfo.y2 = Dest->get_graphicinfo().y1;

			//optimizing the graphical info
			Src->is_comp(GInfo.x1 ,GInfo.y1, pin, true);
			Dest->is_comp(GInfo.x2, GInfo.y2, pin, false);
			pA = new Connection(GInfo, Src, Dest, pin);
			pManager->AddComponent(pA);
		}
		Savefile.close(); //closing the savefile
		pOut->PrintMsg("Load Completed");
	}
	else
		pOut->PrintMsg("file not found");

}

//To undo this action
void Load::Undo()
{

}

//To redo this action
void Load::Redo()
{

}

Load :: ~Load()
{

}