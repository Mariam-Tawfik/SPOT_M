#include "Registrar.h"

#include "Actions/ActionAddCourse.h"
#include"ActionAddNotes.h"
#include "ActionShowNotes.h"
#include "ActionDeleteCourse.h"

Registrar::Registrar()
{
	pGUI = new GUI;	//create interface object
	pSPlan = new StudyPlan;	//create a study plan.
}

//returns a pointer to GUI
GUI* Registrar::getGUI() const
{
	return pGUI;
}

//returns the study plan
StudyPlan* Registrar::getStudyPlay() const
{
	return pSPlan;
}

Action* Registrar::CreateRequiredAction() 
{	
	ActionData actData = pGUI->GetUserAction("Pick an action...");
	Action* RequiredAction = nullptr;

	switch (actData.actType)
	{
	case ADD_CRS:	//add_course action
		RequiredAction = new ActionAddCourse(this);
		break;

	case ADD_NOTE: //
		RequiredAction = new ActionAddNotes(this);
		break;
	case SHOW_NOTE: //
		RequiredAction = new ActionShowNotes(this);
		break;
	case DEL_CRS: //delete course
		RequiredAction = new ActionDeleteCourse(this);
		break;
	case SAVE: //save course
		RequiredAction = new ActionAddCourse(this);
		break;
	case UNDO: 
		RequiredAction = new ActionAddCourse(this);
		break;
	case REDO:
		RequiredAction = new ActionAddCourse(this);
		break;
	case LOAD: //Load study plan
		RequiredAction = new ActionAddCourse(this);
		break;
	case EXIT:
		RequiredAction = nullptr;
		break;
		
	}
	return RequiredAction;
}

//Executes the action, Releases its memory, and return true if done, false if cancelled
bool Registrar::ExecuteAction(Action* pAct)
{
	bool done = pAct->Execute();
	delete pAct;	//free memory of that action object (either action is exec or cancelled)
	return done;
}

void Registrar::Run()
{
	while (true)
	{
		//update interface here as CMU Lib doesn't refresh itself
		//when window is minimized then restored
		UpdateInterface();

		Action* pAct = CreateRequiredAction();
		if (pAct)	//if user doesn't cancel
		{
			if (ExecuteAction(pAct))	//if action is not cancelled
				UpdateInterface();
		}
	}
}


void Registrar::UpdateInterface()
{
	pGUI->UpdateInterface();	//update interface items
	pSPlan->DrawMe(pGUI);		//make study plan draw itself
}

Registrar::~Registrar()
{
	delete pGUI;
}
