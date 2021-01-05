#pragma once
#include "e:\mohamed engineering\programing project phase 2\3\logic_simulator_app\actions\action.h"
#include "..\Components\Component.h"
class DELETEE :
	public Action
{
	int CompoCount;
	Component* CompoList[];
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

