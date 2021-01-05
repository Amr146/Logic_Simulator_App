#include "Switch.h"

Switch::Switch(const GraphicsInfo &r_GfxInfo, int r_FanOut):Component(r_GfxInfo),m_OutputPin(r_FanOut)
{
	m_OutputPin.setStatus(HIGH);
}

void Switch::Operate()
{
}

void Switch::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawSWITCH(m_GfxInfo);
	
	
}
int Switch::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}

int Switch::GetInputPinStatus(int n)	
{
	return -1;
}

void Switch::setInputPinStatus(int n, STATUS s)
{
}

bool Switch::is_comp(int &x, int &y,int&n,bool b)
{
	if(m_GfxInfo.x1<x && m_GfxInfo.x2>x && m_GfxInfo.y1<y && m_GfxInfo.y2>y)
		{
			if(b==true)
			{
				if(m_OutputPin.can_connected())
				{
					x=m_GfxInfo.x2;
					y=m_GfxInfo.y1+24;
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

OutputPin* Switch::getSourcePin()
{
	return &m_OutputPin;
}

InputPin* Switch::getDestPin(int)
{
	return NULL;
}

ActionType Switch::getactiontype()
{
	return ADD_Switch;
}

