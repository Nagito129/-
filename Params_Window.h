#pragma once

#include <QDialog>
#include <QValidator>
#include <QMessageBox>
#include "ui_Params_Window.h"

class Params_Window : public QDialog
{
	Q_OBJECT

public:
	Params_Window(QWidget *parent = nullptr);
	~Params_Window();
	
	QStringList Get_Params();

private:
	Ui:: Params_WindowClass _ui;
	
	QStringList Params;

public slots:
	void Set_Params();
};
