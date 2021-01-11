#pragma once
#include "Action.h"
#include<string>
class Save : public Action
{
private:
	std :: string fileName;
public:
	Save(ApplicationManager* pApp);
	virtual void ReadActionParameters();

	//Execute action
	virtual void Execute();

	//To undo this action
	virtual void Undo();

	//To redo this action
	virtual void Redo();

	~Save();
};

