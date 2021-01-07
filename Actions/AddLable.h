#pragma once
#include "Action.h"
#include "..\Components\Component.h"

class AddLabel : public Action{

private:
	Component* target;
	Output* pOut;
	Input* pIn;
public:
	AddLabel(ApplicationManager* pApp);

	~AddLabel();

	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();
};