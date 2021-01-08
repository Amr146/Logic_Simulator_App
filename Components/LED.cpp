#include "LED.h"
LED::LED(const GraphicsInfo& r_GfxInfo):Component(r_GfxInfo)
{
	m_InputPin.setComponent(this);
	IsSelected = false;
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
	if(InsideMe(x,y))
		{
			if(b==false)
			{
				if(!m_InputPin.get_isC()&&  n==1)
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

void LED :: AddConnection(Connection* con)
{
	connection = con;
}
void LED::RemoveConnection(Connection* con, Pin*, bool IsInput)
{
	con = NULL;
	m_InputPin.set_isc(false);
	m_InputPin.setStatus(LOW);
}

bool LED::fullconnected()
{
	if(m_InputPin.get_isC()==true)
		return true;
	else
		return false;
}

Connection** LED :: GetConnections(int& N)
{
	N = 1;
	return &connection;
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