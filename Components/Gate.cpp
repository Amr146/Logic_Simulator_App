#include "Gate.h"

//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(int r_Inputs, int r_FanOut):m_OutputPin(r_FanOut)
{
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate
	//Associate all input pins to this gate
	for(int i=0; i<m_Inputs; i++)
		m_InputPins[i].setComponent(this);
}


bool Gate::is_comp(int &x, int &y,int&n,bool b)
{
	if(m_GfxInfo.x1<x && m_GfxInfo.x2>x && m_GfxInfo.y1<y && m_GfxInfo.y2>y)
		{
			if(b==true)
			{
				if(m_OutputPin.can_connected())
				{
					x=m_GfxInfo.x2;
					y=m_GfxInfo.y1+25;
				}
				else
					return false;
			}
			else
			{
				x=m_GfxInfo.x1;
				if(m_Inputs==1)
				{
					y=m_GfxInfo.y1+25;
					m_InputPins[0].set_isc(true);
					n=1;
				}

				if(m_Inputs==2)
				
				{
					if(!m_InputPins[0].get_isC())
					{
						y=m_GfxInfo.y1+13;
						m_InputPins[0].set_isc(true);
						n=1;
					}
					else if(!m_InputPins[1].get_isC())
					{
						y=m_GfxInfo.y2-13;
						m_InputPins[1].set_isc(true);
						n=2;
					}
					else 
						return false;
				}
				if(m_Inputs==3)
				{
					if(!m_InputPins[0].get_isC())
					{
						y=m_GfxInfo.y1+10;
						m_InputPins[0].set_isc(true);
						n=1;
					}
					else if(!m_InputPins[1].get_isC())
					{
						y=m_GfxInfo.y1+25;
						m_InputPins[1].set_isc(true);
						n=2;
					}
					else if(!m_InputPins[2].get_isC())
					{
						y=m_GfxInfo.y2-10;
						m_InputPins[2].set_isc(true);
						n=3;
					}
					else 
						return false;
				}

			}

			return true;
		}
	else
		return false;
}

OutputPin* Gate::getSourcePin()
{
	return &m_OutputPin;
}
InputPin* Gate::getDestPin(int n)
{
	return &m_InputPins[n-1];
}
