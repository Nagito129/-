#include "Params_Window.h"

Params_Window::Params_Window(QWidget *parent)
	: QDialog(parent)
{
	_ui.setupUi(this);
	this->setFixedSize(300, 250);
	this->setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);
	this->setWindowIcon(QIcon("Textures/Icons/Tools Icons/Params_Icon.png"));
	this->setWindowTitle("System Parameters");

	_ui.X_Edit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]*")));
	_ui.Y_Edit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]*")));
	
	_ui.X_Edit->setStyleSheet("background-color: rgb(255, 255, 255)");
	_ui.Y_Edit->setStyleSheet("background-color: rgb(255, 255, 255)");
	
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
	
	if (_ui.X_Edit->text() == "") {
		_ui.X_Edit->setText("0");
	}
	if (_ui.Y_Edit->text() == "") {
		_ui.Y_Edit->setText("0");
	}
	
	Params.append(_ui.X_Edit->text());
	Params.append(_ui.Y_Edit->text());

	this->close();
}