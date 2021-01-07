#ifndef _GATE_H
#define _GATE_H

/*
  Class Gate
  -----------
  - Base class for all types of gates
  - Each gate has n inputs pins and one output pin
*/


#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"

class Gate:public Component
{
protected:
	InputPin* m_InputPins;	//Array of input pins of the Gate
	OutputPin m_OutputPin;	//The Gate output pin
	int m_Inputs;		//No. of input pins of that Gate.

	int InputCount;

	Connection** ConnectionsList;
	int ConnectionsCount;
	
	
public:
	Gate(int r_Inputs, int r_FanOut);
	virtual bool is_comp(int&,int&,int&,bool);
	OutputPin* getSourcePin();
	InputPin* getDestPin(int);
	void AddConnection(Connection* con);
	void RemoveConnection(Connection* con, Pin*, bool IsInput);
	virtual Connection** GetConnections(int &N);
	~Gate();

};

#endif
