#include "OR2.h"


OR2::OR2(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void OR2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
	if (m_InputPins[0].getStatus()==HIGH || m_InputPins[1].getStatus()==HIGH)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);
}


// Function Draw
// Draws 2-input AND gate
void OR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawOR2(m_GfxInfo, IsSelected);
}

//returns status of outputpin
int OR2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int OR2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void OR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}
ActionType OR2:: getactiontype()
{
	return ADD_OR_GATE_2;
}


//writes the component information in the save file
void OR2::Save(ofstream& saveFile)
{
	saveFile << Type_OR2 << "\t" << getID() << "\t" << getLabel() << "\t" << m_GfxInfo.x1 << "\t" << m_GfxInfo.y1 << endl;
}

//Loads the component information
void OR2::Load(string lbl, int id)
{
	setLabel(lbl);
	setID(id);
}