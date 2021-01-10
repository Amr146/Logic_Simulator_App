#pragma once
#include "Action.h"
#include<string>
class Load : public Action
{
private:
	std::string fileName;
	int CompCount;
public:
	Load(ApplicationManager* pApp);
	virtual void ReadActionParameters();

	//Execute action
	virtual void Execute();

	//To undo this action
	virtual void Undo();

	//To redo this action
	virtual void Redo();

	~Load();
};

