#pragma once
#include "Action.h"
class Exit : public Action
{
public:
	Exit(ApplicationManager* pApp);
	virtual void ReadActionParameters();

	//Execute action
	virtual void Execute();

	//To undo this action
	virtual void Undo();

	//To redo this action
	virtual void Redo();
	~Exit();
};

