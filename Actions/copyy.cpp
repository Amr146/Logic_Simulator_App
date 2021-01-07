#include "copyy.h"
#include "..\ApplicationManager.h"
#include "../Components/Connection.h"

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

	if (target1 != NULL && target1 != dynamic_cast<Connection*>(target1)) //Check if the Selected component is supported by this operation
	{
		pManager->SetClipboard(target1, Copy, target1->getactiontype());
	}
			
			
}
void copyy:: Undo(){}
void copyy:: Redo(){}

copyy::~copyy(void)
{
}
