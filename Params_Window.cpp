#include "Params_Window.h"

Params_Window::Params_Window(QWidget *parent)
	: QDialog(parent)
{
	_ui.setupUi(this);
	this->setFixedSize(300, 200);
	this->setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);
	this->setWindowIcon(QIcon("Textures/Icons/Tools Icons/Params_Icon.png"));
	this->setWindowTitle("System Parameters");

	
	_ui.Height_Edit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]*")));
	_ui.Width_Edit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]*")));
	_ui.Length_Edit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]*")));
	
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
	if (_ui.Height_Edit->text() != "" && _ui.Width_Edit->text() != "" && _ui.Length_Edit->text() != "") {
		Params.append(_ui.Name_Edit->text());
		Params.append(_ui.Firm_Edit->text());
		Params.append(_ui.Seria_Edit->text());
		Params.append(_ui.Height_Edit->text());
		Params.append(_ui.Width_Edit->text());
		Params.append(_ui.Length_Edit->text());
		Params.append(_ui.Weight_Edit->text());
	
		Params.append("0");
		Params.append("0");

		this->close();
	}
	else {
		QMessageBox::warning(this, "Error", "'Height' or 'Width', or 'Length' is empty");
	}
}