#include "cutt.h"
#include "../Components/Connection.h"

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

	if (target1 != NULL && target1 != dynamic_cast<Connection*>(target1)) //Check if the Selected component is supported by this operation
	{
		pManager->SetClipboard(target1, Cut, target1->getactiontype());
		pManager->ExecuteAction(DEL);
		pManager->SetSelected(NULL);
	}
			
			
}
void cutt:: Undo(){}
void cutt:: Redo(){}

cutt::~cutt(void)
{
}