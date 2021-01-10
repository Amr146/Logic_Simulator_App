#include "Connection.h"
#include "Gate.h"
Connection::Connection(const GraphicsInfo &r_GfxInfo, Component *pS,Component *pD, int Pin ):Component(r_GfxInfo), SelectBoxSize(2)
	
{
	IsSelected = false;
	SrcCmpnt=pS;
	DstCmpnt=pD;
	n_DstPin=Pin;
	SrcPin=pS->getSourcePin();
	DstPin=pD->getDestPin(Pin);
	SrcPin->ConnectTo(this);
	SrcCmpnt->AddConnection(this);
	DstCmpnt->AddConnection(this);
	setID(0);
}

void Connection::setSourcePin(OutputPin *pSrcPin)
{	SrcPin = pSrcPin;	}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}


void Connection::setDestPin(InputPin *pDstPin)
{	DstPin = pDstPin;	}

InputPin* Connection::getDestPin(int n)
{	return DstPin;	}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(Output* pOut)
{
	bool s;

	s=(SrcPin->getStatus()==HIGH);
		
	pOut->DrawConnection(m_GfxInfo, IsSelected, s);
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}

bool Connection::is_comp(int& x,int& y,int&n, bool b)
{
	if(b==true)
	{
		if(!(SrcPin->can_connected()))
			return false;
		return InsideMe(x,y);
	}

	else return false;
}


bool Connection::fullconnected()
{
	return true;
}

bool Connection::InsideMe(int x, int y)
{
	if (x >= (m_GfxInfo.x1) - SelectBoxSize && x <= m_GfxInfo.x1 + ((m_GfxInfo.x2 - m_GfxInfo.x1) / 4) + SelectBoxSize && y >= m_GfxInfo.y1 - SelectBoxSize && y <= m_GfxInfo.y1 + SelectBoxSize)
		return true;
	else if (x >= m_GfxInfo.x1 - SelectBoxSize + ((m_GfxInfo.x2 - m_GfxInfo.x1) / 4) + SelectBoxSize && x <= m_GfxInfo.x2 + SelectBoxSize && y >= m_GfxInfo.y2 - SelectBoxSize && y <= m_GfxInfo.y2 + SelectBoxSize)
		return true;
	else if (m_GfxInfo.y1 < m_GfxInfo.y2 && x >= m_GfxInfo.x1 - SelectBoxSize + ((m_GfxInfo.x2 - m_GfxInfo.x1) / 4) && x <= m_GfxInfo.x1 + SelectBoxSize + ((m_GfxInfo.x2 - m_GfxInfo.x1) / 4) && y >= m_GfxInfo.y1 + SelectBoxSize && y <= m_GfxInfo.y2 + SelectBoxSize)
		return true;
	else if (m_GfxInfo.y1 > m_GfxInfo.y2 && x >= m_GfxInfo.x1 - SelectBoxSize + ((m_GfxInfo.x2 - m_GfxInfo.x1) / 4)  && x <= m_GfxInfo.x1 + SelectBoxSize + ((m_GfxInfo.x2 - m_GfxInfo.x1) / 4) && y <= m_GfxInfo.y1 + SelectBoxSize && y >= m_GfxInfo.y2 + SelectBoxSize)
		return true;
	else
		return false;
}


ActionType Connection::getactiontype()
{
	return ADD_CONNECTION;
}

void Connection::setSrcComp(Component* Src){
	SrcCmpnt = Src;
}
void Connection::setDestComp(Component* Dest){
	DstCmpnt = Dest;
}

Component*	Connection::GetSrcCmpnt(){
	return SrcCmpnt;
}
Component*	Connection::GetDstCmpnt(){
	return DstCmpnt;
}

GraphicsInfo* Connection::getGfxInfo(){
	return &m_GfxInfo;
}

//writes the component information in the save file
void Connection::Save(ofstream& saveFile)
{
	saveFile << SrcCmpnt->getID() << "\t" << DstCmpnt->getID() << "\t" << n_DstPin << endl;
}

//Loads the component information
void Connection::Load(string lbl, int id)
{

}

Connection :: ~Connection()
{
	SrcCmpnt->RemoveConnection(this, SrcPin, false);
	DstCmpnt->RemoveConnection(this, DstPin, true);
}