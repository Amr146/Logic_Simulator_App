#pragma once
#include "Action.h"
#include "..\Components\Component.h"
class Paste : public Action
{
private:
	Component* target;
	Mode ClipboardMode;
	ActionType ClipboardType;
public:
	Paste(ApplicationManager* pApp);
	virtual void ReadActionParameters();

	//Execute action 
	virtual void Execute();

	//To undo this action 
	virtual void Undo();

	//To redo this action 
	virtual void Redo();
	~Paste();
};

