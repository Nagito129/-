#include "Sofa_Sample.h"
#include <iostream>

Sofa_Sample::Sofa_Sample()
{
    srand(time(0));
    Color = QColor(rand() % 215 + 40, rand() % 215 + 40, rand() % 215 + 40);
}

Sofa_Sample::Sofa_Sample(qreal Size, qreal Angle, QColor Color) {
    this->Size = Size;
    this->Angle = Angle;
    this->Color = Color;
    this->setRotation(Angle);
    this->setScale(Size);
}

QString Sofa_Sample::Get_Size()
{
    return QString::number(Size);
}

QString Sofa_Sample::Get_Angle()
{
    return QString::number(Angle);
}

QString Sofa_Sample::Get_Color()
{
    return QString::number(qRed(Color.rgb())) + "," + QString::number(qGreen(Color.rgb())) + "," + QString::number(qBlue(Color.rgb()));
}

QRectF Sofa_Sample::boundingRect() const
{
    return QRectF(-47.5, -95, 95, 190);
}

void Sofa_Sample::paint(QPainter* Painter, const QStyleOptionGraphicsItem* Option, QWidget* Widget)
{
    Painter->setBrush(QBrush(Color));
    Painter->drawRect(-26.5, -75, 75, 150);

    Painter->setBrush(QBrush(QColor(255, 255, 255, 100)));
    Painter->drawRect(-26.5, -75, 75, 150);

    Painter->setBrush(QBrush(Color));
    Painter->drawRect(-36.5, -95, 65, 20);
    Painter->drawRect(-36.5, 75, 65, 20);
    Painter->drawRect(-47.5, -85, 20, 170);
    
    Q_UNUSED(Option)
    Q_UNUSED(Widget)
}

void Sofa_Sample::mouseMoveEvent(QGraphicsSceneMouseEvent* Event)
{
    if (scene()->collidingItems(this).isEmpty()) {
        this->setPos(mapToScene(Event->pos()));
    }
}

void Sofa_Sample::mousePressEvent(QGraphicsSceneMouseEvent* Event)
{
    Return_Position = this->pos();
    Mode = SIZE;
    this->setCursor(QCursor(QPixmap("Custom_Cursors/Size_Mode_Cursor.png")));
    Q_UNUSED(Event);
}

void Sofa_Sample::mouseReleaseEvent(QGraphicsSceneMouseEvent* Event)
{
    Mode = ROTATE;
    this->setCursor(QCursor(Qt::ArrowCursor));
    
    if (!scene()->collidingItems(this).isEmpty()) {
        this->setPos(Return_Position);
    }
    
    Q_UNUSED(Event);
}

void Sofa_Sample::wheelEvent(QGraphicsSceneWheelEvent* Event)
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

    else if (Mode == SIZE){
        if (Event->delta() > 0 && Size <=1.2) {
            this->setScale(Size += 0.05);
            if (!scene()->collidingItems(this).isEmpty()) {
                this->setScale(Size -= 0.05);
            }
        }
        if (Event->delta() < 0 && Size >= 0.8){
            this->setScale(Size -= 0.05);
        }
    }

}


