#include "Params_Window.h"

Params_Window::Params_Window(QWidget *parent)
	: QDialog(parent)
{
	_ui.setupUi(this);
	this->setFixedSize(300, 200);
	this->setWindowIcon(QIcon("Textures/Icons/Tools Icons/Params_Icon.png"));

	connect(_ui.Next_Button, SIGNAL(pressed()), this, SLOT(Set_Params()));
}


Params_Window::~Params_Window()
{

}

QStringList Params_Window::Get_Params()
{
	return Params;
}

void Params_Window::Set_Params(){
	Params.append(_ui.Name_Edit->text());
	Params.append(_ui.Firm_Edit->text());
	Params.append(_ui.Seria_Edit->text());
	Params.append(_ui.Height_Edit->text());
	Params.append(_ui.Width_Edit->text());
	Params.append(_ui.Lenght_Edit->text());
	Params.append(_ui.Weight_Edit->text());

	this->close();
}