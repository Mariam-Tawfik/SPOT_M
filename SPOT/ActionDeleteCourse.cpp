#include "ActionDeleteCourse.h"
bool ActionDeleteCourse::Execute() {
	GUI* pGUI = pReg->getGUI();
	int i = 0;
	pGUI->PrintMsg("Type code of the course that you need to delete from study-plan");
	string code = pGUI->GetSrting();
	
		vector<Course>courses = pReg->getCourseCatalog();
		Course* pC = nullptr;
		for (i = 0; i < courses.size(); ++i) {
			if (code == courses[i].getCode()) {
				StudyPlan* pS = pReg->getStudyPlay();
				pS->DeleteCourseFromPlan(pC, 1, FALL);
			}
		}
	return true;
}