#include "ActionAddCourse.h"
#include "..\Registrar.h"
#include "../Courses/UnivCourse.h"
#include <fstream>
#include <iostream>
#include <string>
#include<sstream>
#include "..//Registrar.h"
using namespace std;
ActionAddCourse::ActionAddCourse(Registrar* p):Action(p)
{
	
}

bool ActionAddCourse::Execute()
{
	GUI* pGUI = pReg->getGUI();	
	
	pGUI->PrintMsg("Add Course to plan: Enter course Code(e.g. CIE202):");
	Course_Code code = pGUI->GetSrting();
	int crd;
	string courseTitle;
	int i = 0;
	//TODO: add input validation


	ActionData actData = pGUI->GetUserAction("Select a year to add coures to:");
	//TODO: add input validation
	if (actData.x < 130) {
		actData.x = 130;
	}
		int x, y;
		if (actData.actType == DRAW_AREA)	//user clicked inside drawing area
		{
			//get coord where user clicked
			x = actData.x;
			y = actData.y;
			graphicsInfo gInfo{ x, y };
			vector<Course>courses = pReg->getCourseCatalog();
			Course* pC = nullptr;
			for (i = 0; i < courses.size(); ++i) {
				if (code == courses[i].getCode()) {
					crd = courses[i].getCredits();
					Course* pC = new Course(courses[i].getCode(), courses[i].getTitle(), crd);
				}
			}

			pC->setGfxInfo(gInfo);

			//TODO: Ask registrar to add course to the year selected by the user
			//TODO: add the course to the correct year obtained from registrar
			StudyPlan* pS = pReg->getStudyPlay();
			pS->AddCourse(pC, 1, FALL);
			if (gInfo.y > 540 && gInfo.y <= 450) {
				if (gInfo.y >= 540 && gInfo.y <= 514)
					pS->AddCourse(pC, 1, FALL);
				if (gInfo.y > 514 && gInfo.y <= 488)
					pS->AddCourse(pC, 1, SPRING);
				if (gInfo.y > 488 && gInfo.y <= 450)
					pS->AddCourse(pC, 1, SUMMER);
			}
			else if (gInfo.y > 450 && gInfo.y <= 370)
			{
				if (gInfo.y >= 460 && gInfo.y <= 434)
					pS->AddCourse(pC, 2, FALL);
				if (gInfo.y > 434 && gInfo.y <= 408)
					pS->AddCourse(pC, 2, SPRING);
				if (gInfo.y > 408 && gInfo.y <= 370)
					pS->AddCourse(pC, 2, SUMMER);
			}
			else if (gInfo.y > 370 && gInfo.y <= 290) {
				if (gInfo.y >= 380 && gInfo.y <= 354)
					pS->AddCourse(pC, 3, FALL);
				if (gInfo.y > 354 && gInfo.y <= 328)
					pS->AddCourse(pC, 3, SPRING);
				if (gInfo.y > 328 && gInfo.y <= 290)
					pS->AddCourse(pC, 3, SUMMER);
			}
			else if (gInfo.y > 290 && gInfo.y <= 210) {
				if (gInfo.y >= 300 && gInfo.y <= 274)
					pS->AddCourse(pC, 4, FALL);
				if (gInfo.y > 274 && gInfo.y <= 248)
					pS->AddCourse(pC, 4, SPRING);
				if (gInfo.y > 248 && gInfo.y <= 210)
					pS->AddCourse(pC, 4, SUMMER);
			}
			else if (gInfo.y > 210 && gInfo.y <= 100) {
				if (gInfo.y >= 220 && gInfo.y <= 194)
					pS->AddCourse(pC, 5, FALL);
				if (gInfo.y > 194 && gInfo.y <= 168)
					pS->AddCourse(pC, 5, SPRING);
				if (gInfo.y > 168 && gInfo.y <= 100)
					pS->AddCourse(pC, 4, SUMMER);
			}

		}
	return true;
}


		ActionAddCourse::~ActionAddCourse()
		{
		}
