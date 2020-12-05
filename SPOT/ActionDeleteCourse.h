#pragma once
#include "Actions/Action.h"
#include"Registrar.h"
class ActionDeleteCourse :
    public Action
{
public:
    ActionDeleteCourse(Registrar* p) :Action(p) {};
    bool virtual Execute(); //pure virtual 
};

