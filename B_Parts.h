#pragma once

#include "Wall_Sample.h"
#include "Window_Sample.h"
#include "Door_Sample.h"
#include "Stairs_Sample.h"

class B_Parts
{
public:
    B_Parts(int Part);
    ~B_Parts();

    void Set_Mode(int Mode);
    bool Get_Delete_Flag();
    bool Spawn_Accept();
    Wall_Sample* Wall;
    Window_Sample* Window;
    Door_Sample* Door;
    Stairs_Sample* Stairs;

private:
    enum Build_Parts {
        WALL = 1,
        WINDOW = 2,
        DOOR = 3,
        STAIRS = 4
    };

    Build_Parts Part;
};

