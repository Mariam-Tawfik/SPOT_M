#include "AcademicYear.h"
#include "../GUI/GUI.h"
#include <iterator>
AcademicYear::AcademicYear()
{
	//TODO: make all necessary initializations
}


AcademicYear::~AcademicYear()
{
}

//Adds a course to this year in the spesified semester
bool AcademicYear::AddCourse(Course* pC, SEMESTER sem) 
{
	//TODO:
	//This function still needs many checks to be compelete
	YearCourses[sem].push_back(pC);
	TotalCredits += pC->getCredits();

	//TODO: acording to course type incremenet corrsponding toatl hours for that year
	if (pC->getCourseType() == UNIV)
		TotalUnivCredits += pC->getCredits();
	else if (pC->getCourseType() == MAJOR)
		TotalMajorCredits += pC->getCredits();
	else if (pC->getCourseType() == MINOR)
		TotalMinorCredits += pC->getCredits();
	else if (pC->getCourseType() == CON)
		TotalConcentrationCredits += pC->getCredits();
	else if (pC->getCourseType() == TRACK)
		TotalTrackCredits += pC->getCredits();
	return true;
}
bool AcademicYear::DeleteCourse(Course* pC, SEMESTER sem)
{
	list<Course*> ::iterator ptr = YearCourses->begin();
	for (ptr = YearCourses[sem].begin(); ptr != YearCourses[sem].end(); ++ptr) {
		if (pC == *ptr) {
			YearCourses[sem].erase(ptr);
			TotalCredits -= pC->getCredits();


			if (pC->getCourseType() == UNIV)
				TotalUnivCredits -= pC->getCredits();
			else if (pC->getCourseType() == MAJOR)
				TotalMajorCredits -= pC->getCredits();
			else if (pC->getCourseType() == MINOR)
				TotalMinorCredits -= pC->getCredits();
			else if (pC->getCourseType() == CON)
				TotalConcentrationCredits -= pC->getCredits();
			else if (pC->getCourseType() == TRACK)
				TotalTrackCredits -= pC->getCredits();
		}
	}
	return true;
}
	

void AcademicYear::DrawMe(GUI* pGUI) const
{
	pGUI->DrawAcademicYear(this);
	//Draw all semesters inside this year by iterating on each semester list
	//to get courses and draw each course

	
	for (int sem = FALL; sem < SEM_CNT; sem++) {
		for (auto it = YearCourses[sem].begin(); it != YearCourses[sem].end(); ++it)
		{
			(*it)->DrawMe(pGUI);	//call DrawMe for each course in this semester
		}
	}
}