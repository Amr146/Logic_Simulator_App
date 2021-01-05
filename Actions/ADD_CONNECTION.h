#ifndef _ADD_CONNECTION_H
#define _ADD_CONNECTION_H

#include "Action.h"
#include "../Components/Connection.h"

class AddConnection : public Action
{
	int x1, x2 , y1 , y2;
	int i,k,n_DstPin;
	bool raction;
public:
	AddConnection(ApplicationManager *pApp);

	virtual ~AddConnection(void);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
#endif
