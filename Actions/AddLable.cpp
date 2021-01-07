#include "AddLable.h"
#include "..\ApplicationManager.h"


AddLabel::AddLabel( ApplicationManager* pApp) : Action(pApp){
	target = NULL;
	pOut = pApp->GetOutput();
	pIn = pApp->GetInput();
}

void AddLabel::ReadActionParameters(){
	int x, y;
	pOut->ClearStatusBar();
	pOut->PrintMsg("Select The Component");

	pIn->GetPointClicked(x, y);
	
	target = pManager->GetClickedComponent(x, y);
}

//Execute action
void AddLabel::Execute()
{
	ReadActionParameters();
	if(target != NULL){
		pManager->SetSelected(target);
		target->SetIsSelected(true);
		pOut->ClearStatusBar();
		pOut->PrintMsg("Write The Label");
		string lbl = pIn->GetSrting(pOut);
		if(target->getLabel() == ""){
			target->setLabel(lbl);
		}else{
			pOut->ClearStatusBar();
			pOut->PrintMsg("This Component Already Have A Label, You Can Edit It");
		}
	}else{
		pOut->ClearStatusBar();
		pOut->PrintMsg("Select A Component");
		Execute();
	}
}

//To undo this action 
void AddLabel::Undo()
{

}

//To redo this action 
void AddLabel::Redo()
{

}

AddLabel::~AddLabel()
{

}