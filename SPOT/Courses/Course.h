#pragma once
#include <string>
#include <list>
using namespace std;
#include "..\DEFs.h"

#include "../GUI/Drawable.h"

//Base class for all types of courses
enum CourseType {
	UNIV,
	TRACK,
	CON, // MEANS concentration
	MINOR,
	MAJOR
};
class Course : public Drawable
{
	const Course_Code code;	//course code: e.g. "CIE202". This is the course ID
	const string Title;		//course title: e.g. "Fundamentals of Computer Programming"
	int credits;	//no. of course credits
	CourseType type;	//Univ, track, or major.....etc.
	bool Done;		//Done or not yet?
	list<Course_Code> PreReq;	//list of prerequisites
	list<Course_Code> CoReq;	//list of prerequisites
public:
	Course(Course_Code r_code,string r_title, int crd);
	string getTitle() const;
	string getCode() const;
	int getCredits() const;
	CourseType getCourseType() const;
	void DrawMe(GUI*) const;
	virtual ~Course();

};
