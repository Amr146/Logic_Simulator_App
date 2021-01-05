#include "DELETEE.h"
#include "../ApplicationManager.h"

DELETEE::DELETEE(ApplicationManager *pApp)
	: Action(pApp)
{
	
}
void DELETEE:: ReadActionParameters()
{
	if (pManager->GetSelected() != NULL)
		target = pManager->GetSelected();
	else
		target = NULL;
}
void DELETEE:: Execute()
{
	ReadActionParameters();

	if (target != NULL)
	{
		pManager->deletecomp(target);
		pManager->SetSelected(NULL);
	}
}
void DELETEE:: Undo(){}
void DELETEE:: Redo(){}
DELETEE::~DELETEE(void)
{
}

