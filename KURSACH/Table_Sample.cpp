#include "Table_Sample.h"

Table_Sample::Table_Sample()
{
	srand(time(0));
	Alpha_Color = QColor(255, 255, 255, rand() % 50);
}

Table_Sample::Table_Sample(qreal Size, qreal Angle, QColor Alpha_Color)
{
	this->Size = Size;
	this->Angle = Angle;
	this->Alpha_Color = Alpha_Color;
	this->setRotation(Angle);
	this->setScale(Size);
}

QString Table_Sample::Get_Size()
{
	return QString::number(Size);
}

QString Table_Sample::Get_Angle()
{
	return QString::number(Angle);
}

QString Table_Sample::Get_Alpha()
{
	return QString::number(qAlpha(Alpha_Color.rgba()));
}

QRectF Table_Sample::boundingRect() const
{
	return QRectF(-100, -50, 200, 100);
}

void Table_Sample::paint(QPainter* Painter, const QStyleOptionGraphicsItem* Option, QWidget* Widget)
{
	Painter->setBrush(Color);
	Painter->drawRect(-100, -50, 200, 100);
	Painter->setBrush(Alpha_Color);
	Painter->drawRect(-100, -50, 200, 100);

	Q_UNUSED(Option)
	Q_UNUSED(Widget)
}

void Table_Sample::mouseMoveEvent(QGraphicsSceneMouseEvent* Event)
{
	if (scene()->collidingItems(this).isEmpty()) {
		this->setPos(mapToScene(Event->pos()));
	}
}

void Table_Sample::mousePressEvent(QGraphicsSceneMouseEvent* Event)
{
	Return_Position = this->pos();
	Mode = SIZE;
	this->setCursor(QCursor(QPixmap("Custom_Cursors/Size_Mode_Cursor.png")));
	Q_UNUSED(Event);
}

void Table_Sample::mouseReleaseEvent(QGraphicsSceneMouseEvent* Event)
{
	Mode = ROTATE;
	this->setCursor(QCursor(Qt::ArrowCursor));

	if (!scene()->collidingItems(this).isEmpty()) {
		this->setPos(Return_Position);
	}

	Q_UNUSED(Event);
}

void Table_Sample::wheelEvent(QGraphicsSceneWheelEvent* Event)
{
	if (Mode == ROTATE) {
		this->setCursor(QCursor(QPixmap("Custom_Cursors/Rotate_Mode_Cursor.png")));
		if (Event->delta() > 0) {
			this->setRotation(Angle += 15);
			if (!scene()->collidingItems(this).isEmpty()) {
				this->setRotation(Angle -= 15);
			}
		}
		else {
			this->setRotation(Angle -= 15);
			if (!scene()->collidingItems(this).isEmpty()) {
				this->setRotation(Angle += 15);
			}
		}
	}

	else if (Mode == SIZE) {
		if (Event->delta() > 0 && Size <= 1.2) {
			this->setScale(Size += 0.05);
			if (!scene()->collidingItems(this).isEmpty()) {
				this->setScale(Size -= 0.05);
			}
		}
		if (Event->delta() < 0 && Size >= 0.8) {
			this->setScale(Size -= 0.05);
		}
	}
}
