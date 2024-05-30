/**
 * @file B_Parts.h
 * @brief ����������� ������ B_Parts ��� ���������� ���������� ������������ ������
 */

#include "B_Parts.h"

 /**
  * @brief ����������� ������ B_Parts
  * @param Part ��� ������������ �����
  */
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

/**
 * @brief ����������� ������ B_Parts � �����������
 * @param Params ��������� ������������ �����
 */
B_Parts::B_Parts(QStringList Params) {
	int Part = Params[0].toInt();
	if (Part == WALL) {
		this->Part = WALL;
		Wall = new Wall_Sample(Params[3].toInt(), Params[4].toInt());
	}
	else if (Part == WINDOW) {
		this->Part = WINDOW;
		Window = new Window_Sample(Params[3].toInt(), Params[4].toInt());

	}
	else if (Part == DOOR) {
		this->Part = DOOR;
		Door = new Door_Sample(Params[3].toInt(), Params[4].toInt());

	}
	else if (Part == STAIRS) {
		this->Part = STAIRS;
		Stairs = new Stairs_Sample(Params[3].toInt(), Params[4].toInt());
	}
}

/**
 * @brief ���������� ������ B_Parts
 */
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

/**
 * @brief ��������� ������ ������ ��� ������������ �����
 * @param Mode ����� ������
 */
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

/**
 * @brief ��������� ����� �������� ��� ������������ �����
 * @return true, ���� ����� ������ ���� �������, � ��������� ������ - false
 */
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

/**
 * @brief ������������� �������� ������������ �����
 * @return true, ���� �������� ���������, � ��������� ������ - false
 */
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

/**
 * @brief ��������� ���� ������������ �����
 * @return ��� ������������ �����
 */
int B_Parts::Get_Part() {
	return Part;
}
