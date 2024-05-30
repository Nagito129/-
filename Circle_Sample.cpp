#include "Circle_Sample.h"

Circle_Sample::Circle_Sample(QString Name, qreal Lenght, qreal Width, qreal Angle)
{
	this->Name = Name;
	this->Lenght = Lenght;
	this->Width = Width;
	this->Angle = Angle;
	Coliding_Color.setRgb(210, 20, 20);
}

Circle_Sample::Circle_Sample(QString Name, qreal Lenght, qreal Width)
{
	this->Name = Name;
	this->Lenght = Lenght;
	this->Width = Width;
	Coliding_Color.setRgb(210, 20, 20);
	Coliding_Color.setAlpha(140);
}

void Circle_Sample::Set_Workload(QColor Color, qreal Workload)
{
	Color_Status = Color;
	Workload_Status = Workload;
	Set_Obj_Color(Color_Status);
}

bool Circle_Sample::Spawn_Accept()
{
	if (scene()->collidingItems(this).isEmpty()) {
		Mode = OFF;
		Color_Status.setAlpha(255);
		Set_Obj_Color(Color_Status);
		return true;
	}
	else {
		return false;
	}
}

void Circle_Sample::Set_Mode(int Mode)
{
	if (Mode == 0) {
		this->Mode = OFF;
	}
	else if (Mode == 1) {
		this->Mode = MOVE;
	}
	else if (Mode == 3) {
		this->Mode = DELETE;
	}
}

bool Circle_Sample::Get_Delete_Flag()
{
	return Delete_Flag;
}

QRectF Circle_Sample::boundingRect() const
{
	return shape().boundingRect();
}

QPainterPath Circle_Sample::shape() const
{
	QPainterPath Circle;
	Circle.addEllipse(0 - Lenght / 2, 0 - Width / 2, Lenght, Width);
	return Circle;
}

void Circle_Sample::paint(QPainter* Painter, const QStyleOptionGraphicsItem* Option, QWidget* Widget)
{
	if (Mode == SPAWN) {
		Object_Color.setAlpha(140);
	}
	Painter->setBrush(Object_Color);
	Painter->drawEllipse(0 - Lenght / 2, 0 - Width / 2, Lenght, Width);
}

void Circle_Sample::mouseMoveEvent(QGraphicsSceneMouseEvent* Event)
{	
	if (Mode == SPAWN || Mode == MOVE) {
		this->setPos(mapToScene(Event->pos()));
		Check_Coliding();
	}


}

void Circle_Sample::mousePressEvent(QGraphicsSceneMouseEvent* Event)
{
	if (Mode == MOVE) {
		this->setZValue(1);
		Return_Position = this->pos();

		Object_Color.setAlpha(140);
		update();
	}

	else if (Mode == DELETE) {
		if (Delete_Flag == false) {
			Delete_Flag = true;
			Object_Color.setRgb(59, 106, 171);
			this->setScale(1.05);
		}
		else {
			Delete_Flag = false;
			Object_Color = Color_Status;
			this->setScale(1);
		}
	}
	Q_UNUSED(Event);
}

void Circle_Sample::mouseReleaseEvent(QGraphicsSceneMouseEvent* Event)
{
	if (Mode == MOVE) {
		this->setZValue(0);

		if (Check_Coliding()) {
			this->setPos(Return_Position);
		}
		Object_Color = Color_Status;
		Object_Color.setAlpha(255);
		update();
	}
	Q_UNUSED(Event);
}

void Circle_Sample::wheelEvent(QGraphicsSceneWheelEvent* Event)
{
	if (Mode == SPAWN || Mode == MOVE) {
		if (Event->delta() > 0) {
			this->setRotation(Angle += 15);
		}
		else {
			this->setRotation(Angle -= 15);
		}
		Check_Coliding();
	}
}

void Circle_Sample::Set_Obj_Color(QColor Color)
{
	Object_Color = Color;
	update(boundingRect());
}

bool Circle_Sample::Check_Coliding()
{
	if (scene()->collidingItems(this).isEmpty()) {
		Color_Status.setAlpha(140);
		Set_Obj_Color(Color_Status);
		return false;
	}

	else {
		Set_Obj_Color(Coliding_Color);
		return true;
	}
}

