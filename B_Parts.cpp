/**
 * @file B_Parts.h
 * @brief ќпределение класса B_Parts дл€ управлени€ элементами строительных частей
 */

#include "B_Parts.h"

 /**
  * @brief  онструктор класса B_Parts
  * @param Part “ип строительной части
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
 * @brief  онструктор класса B_Parts с параметрами
 * @param Params ѕараметры строительной части
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
 * @brief ƒеструктор класса B_Parts
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
 * @brief ”становка режима работы дл€ строительной части
 * @param Mode –ежим работы
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
 * @brief ѕолучение флага удалени€ дл€ строительной части
 * @return true, если часть должна быть удалена, в противном случае - false
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
 * @brief ѕодтверждение создани€ строительной части
 * @return true, если создание разрешено, в противном случае - false
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
 * @brief ѕолучение типа строительной части
 * @return “ип строительной части
 */
int B_Parts::Get_Part() {
	return Part;
}
