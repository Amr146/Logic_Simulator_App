#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	Component* Selected; //poiter to the selected component
	Component* Clipboard; //poiter to the component in the clipboard
	Mode ClipboardMode;
	ActionType ClipboardType;
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)

	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface


public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window
	
	void SetSelected(Component*); //Sets Selected pointer
	void deletecomp(Component*);  //deletes a component from the componentslist 
	Component* GetSelected();  //gets Selected pointer

	void SetClipboard(Component*, Mode, ActionType); //Sets Clipboard pointer
	Component* GetClipboard(Mode&, ActionType&);  //gets Clipboard pointer


	Component* GetClickedComponent(int x, int y);

	void Simulate(); //Operate all of the components

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);

	Component* get_Component(int n);

	bool is_com(int&, int&, int& ,int&, bool);

	//destructor
	~ApplicationManager();
};

#endif