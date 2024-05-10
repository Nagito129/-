#include "Armchair_Sample.h"

Armchair_Sample::Armchair_Sample()
{
    srand(time(0));
    Color = QColor(rand() % 215 + 40, rand() % 215 + 40, rand() % 215 + 40);
}

Armchair_Sample::Armchair_Sample(qreal Size, qreal Angle, QColor Color)
{
    this->Size = Size;
    this->Angle = Angle;
    this->Color = Color;
    this->setRotation(Angle);
    this->setScale(Size);
}

QString Armchair_Sample::Get_Size()
{
    return QString::number(Size);
}

QString Armchair_Sample::Get_Angle()
{
    return QString::number(Angle);
}

QString Armchair_Sample::Get_Color()
{
    return QString::number(qRed(Color.rgb())) + "," + QString::number(qGreen(Color.rgb())) + "," + QString::number(qBlue(Color.rgb()));
}

QRectF Armchair_Sample::boundingRect() const
{
	return QRectF(-44, -46, 85, 92);
}

void Armchair_Sample::paint(QPainter* Painter, const QStyleOptionGraphicsItem* Option, QWidget* Widget)
{
    Painter->setBrush(Color);
    Painter->drawRect(-38, -46, 75, 14);
    Painter->drawRect(-38, 32, 75, 14);
    Painter->drawRect(-44, -37, 14, 74);
    Painter->drawRect(-30, -32, 70, 64);

    Painter->setBrush(QColor(255, 255, 255, 128));
    Painter->drawRect(-30, -32, 70, 64);
    

    Q_UNUSED(Option)
    Q_UNUSED(Widget)
}

void Armchair_Sample::mouseMoveEvent(QGraphicsSceneMouseEvent* Event)
{
    if (scene()->collidingItems(this).isEmpty()) {
        this->setPos(mapToScene(Event->pos()));
    }
}

void Armchair_Sample::mousePressEvent(QGraphicsSceneMouseEvent* Event)
{
    Return_Position = this->pos();
    Mode = SIZE;
    this->setCursor(QCursor(QPixmap("Custom_Cursors/Size_Mode_Cursor.png")));
    Q_UNUSED(Event);
}

void Armchair_Sample::mouseReleaseEvent(QGraphicsSceneMouseEvent* Event)
{
    Mode = ROTATE;
    this->setCursor(QCursor(Qt::ArrowCursor));

    if (!scene()->collidingItems(this).isEmpty()) {
        this->setPos(Return_Position);
    }

    Q_UNUSED(Event);
}

void Armchair_Sample::wheelEvent(QGraphicsSceneWheelEvent* Event)
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
