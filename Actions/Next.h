#pragma once
#include "Action.h"
class Next : public Action
{
public:
	Next(ApplicationManager* pApp);
	virtual ~Next();
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};

