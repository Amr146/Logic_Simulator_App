#pragma once
#include "action.h"
#include "..\Components\Component.h"
class copyy :
	public Action
{
private:
	Component * target1;
public:
	copyy(ApplicationManager *pApp);
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();
	~copyy(void);
};