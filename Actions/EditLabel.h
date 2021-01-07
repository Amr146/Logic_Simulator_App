#pragma once
#include "Action.h"
#include "..\Components\Component.h"

class EditLabel : public Action
{
private:
	Component* target;
	Output* pOut;
	Input* pIn;

public:
	EditLabel(ApplicationManager* pApp);	//constructor

	virtual void ReadActionParameters();

	//Execute action
	virtual void Execute();

	//To undo this action
	virtual void Undo();

	//To redo this action
	virtual void Redo();
};