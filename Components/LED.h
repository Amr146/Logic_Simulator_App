#pragma once
#include "Component.h"
#include "InputPin.h"


class LED:public Component
{
	InputPin m_InputPin;
public:
	LED(const GraphicsInfo &r_GfxInfo);
	virtual void Operate();	
	virtual void Draw(Output* pOut);	

	virtual int GetOutPinStatus();	
	virtual int GetInputPinStatus(int n);

	virtual void setInputPinStatus(int n, STATUS s);

	virtual bool is_comp(int&,int&,int&,bool);
	OutputPin* getSourcePin();
	InputPin* getDestPin(int);

	virtual ActionType getactiontype();

};