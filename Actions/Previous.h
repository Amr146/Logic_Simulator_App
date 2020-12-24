#pragma once
#include "Action.h"
class Previous : public Action
{
public:
	Previous(ApplicationManager* pApp);
	virtual ~Previous();
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};

