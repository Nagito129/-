#pragma once
#include <qwidget.h>

#include "ui_System_Item.h"
#include "Square_Sample.h"
#include "Circle_Sample.h"

class System_Item : public QWidget
{
	Q_OBJECT

public:	
	System_Item(QWidget* parent = nullptr);
	~System_Item();
	
	void Set_Params(QStringList Params, QString Icon);

	QStringList Params;
	QStringList Get_Params();
	void Set_Position(qreal x, qreal y);
	void Set_Mode(int Mode);
	bool Get_Delete_Flag();

	bool is_Square = true;
	QColor Color;
	qreal Workload;

	Square_Sample* Square;
	Circle_Sample* Circle;
private:
	Ui::Sistem_Item sys;
	void Status_Color();
	void Set_Workload();

public slots:
	void Set_Firm();
	void Set_Seria();
	void Set_Weidh();
	void Info();
	

};

