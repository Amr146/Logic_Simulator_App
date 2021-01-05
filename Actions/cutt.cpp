#include "cutt.h"


#include "..\ApplicationManager.h"

cutt::cutt(ApplicationManager *pApp)
	: Action(pApp)
{
	
	
}
void cutt:: ReadActionParameters()
{
	if (pManager->GetSelected() != NULL)
		target1 = pManager->GetSelected();
	else
		target1 = NULL;
}
void cutt:: Execute()
{
	ReadActionParameters();

	if (target1 != NULL)
	{
		pManager->copycomp(target1->getactiontype());
		pManager->deletecomp(target1);
		//pManager->SetSelected(NULL);
	}
			
			
}
void cutt:: Undo(){}
void cutt:: Redo(){}

cutt::~cutt(void)
{
}