#pragma once
#include "Action.h"
#include "Component.h"
class Select : public Action
{
private:
	int x, y;
	Component* target;
public:
	Select(ApplicationManager* pApp);
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();

	~Select();
};

