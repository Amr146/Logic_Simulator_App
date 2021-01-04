#include "Select.h"
#include "..\ApplicationManager.h"

Select::Select(ApplicationManager* pApp): Action(pApp)
{
	target = NULL;
}
void Select::ReadActionParameters()
{
	if (pManager->GetSelected() == NULL)
	{
		//Get a Pointer to the Input
		Input* pIn = pManager->GetInput();

		//Wait for User Input
		pIn->GetCurrentPosition(x, y);

		target = pManager->GetClickedComponent(x, y);
	}
	else
		target = pManager->GetSelected();

}

//Execute action
void Select::Execute()
{
	ReadActionParameters();
	if(target != NULL)
	if (pManager->GetSelected() == NULL)
	{
		pManager->SetSelected(target);
		target->SetIsSelected(true);
	}
	else
	{
		pManager->SetSelected(NULL);
		target->SetIsSelected(false);
	}
}

//To undo this action 
void Select::Undo()
{

}

//To redo this action 
void Select::Redo()
{

}

Select :: ~Select()
{

}