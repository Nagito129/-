#pragma once
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>

class Chair_Sample : public QGraphicsItem
{
public:
    Chair_Sample();
    Chair_Sample(qreal Size, QColor Alpha_Color, QColor Color_2);

    QString Get_Size();
    QString Get_Alpha();
    QString Get_Color();


protected:
    QRectF boundingRect() const override;
    void paint(QPainter* Painter, const QStyleOptionGraphicsItem* Option, QWidget* Widget) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* Event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* Event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* Event) override;
    void wheelEvent(QGraphicsSceneWheelEvent* Event) override;

private:
    const QColor Color_1 = QColor(114, 79, 56);
    QColor Alpha_Color, Color_2;
    qreal Size = 1;
    QPointF Return_Position;
};

