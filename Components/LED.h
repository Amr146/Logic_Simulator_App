#pragma once
#include "Component.h"
#include "InputPin.h"


class LED:public Component
{
	InputPin m_InputPin;

	Connection* connection;

public:
	LED(const GraphicsInfo &r_GfxInfo);
	virtual void Operate();	
	virtual void Draw(Output* pOut);	

	virtual int GetOutPinStatus();	
	virtual int GetInputPinStatus(int n);

	virtual void setInputPinStatus(int n, STATUS s);

	virtual bool fullconnected ();

	virtual bool is_comp(int&,int&,int&,bool);
	OutputPin* getSourcePin();
	InputPin* getDestPin(int);

	void AddConnection(Connection* con);
	void RemoveConnection(Connection* con, Pin*, bool IsInput);
	Connection** GetConnections(int& N);

	virtual ActionType getactiontype();
	virtual void Save(ofstream& saveFile); //writes the component information in the save file
	virtual void Load(string lbl, int id); //Loads the component information
};