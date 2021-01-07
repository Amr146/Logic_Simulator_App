#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"
#include "InputPin.h"
#include "OutputPin.h"

//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	string m_Label;
protected:
	Output* pout;
	bool IsSelected;
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
public:
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	
	virtual bool InsideMe(int x, int y);

	virtual void AddConnection(Connection* con);
	virtual void RemoveConnection(Connection* con, Pin*, bool IsInput);

	virtual Connection** GetConnections(int &N);
	
	void SetIsSelected(bool q);
	bool getisselected();
	virtual ActionType getactiontype()=0;
	
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.

	virtual bool is_comp(int&,int&,int&, bool)=0;

	GraphicsInfo get_graphicinfo();

	virtual OutputPin* getSourcePin()=0;
	virtual InputPin* getDestPin(int i=0)=0;


	Component();	
	
	//Destructor must be virtual
	virtual ~Component();
};

#endif
