#pragma once
#include "Action.h"
class DesignMode : public Action
{
public:
	DesignMode(ApplicationManager* pApp);
	virtual ~DesignMode();
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};

