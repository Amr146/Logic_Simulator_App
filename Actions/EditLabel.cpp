#include "EditLabel.h"
#include "../ApplicationManager.h"
#include "../Components/Connection.h"
EditLabel::EditLabel(ApplicationManager* pApp) :Action(pApp) 	//constructor
{
	target = NULL;
	pOut = pApp->GetOutput();
	pIn = pApp->GetInput();
}
void EditLabel::ReadActionParameters()
{
	int x, y;		//	Coordinates Of User Clicked Point
	pOut->ClearStatusBar();
	pOut->PrintMsg("Select The Component");

	pIn->GetPointClicked(x, y);
	
	target = pManager->GetClickedComponent(x, y);		//	The Component That User Wants To Edit
}

//Execute action
void EditLabel::Execute()
{
	ReadActionParameters();

	if(target != NULL){					//	The User Clicked A Component
		pManager->SetSelected(target);	//	Mark This Component As Selected
		target->SetIsSelected(true);
		
		if(target->getLabel() != ""){	//	This Component Already Has A Label
			
			pOut->ClearStatusBar();
			pOut->PrintMsg("Write The Label");
			string lbl = pIn->GetSrting(pOut);	//	Get The Label From The User
			target->setLabel(lbl);				//	Set The Label

		}else{							//	This Component Does Not Have A Label To Edit
			pOut->ClearStatusBar();
			pOut->PrintMsg("This Component Doesn\'t Have A Label To Edit, You Can Add Label To It");
		}
	}else{								//	The User Clicked An Empty Area
		pOut->ClearStatusBar();
		pOut->PrintMsg("Select A Component");
		Execute();								//	Execute This Action Again Until The User Clicks A Component
	}

	//	Edit The DestPin & SrcPin If The Component Is A Connection
	if(dynamic_cast<Connection*>(target) != NULL){
		int x, y, i, k, n_DstPin;
		STATUS s;
		Connection* Conn = dynamic_cast<Connection*>(target);	//	The Connection That The User Clicked
		GraphicsInfo *GfxInfo = Conn->getGfxInfo();				//	The Info Of The Connection
		
		//	Edit The SrcPin
		pOut->ClearStatusBar();
		pOut->PrintMsg("To Edit The Source Pin Of This Connection Select A Component");

		pIn->GetPointClicked(x, y);
		target = pManager->GetClickedComponent(x, y);			//	The New Src. Component
		
		if(!pManager->is_com(x,y,i,n_DstPin,true))
		{
			pOut->ClearStatusBar();
			target = Conn->GetSrcCmpnt();
			s = (STATUS)target->GetOutPinStatus();
		}else{
			s = (STATUS)target->GetOutPinStatus();
			GfxInfo->x1 = x;				//	The X Coord. Of The New SrcPin
			GfxInfo->y1 = y;				//	The Y Coord. Of The New SrcPin
			OutputPin* srcPin = target->getSourcePin();
			Conn->setSourcePin(srcPin);
			Conn->setSrcComp(target);
			srcPin->setStatus(s);
		}

		//	Edit The DestPin
		pOut->ClearStatusBar();
		pOut->PrintMsg("To Edit The Destenation Pin Of This Connection Select A Component");

		pIn->GetPointClicked(x, y);
		target = pManager->GetClickedComponent(x, y);			//	The New Dst. Component

		if(!pManager->is_com(x,y,k,n_DstPin, false) )
		{
			pOut->ClearStatusBar();
		}else{
			GfxInfo->x2 = x;				//	The X Coord. Of The New DstPin
			GfxInfo->y2 = y;				//	The Y Coord. Of The New DstPin
			
			//	Removing The Connection Connected To The Old DstPin
			Conn->getDestPin()->setStatus(LOW);		//<<<<
			Conn->getDestPin()->set_isc(false);			//	Removing The Connection Connected To The Old DstPin
			Conn->setDestPin(NULL);					//<<<<
			
			InputPin* DstPin = target->getDestPin(n_DstPin);
			Conn->setDestPin(DstPin);
			Conn->setDestComp(target);
			DstPin->setStatus(s);
		}
	}
}

//To undo this action
void EditLabel::Undo()
{
}

//To redo this action
void EditLabel::Redo()
{
}