#pragma once
#include "action.h"
#include "..\Components\Component.h"
class DELETEE :
	public Action
{
private:
	Component* target;
	Connection** targetConnections;
public:
	DELETEE(ApplicationManager *pApp);
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();
	~DELETEE(void);
};

