#pragma once
#include "Action.h"

class SimulateMode : public Action
{
public:
	SimulateMode(ApplicationManager* pApp);
	virtual ~SimulateMode();
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};

