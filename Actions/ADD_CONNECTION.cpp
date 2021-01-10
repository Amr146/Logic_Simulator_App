#include "ADD_CONNECTION.h"
#include "../ApplicationManager.h"

AddConnection::AddConnection(ApplicationManager *pApp):Action(pApp)
{
}

AddConnection::~AddConnection(void)
{
}

void AddConnection::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	raction=false;
	//Wait for User Input
	pOut->PrintMsg("Click on the source gate");
	pIn->GetPointClicked(x1, y1);
	if(!pManager->is_com(x1,y1,i,n_DstPin,true) )
		{
			pOut->ClearStatusBar();
			return ;
		}
	pOut->PrintMsg("Click on the Destination gate");
	pIn->GetPointClicked(x2, y2);
	if(x2<x1)
	{
		pOut->ClearStatusBar();
		return;
	}
	pOut->PrintMsg("Enter the InputPin's Number : ");
	string s;
	while (true)
	{
		s = pIn->GetSrting(pOut);
		if (isdigit(s[0]) != false)
		{
			n_DstPin = stoi(s);
			break;
		}
		else
		{
			pOut->PrintMsg("Please Enter a valid number for the Input");
			continue;
		}
	}
	if(!pManager->is_com(x2,y2,k,n_DstPin, false) )
	{
		pOut->ClearStatusBar();
		return ;
	}
	raction=true;



	//Clear Status Bar
	pOut->ClearStatusBar();
	
}
void AddConnection::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	
	//Calculate the rectangle Corners
	GraphicsInfo GInfo;

		
	if(raction)
	{
		GInfo.x1 = x1;
		GInfo.x2 = x2;
		GInfo.y1 = y1;
		GInfo.y2 = y2;


	
		Connection*pA = new Connection(GInfo,pManager->get_Component(i),pManager->get_Component(k),n_DstPin);
		pManager->AddComponent(pA);
		
	}
		
	
	raction=false;
}

void AddConnection::Undo()
{}

void AddConnection::Redo()
{}