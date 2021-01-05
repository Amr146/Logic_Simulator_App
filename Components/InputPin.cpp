#include "InputPin.h"

InputPin::InputPin()
{}

void InputPin::setComponent(Component *pCmp)
{
	pComp = pCmp;
	is_connected=false;

	
}

Component* InputPin::getComponent()
{
	return pComp;
}

void InputPin::set_isc(bool s)
{
	is_connected=s;
}

bool InputPin::get_isC()
{
	return is_connected;
}
