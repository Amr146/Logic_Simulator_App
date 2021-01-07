#include "Paste.h"
#include "..\ApplicationManager.h"

Paste::Paste(ApplicationManager* pApp):Action(pApp)
{
	target = NULL;
	ClipboardMode = Copy;
}
void Paste::ReadActionParameters()
{
	if (pManager->GetClipboard(ClipboardMode, ClipboardType) != NULL)
	{
		//Get a Pointer to the Clipboard 

		target = pManager->GetClipboard(ClipboardMode, ClipboardType);
	}
	else
		target = NULL;
}

//Execute action
void Paste::Execute()
{
	ReadActionParameters();

	if (target != NULL)
	{
		pManager->ExecuteAction(ClipboardType);
		pManager->ExecuteAction(SELECT);
	}
	else if (ClipboardMode == Cut)
		{
			pManager->ExecuteAction(ClipboardType);
		}
}

//To undo this action 
void Paste::Undo()
{

}

//To redo this action 
void Paste :: Redo()
{

}
Paste :: ~Paste()
{

}