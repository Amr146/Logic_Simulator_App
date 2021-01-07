#pragma once
#include "Action.h"
#include "../Components/Switch.h"
#include "../Components/Component.h"



class Simulation : public Action
{
private:
	int x;
	int y;
	Component* target;
public:
	Simulation(ApplicationManager* pApp);
	virtual ~Simulation();
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};
