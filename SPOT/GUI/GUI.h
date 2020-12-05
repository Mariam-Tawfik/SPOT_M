#pragma once
#include <string>
#include <fstream>
using namespace std;

#include "..\DEFs.h"
#include "CMUgraphicsLib\CMUgraphics.h"

class Course;
class AcademicYear;
class Note;
//user interface class
class GUI
{

	enum MENU_ITEM //The items of the menu (you should add more items)
	{
		//Note: Items are ordered here as they appear in the menu
		//If you want to change the menu items order, just change the order here
		ITM_ADD,		//Add a new course
		ITM_ADD_NOTE,
		ITM_SHOW_NOTE,
		ITM_LOAD,
	    ITM_SAVE,
		ITM_UNDO,
		ITM_REDO,
        ITM_DEL,
		ITM_EXIT,		//Exit item

		ITM_CNT			//no. of menu items ==> This should be the last line in this enum

	};

	//Some constants for GUI
	static const int	WindWidth = 1000, WindHeight = 600,	//Window width and height
		wx = 15, wy = 15,		//Window starting coordinates
		StatusBarHeight = 60,	//Status Bar Height
		MenuBarHeight = 80,		//Menu Bar Height (distance from top of window to bottom line of menu bar)
		MenuItemWidth = 70,	   //Width of each item in the menu
		YearWidth = 80,
		YearHeight = 30;


	color DrawColor = BLACK;		//Drawing color
	color FillColor = SNOW;		//Filling color (for courses)
	color HiColor = RED;			//Highlighting color
	color ConnColor = GREEN;		//Connector color
	color MsgColor = BLUE;			//Messages color
	color BkGrndColor = GAINSBORO;	   //Background color
	color StatusBarColor = DARKGRAY; //statusbar color
	color YearColor = BLANCHEDALMOND;
	string WindTitle = "Study-Plan Organizational Tool (SPOT)";

	window* pWind;
	window* pNoteWind;
public:
	GUI();
	void CreateMenu() const;
	void ClearDrawingArea() const;
	void ClearStatusBar() const;	//Clears the status bar

	//output functions
	void PrintMsg(string msg) const;		//prints a message on status bar

	//Drawing functions
	void DrawCourse(const Course* );
	void DrawAcademicYear(const AcademicYear*);
	void DrawNotes(Note n);
	void UpdateInterface() const;
	
	//input functions
	ActionData GUI::GetUserAction(string msg = "") const;
	string GetSrting() const;


	
	

	~GUI();
};

