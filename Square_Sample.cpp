#include "Square_Sample.h"

Square_Sample::Square_Sample(QString Name, qreal Lenght, qreal Width, qreal Angle, qreal X, qreal Y)
{
	this->Name = Name;
	this->Lenght = Lenght;
	this->Width = Width;
	this->Angle = Angle;
	this->X = X;
	this->Y = Y;
	
}

Square_Sample::Square_Sample(QString Name, qreal Lenght, qreal Width)
{
	this->Name = Name;
	this->Lenght = Lenght;
	this->Width = Width;
	this->Workload_Status = Workload_Status;
}


void Square_Sample::Set_Workload(QColor Color, qreal Workload)
{
	Color_Status = Color;
	Workload_Status = Workload;
	update(boundingRect());
}



QRectF Square_Sample::boundingRect() const
{
	return QRectF(0 - Lenght / 2, 0 - Width / 2, Lenght, Width);
}

void Square_Sample::paint(QPainter* Painter, const QStyleOptionGraphicsItem* Option, QWidget* Widget)
{
	Painter->setBrush(Color_Status);
	Painter->drawRect(0 - Lenght / 2, 0 - Width / 2, Lenght, Width);
}

