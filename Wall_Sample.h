/**
 * @file Wall_Sample.h
 * @brief ���������� ������ Wall_Sample ��� ������ � �������� �����
 */

#pragma once

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>

 /**
  * @brief ����� ��� ������ � �������� �����
  */
class Wall_Sample : public QGraphicsItem
{
public:
    /**
     * @brief ����������� ������ Wall_Sample
     * @param Length ����� �������
     * @param Width ������ �������
     */
    Wall_Sample(qreal Length, qreal Width);

    /**
     * @brief ����������� ������ Wall_Sample ��� ����������
     */
    Wall_Sample();

    /**
     * @brief ��������� ������ ������
     * @param Mode ����� ������
     */
    void Set_Mode(int Mode);

    /**
     * @brief ��������� ����� ��������
     * @return ���� ��������
     */
    bool Get_Delete_Flag();

    /**
     * @brief �������� ����������� ���������� �������
     * @return ����������� ���������� �������
     */
    bool Spawn_Accept();

    /**
     * @brief ��������� ����� �������
     * @return ����� �������
     */
    int Get_Length();

    /**
     * @brief ��������� ������ �������
     * @return ������ �������
     */
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

    qreal Length = 100, ///< ����� �������
        Old_Length = Length, ///< ������ ����� �������
        Width = 50, ///< ������ �������
        Old_Width = Width, ///< ������ ������ �������
        Min_Size = 25; ///< ����������� ������
    QPointF Return_Position; ///< ������� ��������
    QColor Default_Color, ///< ���� �� ���������
        Coliding_Color, ///< ���� ������������
        Object_Color; ///< ���� �������
    Mods Mode = SPAWN; ///< ����� ������
    Edges Edge = NOTHING; ///< �������
    bool Delete_Flag = false; ///< ���� ��������

    /**
     * @brief �������� ������������
     * @return ��������� �������� ������������
     */
    bool Check_Coliding();

    /**
     * @brief ��������� ����� �������
     * @param Color ����
     */
    void Set_Obj_Color(QColor Color);
};