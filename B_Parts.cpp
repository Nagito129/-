#include "B_Parts.h"

B_Parts::B_Parts(int Part)
{
	if (Part == WALL) {
		this->Part = WALL;
		Wall = new Wall_Sample;
	}
	else if (Part == WINDOW) {
		this->Part = WINDOW;
		Window = new Window_Sample;

	}
	else if (Part == DOOR) {
		this->Part = DOOR;
		Door = new Door_Sample;

	}
	else if (Part == STAIRS) {
		this->Part = STAIRS;
		Stairs = new Stairs_Sample;
	}
}

B_Parts::~B_Parts()
{
	if (Part == WALL) {
		delete Wall;
	}
	else if (Part == WINDOW) {
		delete Window;
	}
	else if (Part == DOOR) {
		delete Door;
	}
	else if (Part == STAIRS) {
		delete Stairs;
	}
}

void B_Parts::Set_Mode(int Mode)
{
	if (Part == WALL) {
		Wall->Set_Mode(Mode);
	}
	else if (Part == WINDOW) {
		Window->Set_Mode(Mode);
	}
	else if (Part == DOOR) {
		Door->Set_Mode(Mode);
	}
	else if (Part == STAIRS) {
		Stairs->Set_Mode(Mode);
	}
}

bool B_Parts::Get_Delete_Flag()
{
	if (Part == WALL) {
		return Wall->Get_Delete_Flag();
	}
	else if (Part == WINDOW) {
		return Window->Get_Delete_Flag();
	}
	else if (Part == DOOR) {
		return Door->Get_Delete_Flag();
	}
	else if (Part == STAIRS) {
		return Stairs->Get_Delete_Flag();
	}
}

bool B_Parts::Spawn_Accept()
{
	if (Part == WALL) {
		return Wall->Spawn_Accept();
	}
	else if (Part == WINDOW) {
		return Window->Spawn_Accept();
	}
	else if (Part == DOOR) {
		return Door->Spawn_Accept();
	}
	else if (Part == STAIRS) {
		return Stairs->Spawn_Accept();
	}
}
