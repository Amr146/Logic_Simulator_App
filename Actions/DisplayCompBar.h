#pragma once
#include "Action.h"
class DisplayCompBar : public Action
{
public:
	DisplayCompBar(ApplicationManager* pApp);	//constructor

	virtual void ReadActionParameters();

	//Execute action
	virtual void Execute();

	//To undo this action
	virtual void Undo();

	//To redo this action
	virtual void Redo();
};

