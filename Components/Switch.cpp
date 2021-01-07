#include "Switch.h"

Switch::Switch(const GraphicsInfo &r_GfxInfo, int r_FanOut):Component(r_GfxInfo),m_OutputPin(r_FanOut)
{
	IsSelected = false;
	m_OutputPin.setStatus(HIGH);
	ConnectionsList = new Connection * [r_FanOut];
	ConnectionsCount = 0;
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

void Switch::AddConnection(Connection* con)
{
	ConnectionsList[ConnectionsCount++] = con;
}
void Switch::RemoveConnection(Connection* con, Pin* pin, bool IsInput)
{
	for (int i = 0; i < ConnectionsCount; i++)
	{
		if (ConnectionsList[i] == con)
		{

			ConnectionsList[i] = ConnectionsList[ConnectionsCount - 1];
			ConnectionsList[ConnectionsCount - 1] = NULL;

			ConnectionsCount--;
			m_OutputPin.DisconnectFrom(con);
			break;
		}
	}


}

Connection** Switch::GetConnections(int& N)
{
	N = ConnectionsCount;
	return ConnectionsList;
}

Switch :: ~Switch()
{
	delete[] ConnectionsList;
}