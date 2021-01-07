#include "LED.h"
LED::LED(const GraphicsInfo& r_GfxInfo):Component(r_GfxInfo)
{
	m_InputPin.setComponent(this);
}

void LED::Operate()
{

}

void LED::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if(m_InputPin.getStatus()==HIGH)
		pOut->DrawLEDon(m_GfxInfo, IsSelected);
	else 
		pOut->DrawLEDoff(m_GfxInfo, IsSelected);
	
	
}
int LED::GetOutPinStatus()	
{
	return -1;
}

int LED::GetInputPinStatus(int n=1)	
{
	return m_InputPin.getStatus();
}

void LED::setInputPinStatus(int n, STATUS s)
{
	IsSelected = false;
	m_InputPin.setStatus(s);
}

bool LED::is_comp(int &x, int &y,int&n,bool b)
{
	if(m_GfxInfo.x1<x && m_GfxInfo.x2>x && m_GfxInfo.y1<y && m_GfxInfo.y2>y)
		{
			if(b==false)
			{
				if(!m_InputPin.get_isC())
				{
					x=m_GfxInfo.x1;
					y=m_GfxInfo.y1+48;
					m_InputPin.set_isc(true);
					n=1;
					return true;
				}
				else
					return false;
			}
			else 
				return false;
		}
	else
		return false;
}

OutputPin* LED::getSourcePin()
{
	return NULL;
}

InputPin* LED::getDestPin(int)
{
	return &m_InputPin;
}

ActionType LED::getactiontype()
{
	return ADD_LED;
}