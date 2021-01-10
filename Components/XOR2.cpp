#include "XOR2.h"


#include <iostream>
using namespace std;
XOR2::XOR2(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void XOR2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	if (m_InputPins[0].getStatus()==LOW && m_InputPins[1].getStatus()==LOW)
		m_OutputPin.setStatus(LOW);
	else if (m_InputPins[0].getStatus()==LOW && m_InputPins[1].getStatus()==HIGH)
		m_OutputPin.setStatus(HIGH);
	else if (m_InputPins[0].getStatus()==HIGH && m_InputPins[1].getStatus()==LOW)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);
	
}


// Function Draw
// Draws 2-input AND gate
void XOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXOR2(m_GfxInfo, IsSelected);
}

//returns status of outputpin
int XOR2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}
ActionType XOR2:: getactiontype()
{
	return ADD_XOR_GATE_2;
}

//writes the component information in the save file
void XOR2::Save(ofstream& saveFile)
{
	saveFile << Type_XOR2 << "\t" << getID() << "\t" << getLabel() << "\t" << m_GfxInfo.x1 << "\t" << m_GfxInfo.y1 << endl;
}

//Loads the component information
void XOR2::Load(string lbl, int id)
{
	setLabel(lbl);
	setID(id);
}