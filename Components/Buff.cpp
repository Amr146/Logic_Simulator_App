#include "Buff.h"


Buff::Buff(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void Buff::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
	if (m_InputPins[0].getStatus()==HIGH )
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);
}


// Function Draw
// Draws 2-input AND gate
void Buff::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawBUFFER(m_GfxInfo, IsSelected);
}

//returns status of outputpin
int Buff::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int Buff::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void Buff::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}
ActionType Buff:: getactiontype()
{
	return ADD_Buff;
}

//writes the component information in the save file
void Buff::Save(ofstream& saveFile)
{
	saveFile << Type_Buff << "\t" << getID() << "\t" << getLabel() << "\t" << m_GfxInfo.x1 << "\t" << m_GfxInfo.y1 << endl;
}

//Loads the component information
void Buff::Load(string lbl, int id)
{
	setLabel(lbl);
	setID(id);
}