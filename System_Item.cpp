#include "System_Item.h"

System_Item::System_Item(QWidget* parent)
	: QWidget(parent)
{
	sys.setupUi(this);
	sys.Info->hide();
	sys.Position->hide();
	this->setFixedSize(300, 25);
	

	connect(sys.Item_Name, SIGNAL(pressed()), this, SLOT(Info()));
	connect(sys.Firm_Edit, SIGNAL(returnPressed()), this, SLOT(Set_Firm()));
	connect(sys.Seria_Edit, SIGNAL(returnPressed()), this, SLOT(Set_Seria()));
	connect(sys.Weight_Edit, SIGNAL(returnPressed()), this, SLOT(Set_Weidh()));
}

System_Item::~System_Item()
{
	if (is_Square) {
		delete Square;
	}
	else {
		delete Circle;
	}
}



void System_Item::Set_Params(QStringList Params, QString Icon)
{
	this->Params = Params;
	sys.Item_Name->setText(Params[0]);
	sys.Item_Name->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	sys.Item_Name->setIcon(QIcon("Textures/Icons/Tools Icons/" + Icon));
	sys.Firm_Edit->setText(Params[1]);
	sys.Seria_Edit->setText(Params[2]);
	sys.Height_L->setText(Params[3]);
	sys.Width_L->setText(Params[4]);
	sys.Lenght_L->setText(Params[5]);
	sys.Weight_Edit->setText(Params[6]);
	sys.X_pos->setText(Params[7]);
	sys.Y_pos->setText(Params[8]);
	
	if (is_Square) {
		Square = new Square_Sample(Params[0], Params[5].toFloat(), Params[4].toFloat());
	}
	else {
		Circle = new Circle_Sample(Params[0], Params[5].toFloat(), Params[4].toFloat());
	}
	Set_Workload();
}

QStringList System_Item::Get_Params()
{
	return Params;
}

void System_Item::Set_Position(qreal x, qreal y)
{
	sys.X_pos->setText(QString::number(x));
	sys.Y_pos->setText(QString::number(y));
}

void System_Item::Set_Mode(int Mode)
{
	if (is_Square) {
		Square->Set_Mode(Mode);
	}
	else
	{
		Circle->Set_Mode(Mode);
	}
}

bool System_Item::Get_Delete_Flag()
{
	if (is_Square) {
		return Square->Get_Delete_Flag();
	}
	else {
		return Circle->Get_Delete_Flag();
	}
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

void System_Item::Set_Weidh()
{
	Params[6] = sys.Weight_Edit->text();
	Set_Workload();
}

void System_Item::Set_Workload()
{
	sys.Workload_Bar->setValue(rand() % 101);
	Workload = sys.Workload_Bar->value();
	Status_Color();
	if (is_Square) {
		Square->Set_Workload(Color, Workload);
	}
	else {
		Circle->Set_Workload(Color, Workload);
	}
}

void System_Item::Status_Color()
{
	Color.setRgb(84 + Workload, 204 - Workload, 83);
	sys.Item_Name->setStyleSheet("color: rgb(10, 10, 10);\n"
								"text-align: bottom;\n"
								"background-color: rgb(" + QString::number(qRed(Color.rgb()))
								+ ", " + QString::number(qGreen(Color.rgb())) + ", 83);");
	
	sys.Workload_Bar->setStyleSheet("QProgressBar\n"
		"{\n"
		"background-color: rgb(255, 255, 255);\n"
		"}\n"
		"QProgressBar::chunk\n"
		"{\n"
		"background-color: rgb(" + QString::number(qRed(Color.rgb()))
		+ ", " + QString::number(qGreen(Color.rgb())) + ", 83);\n"
		"}\n");
}

void System_Item::Info()
{
	if (sys.Info->isHidden()) {
		sys.Info->show();
		sys.Position->show();
		this->setFixedHeight(275);
	}
	else {
		sys.Info->hide();
		sys.Position->hide();
		this->setFixedHeight(25);
	}
}

