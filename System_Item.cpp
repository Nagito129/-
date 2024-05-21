#include "System_Item.h"

System_Item::System_Item(QWidget* parent)
	: QWidget(parent)
{
	sys.setupUi(this);
	sys.Info->hide();
	this->setFixedSize(300, 25);
	

	connect(sys.Item_Name, SIGNAL(pressed()), this, SLOT(Info()));
	connect(sys.Firm_Edit, SIGNAL(returnPressed()), this, SLOT(Set_Firm()));
	connect(sys.Seria_Edit, SIGNAL(returnPressed()), this, SLOT(Set_Seria()));
	connect(sys.Height_Edit, SIGNAL(returnPressed()), this, SLOT(Set_Height()));
	connect(sys.Width_Edit, SIGNAL(returnPressed()), this, SLOT(Set_Width()));
	connect(sys.Lenght_Edit, SIGNAL(returnPressed()), this, SLOT(Set_Lenght()));
	connect(sys.Weight_Edit, SIGNAL(returnPressed()), this, SLOT(Set_Weidh()));
}

void System_Item::Set_Params(QStringList Params, QString Icon)
{
	this->Params = Params;
	sys.Item_Name->setText(Params[0]);
	sys.Item_Name->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	sys.Item_Name->setIcon(QIcon("Textures/Icons/Tools Icons/" + Icon));
	sys.Firm_Edit->setText(Params[1]);
	sys.Seria_Edit->setText(Params[2]);
	sys.Height_Edit->setText(Params[3]);
	sys.Width_Edit->setText(Params[4]);
	sys.Lenght_Edit->setText(Params[5]);
	sys.Weight_Edit->setText(Params[6]);

	Set_Workload();
}

QStringList System_Item::Get_Params()
{
	return Params;
}

void System_Item::Set_Firm()
{
	Params[1] = sys.Firm_Edit->text();
	Set_Workload();
}

void System_Item::Set_Seria()
{
	Params[2] = sys.Seria_Edit->text();
	Set_Workload();
}

void System_Item::Set_Height()
{
	Params[3] = sys.Height_Edit->text();
	Set_Workload();
}

void System_Item::Set_Width()
{
	Params[4] = sys.Width_Edit->text();
	Set_Workload();
}

void System_Item::Set_Lenght()
{
	Params[5] = sys.Lenght_Edit->text();
	Set_Workload();
}

void System_Item::Set_Weidh()
{
	Params[6] = sys.Weight_Edit->text();
	Set_Workload();
}

void System_Item::Set_Workload()
{
	sys.Workload_Bar->setValue(rand() % 101);
	Status_Color();
}

void System_Item::Status_Color()
{
	sys.Item_Name->setStyleSheet("color: rgb(10, 10, 10);\n"
								"text-align: bottom;\n"
								"background-color: rgb(" + QString::number(84 + sys.Workload_Bar->value())
								+ ", " + QString::number(204 - sys.Workload_Bar->value()) + ", 83);");
	
	sys.Workload_Bar->setStyleSheet("QProgressBar\n"
		"{\n"
		"background-color: rgb(255, 255, 255);\n"
		"}\n"
		"QProgressBar::chunk\n"
		"{\n"
		"background-color: rgb(" + QString::number(84 + sys.Workload_Bar->value()) + ", " + QString::number(204 - sys.Workload_Bar->value()) + ", 83);\n"
		"}\n");
}

void System_Item::Info()
{
	if (sys.Info->isHidden()) {
		sys.Info->show();
		this->setFixedHeight(200);
	}
	else {
		sys.Info->hide();
		this->setFixedHeight(25);
	}
}

