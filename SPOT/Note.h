#pragma once
#include<string>
#include"GUI/Drawable.h"
using namespace std;

class Note :public Drawable
{
	string myNote;
public:
	void setmyNote(string);
	string getmyNote();
	void virtual DrawMe(GUI*) const;
};

