#include "DELETEE.h"
#include "../ApplicationManager.h"
#include "../Components/Connection.h"

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
		if (target != dynamic_cast<Connection*>(target))
		{
			int N = 0;
			targetConnections = target->GetConnections(N);
			for (int i = 0; i < N; i++)
			{
				pManager->deletecomp(targetConnections[i--]);
				N--;
			}
		}
		pManager->deletecomp(target);
		pManager->SetSelected(NULL);
	}
}
void DELETEE:: Undo(){}
void DELETEE:: Redo(){}
DELETEE::~DELETEE(void)
{
}

