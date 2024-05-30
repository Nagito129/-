#pragma once

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>

class Wall_Sample :
    public QGraphicsItem
{
public:
    Wall_Sample(qreal Length, qreal Width);
    Wall_Sample();

    void Set_Mode(int Mode);
    bool Get_Delete_Flag();
    bool Spawn_Accept();
    int Get_Length();
    int Get_Width();

protected:
    QRectF boundingRect() const override;
    void paint(QPainter* Painter, const QStyleOptionGraphicsItem* Option, QWidget* Widget) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* Event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* Event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* Event) override;
    void hoverMoveEvent(QGraphicsSceneHoverEvent* Event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* Event) override;

private:
    enum Mods {
        OFF = 0,
        MOVE = 1,
        SIZE = 2,
        DELETE = 3,
        SPAWN = 4
    };
    
    enum Edges {
        NOTHING = 0,
        TOP = 1,
        BOT = 2,
        LEFT = 3,
        RIGHT = 4,
    };

    qreal Length = 100,
        Old_Length = Length,
        Width = 50,
        Old_Width = Width,
        Min_Size = 25;
    QPointF Return_Position;
    QColor Default_Color, 
        Coliding_Color,
        Object_Color;
    Mods Mode = SPAWN;
    Edges Edge = NOTHING;
    bool Delete_Flag = false;

    bool Check_Coliding();
    void Set_Obj_Color(QColor Color);
};

