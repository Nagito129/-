#include "Chair_Sample.h"

Chair_Sample::Chair_Sample()
{
	srand(time(0));
	Alpha_Color = QColor(255, 255, 255, rand() % 50);
	Color_2 = QColor(rand() % 215 + 40, rand() % 215 + 40, rand() % 215 + 40);
}

Chair_Sample::Chair_Sample(qreal Size, QColor Alpha_Color, QColor Color_2)
{
	this->Size = Size;
	this->Alpha_Color = Alpha_Color;
	this->Color_2 = Color_2;
	this->setScale(Size);
}

QString Chair_Sample::Get_Size()
{
	return QString::number(Size);
}

QString Chair_Sample::Get_Alpha()
{
	return QString::number(qAlpha(Alpha_Color.rgba()));
}

QString Chair_Sample::Get_Color()
{
	return QString::number(qRed(Color_2.rgb())) + "," + QString::number(qGreen(Color_2.rgb())) + "," + QString::number(qBlue(Color_2.rgb()));
}

QRectF Chair_Sample::boundingRect() const
{
	return QRectF(-20, -20, 40, 40);
}

void Chair_Sample::paint(QPainter* Painter, const QStyleOptionGraphicsItem* Option, QWidget* Widget)
{
	Painter->setBrush(Color_1);
	Painter->drawEllipse(-20, -20, 40, 40);
	Painter->setBrush(Alpha_Color);
	Painter->drawEllipse(-20, -20, 40, 40);
	Painter->setBrush(Color_2);
	Painter->drawEllipse(-15, -15, 30, 30);

	Q_UNUSED(Option)
	Q_UNUSED(Widget)
}

void Chair_Sample::mouseMoveEvent(QGraphicsSceneMouseEvent* Event)
{
	if (scene()->collidingItems(this).isEmpty()) {
		this->setPos(mapToScene(Event->pos()));
	}
}

void Chair_Sample::mousePressEvent(QGraphicsSceneMouseEvent* Event)
{
	Return_Position = this->pos();
	this->setCursor(QCursor(QPixmap("Custom_Cursors/Size_Mode_Cursor.png")));
	Q_UNUSED(Event);
}

void Chair_Sample::mouseReleaseEvent(QGraphicsSceneMouseEvent* Event)
{
	this->setCursor(QCursor(Qt::ArrowCursor));

	if (!scene()->collidingItems(this).isEmpty()) {
		this->setPos(Return_Position);
	}
}

void Chair_Sample::wheelEvent(QGraphicsSceneWheelEvent* Event)
{
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
