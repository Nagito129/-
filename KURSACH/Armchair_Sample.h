#pragma once
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>

class Armchair_Sample : public QGraphicsItem
{
public:
    Armchair_Sample();
    Armchair_Sample(qreal Size, qreal Angle, QColor Color);

    QString Get_Size();
    QString Get_Angle();
    QString Get_Color();

protected:
    QRectF boundingRect() const override;
    void paint(QPainter* Painter, const QStyleOptionGraphicsItem* Option, QWidget* Widget) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* Event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* Event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* Event) override;
    void wheelEvent(QGraphicsSceneWheelEvent* Event) override;

private:
    enum Mods {
        ROTATE = 0,
        SIZE = 1
    };

    QColor Color;
    qreal Angle = 0,
        Size = 1;
    QPointF Return_Position;

    bool Mode = ROTATE;
};

