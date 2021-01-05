#include "copyy.h"
#include "..\ApplicationManager.h"

copyy::copyy(ApplicationManager *pApp)
	: Action(pApp)
{
	
	
}
void copyy:: ReadActionParameters()
{
	if (pManager->GetSelected() != NULL)
		target1 = pManager->GetSelected();
	else
		target1 = NULL;
}
void copyy:: Execute()
{
	ReadActionParameters();

	if (target1 != NULL)
	{
		pManager->copycomp(target1->getactiontype());
		pManager->SetSelected(NULL);
	}
			
			
}
void copyy:: Undo(){}
void copyy:: Redo(){}

copyy::~copyy(void)
{
}
