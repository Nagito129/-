#pragma once
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPaintEvent>
#include <QGraphicsSceneMouseEvent>

class Circle_Sample :
    public QGraphicsItem
{
public:
    Circle_Sample(QString Name, qreal Lenght, qreal Width, qreal Angle);
    Circle_Sample(QString Name, qreal Lenght, qreal Width);

    void Set_Workload(QColor Color, qreal Workload);

    bool Spawn_Accept();
    void Set_Mode(int Mode);
    bool Get_Delete_Flag();

protected:
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter* Painter, const QStyleOptionGraphicsItem* Option, QWidget* Widget) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* Event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* Event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* Event) override;
    void wheelEvent(QGraphicsSceneWheelEvent* Event) override;

private:
    enum Mods {
        OFF = 0,
        MOVE = 1,
        SPAWN = 2,
        DELETE = 3
    };

    Mods Mode = SPAWN;

    QString Name;
    qreal Lenght,
        Width,
        Angle = 0,
        Workload_Status;

    QColor Color_Status,
        Coliding_Color,
        Object_Color;
    bool Delete_Flag = false;
    QPointF Return_Position;

    bool Check_Coliding();
    void Set_Obj_Color(QColor Color);
};