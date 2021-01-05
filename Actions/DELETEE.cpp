#include "DELETEE.h"
#include "../ApplicationManager.h"

DELETEE::DELETEE(ApplicationManager *pApp)//,Component** complist,int  compcount)
	: Action(pApp)
{
	
}
void DELETEE:: ReadActionParameters(){}
void DELETEE:: Execute()
{

			pManager->deletecomp();
			
}
void DELETEE:: Undo(){}
void DELETEE:: Redo(){}
DELETEE::~DELETEE(void)
{
}

