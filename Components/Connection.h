#pragma once
#include "component.h"
#include "InputPin.h"
#include "OutputPin.h"

class Connection :	public Component
{
	const int SelectBoxSize;
	Component*	SrcCmpnt;	//Connection source component
	Component*	DstCmpnt;	//Connection Destination component
	int		n_DstPin;		//The Input pin to which this connection is linked
	OutputPin* SrcPin;	//The Source pin of this connection (an output pin of certain Component)
	InputPin* DstPin;	//The Destination pin of this connection (an input pin of certain Component)
public:
	Connection(const GraphicsInfo &r_GfxInfo,  Component *pS=NULL,Component *pD=NULL, int Pin=0 );
	//Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin);

	virtual void Operate() ;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut);	//for each component to Draw itself

	void setSourcePin(OutputPin *pSrcPin);
	void setDestPin(InputPin *pDstPin);
	OutputPin* getSourcePin();
	InputPin* getDestPin(int n = 1);

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	virtual bool is_comp(int&,int&,int&,bool);

	virtual bool InsideMe(int x, int y);

	virtual ActionType getactiontype();

	virtual bool fullconnected ();

	void setSrcComp(Component*	Src);
	void setDestComp(Component*	Dest);

	Component*	GetSrcCmpnt();
	Component*	GetDstCmpnt();

	GraphicsInfo* getGfxInfo();

	virtual void Save(ofstream& saveFile); //writes the component information in the save file
	virtual void Load(string lbl, int id); //Loads the component information
	~Connection();
};
