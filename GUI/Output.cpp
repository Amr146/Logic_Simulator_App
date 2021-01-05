#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode
	UI.gatesGroup = 1;
	UI.displayCompBar = false;

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;
	
	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);	
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(UI.MsgColor); 
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string DesignMenuItemImages[ITM_DSN_CNT];
	DesignMenuItemImages[ITM_ADD] = "images\\Menu\\Menu_ADD.jpg";
	DesignMenuItemImages[ITM_CONNECTION] = "images\\Menu\\Menu_CONNECTION.jpg";
	DesignMenuItemImages[ITM_LABEL] = "images\\Menu\\Menu_Label.jpg";
	DesignMenuItemImages[ITM_EDIT] = "images\\Menu\\Menu_Edit.jpg";
	DesignMenuItemImages[ITM_DELETE]  = "images\\Menu\\Menu_DELETE.jpg";
	DesignMenuItemImages[ITM_MOVE]  = "images\\Menu\\Menu_Move.jpg";
	DesignMenuItemImages[ITM_COPY] = "images\\Menu\\Menu_Copy.jpg";
	DesignMenuItemImages[ITM_CUT] = "images\\Menu\\Menu_Cut.jpg";
	DesignMenuItemImages[ITM_SIM_MODE] = "images\\Menu\\Menu_SIM_MODE.jpg";
	DesignMenuItemImages[ITM_SAVE] = "images\\Menu\\Menu_SAVE.jpg";
	DesignMenuItemImages[ITM_LOAD] = "images\\Menu\\Menu_LOAD.jpg";
	DesignMenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";

	//TODO: Prepare image for each menu item and add it to the list

	string CompMenuItemImages[ITM_CMP_CNT];
	CompMenuItemImages[ITM_Buff] = "images\\Menu\\Menu_Buff.jpg";
	CompMenuItemImages[ITM_INV] = "images\\Menu\\Menu_INV.jpg";
	CompMenuItemImages[ITM_AND2] = "images\\Menu\\Menu_AND2.jpg";
	CompMenuItemImages[ITM_OR2] = "images\\Menu\\Menu_OR2.jpg";
	CompMenuItemImages[ITM_NAND2] = "images\\Menu\\Menu_NAND2.jpg";
	CompMenuItemImages[ITM_NOR2] = "images\\Menu\\Menu_NOR2.jpg";
	CompMenuItemImages[ITM_XOR2] = "images\\Menu\\Menu_XOR2.jpg";
	CompMenuItemImages[ITM_XNOR2] = "images\\Menu\\Menu_XNOR2.jpg";
	CompMenuItemImages[ITM_NEXT] = "images\\Menu\\Menu_Next.jpg";
	CompMenuItemImages[ITM_PREVIOUS] = "images\\Menu\\Menu_Previous.jpg";
	CompMenuItemImages[ITM_AND3] = "images\\Menu\\Menu_AND3.jpg";
	CompMenuItemImages[ITM_NOR3] = "images\\Menu\\Menu_NOR3.jpg";
	CompMenuItemImages[ITM_XOR3] = "images\\Menu\\Menu_XOR3.jpg";
	CompMenuItemImages[ITM_Switch] = "images\\Menu\\Menu_Switch.jpg";
	CompMenuItemImages[ITM_LED] = "images\\Menu\\Menu_LED.jpg";
	CompMenuItemImages[ITM_CLOSE] = "images\\Menu\\Menu_Close.jpg";

	//Draw menu item one image at a time
	if(UI.displayCompBar)
	{ 
		if (UI.gatesGroup == 1)
		{
			for (int i = 0; i < 8; i++)
				pWind->DrawImage(CompMenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
			pWind->SetPen(RED, 3);
			pWind->DrawLine(UI.ToolItemWidth * ITM_NEXT, UI.ToolBarHeight, UI.ToolItemWidth * ITM_NEXT, 0);
			pWind->DrawImage(CompMenuItemImages[ITM_NEXT], ITM_NEXT * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
		}
		else
		{
			pWind->DrawImage(CompMenuItemImages[ITM_PREVIOUS], 0, 0, UI.ToolItemWidth, UI.ToolBarHeight);
			pWind->SetPen(RED, 3);
			pWind->DrawLine(UI.ToolItemWidth, UI.ToolBarHeight, UI.ToolItemWidth, 0);
			for (int i = 1; (i + ITM_PREVIOUS) < ITM_Switch; i++)
				pWind->DrawImage(CompMenuItemImages[i + ITM_PREVIOUS], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
			pWind->SetPen(WHITE, 1);
			pWind->SetBrush(WHITE);
			pWind->DrawRectangle(4 * UI.ToolItemWidth, 0, ITM_Switch * UI.ToolItemWidth, UI.ToolBarHeight);
		}
		pWind->SetPen(RED, 6);
		pWind->DrawLine(UI.ToolItemWidth * 9, UI.ToolBarHeight, UI.ToolItemWidth * 9, 0);
		for (int i = 13; i < ITM_CMP_CNT; i++)
			pWind->DrawImage(CompMenuItemImages[i], (i - 4) * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
	}
	else
	{
		for (int i = 0; i < ITM_DSN_CNT; i++)
			pWind->DrawImage(DesignMenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
		
	}

	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION;	//Simulation Mode
	string DesignMenuItemImages[ITM_SIM_CNT];
	DesignMenuItemImages[ITM_SIM] = "images\\Menu\\Menu_SIM_MODE.jpg";
	DesignMenuItemImages[ITM_DSN_MODE] = "images\\Menu\\Menu_DSN_MODE.jpg";
	DesignMenuItemImages[ITM_TRUTH] = "images\\Menu\\Menu_TRUTH.jpg";


	for(int i=0; i<ITM_SIM_CNT; i++)
		pWind->DrawImage(DesignMenuItemImages[i],i*UI.ToolItemWidth,0,UI.ToolItemWidth, UI.ToolBarHeight);

	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(ITM_SIM_CNT * UI.ToolItemWidth, 0, UI.width, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)
	//edited

}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Hilighted\\and.jpg";
	else  
		GateImage = "Images\\Gates\\Normal\\and.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

//TODO: Add similar functions to draw all components	===================================>>>>>>>>>>>>		DONE

void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Hilighted\\or.jpg";
	else  
		GateImage = "Images\\Gates\\Normal\\or.jpg";

	//Draw OR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNOT(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Hilighted\\not.jpg";
	else  
		GateImage = "Images\\Gates\\Normal\\not.jpg";

	//Draw NOT Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Hilighted\\nand.jpg";
	else  
		GateImage = "Images\\Gates\\Normal\\nand.jpg";

	//Draw NAND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Hilighted\\nor.jpg";
	else  
		GateImage = "Images\\Gates\\Normal\\nor.jpg";

	//Draw OR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}


void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Hilighted\\xor.jpg";
	else  
		GateImage = "Images\\Gates\\Normal\\xor.jpg";

	//Draw XOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}


void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Hilighted\\xnor.jpg";
	else  
		GateImage = "Images\\Gates\\Normal\\xnor.jpg";

	//Draw XNOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}


void Output::DrawBUFFER(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Hilighted\\buffer.jpg";
	else  
		GateImage = "Images\\Gates\\Normal\\buffer.jpg";

	//Draw BUFFER Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}


void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Hilighted\\and3.jpg";
	else  
		GateImage = "Images\\Gates\\Normal\\and3.jpg";

	//Draw AND3 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}


void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Hilighted\\nor3.jpg";
	else  
		GateImage = "Images\\Gates\\Normal\\nor3.jpg";

	//Draw NOR3 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}


void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Hilighted\\xor3.jpg";
	else  
		GateImage = "Images\\Gates\\Normal\\xor3.jpg";

	//Draw XOR3 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}


void Output::DrawSWITCH(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Hilighted\\switch_on.jpg";
	else  
		GateImage = "Images\\Gates\\Normal\\switch_on.jpg";

	//Draw SWITCH at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}


void Output::DrawLEDoff(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Hilighted\\led_off.jpg";
	else  
		GateImage = "Images\\Gates\\Normal\\led_off.jpg";

	//Draw LED at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawLEDon(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Hilighted\\led_on.jpg";
	else  
		GateImage = "Images\\Gates\\Normal\\led_on.jpg";

	//Draw LED at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}



void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{
	//TODO: Add code to draw connection		======================================>>>>>>>>>>>>>>>>>>>>>>>>>>>>>		DONE
	
	if(selected)	//use connection in the highlighted case
		pWind->SetPen(UI.SelectColor,3);
	else  
		pWind->SetPen(UI.DrawColor,3);


	pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x1+((r_GfxInfo.x2-r_GfxInfo.x1)/4) , r_GfxInfo.y1);	
	pWind->DrawLine(r_GfxInfo.x1+((r_GfxInfo.x2-r_GfxInfo.x1)/4), r_GfxInfo.y1,r_GfxInfo.x1+((r_GfxInfo.x2-r_GfxInfo.x1)/4), r_GfxInfo.y2);	
	pWind->DrawLine(r_GfxInfo.x1+((r_GfxInfo.x2-r_GfxInfo.x1)/4), r_GfxInfo.y2, r_GfxInfo.x2 , r_GfxInfo.y2);	
}

void Output::PrintLabel(GraphicsInfo r_GfxInfo, string lbl) const
{
	// Print the label
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);

	int lblWidth, lblHeight;
	pWind->GetStringSize(lblWidth, lblHeight, lbl);
	while(r_GfxInfo.x1 < 0 || r_GfxInfo.x1 > UI.width - (lblWidth+3*lbl.length()) || r_GfxInfo.y1 < UI.ToolBarHeight || r_GfxInfo.y1 > UI.height - UI.StatusBarHeight - lblHeight){
		PrintMsg("You are not allowed to print your label outside the drawing area, choose your place again...");
		pWind->WaitMouseClick(r_GfxInfo.x1, r_GfxInfo.y1);
	}
	pWind->DrawString(r_GfxInfo.x1, r_GfxInfo.y1, lbl);
}

Output::~Output()
{
	delete pWind;
}
