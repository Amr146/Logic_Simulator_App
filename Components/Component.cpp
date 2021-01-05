#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;

}

bool Component :: InsideMe(int x, int y)
{
	if (x >= m_GfxInfo.x1 && x <= m_GfxInfo.x2 && y >= m_GfxInfo.y1 && y <= m_GfxInfo.y2)
		return true;
	else
		return false;
}

void Component::SetIsSelected(bool q)
{
	IsSelected = q;
}
bool Component:: getisselected()
{
	return IsSelected;
}

GraphicsInfo Component::get_graphicinfo()
{
	return m_GfxInfo;
}

Component::Component()
{
	IsSelected=false;
}

Component::~Component()
{}


