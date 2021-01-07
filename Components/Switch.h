#pragma once
#include "Component.h"
#include "OutputPin.h"


class Switch:public Component
{
	OutputPin m_OutputPin;

	Connection** ConnectionsList;
	int ConnectionsCount;
public:
	Switch(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	virtual void Operate();	
	virtual void Draw(Output* pOut);	

	virtual int GetOutPinStatus();	
	virtual int GetInputPinStatus(int n);

	virtual void setInputPinStatus(int n, STATUS s);

	virtual bool is_comp(int&,int&,int&,bool);
	OutputPin* getSourcePin();
	InputPin* getDestPin(int);

	void AddConnection(Connection* con);
	void RemoveConnection(Connection* con, Pin*, bool IsInput);
	virtual Connection** GetConnections(int& N);

	virtual ActionType getactiontype();
	~Switch();
};