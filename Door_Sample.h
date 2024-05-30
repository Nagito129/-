/**
 * @file Door_Sample.h
 * @brief ���������� ������ Door_Sample ��� ������ � ��������� ������
 */

#pragma once

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>

 /**
  * @brief ����� ��� ������ � ��������� ������
  */
class Door_Sample :
    public QGraphicsItem
{
public:
    /**
     * @brief ����������� ������ Door_Sample � ����������� ����� � ������
     * @param Length ����� �����
     * @param Width ������ �����
     */
    Door_Sample(qreal Length, qreal Width);

    /**
     * @brief ����������� ������ Door_Sample ��� ����������
     */
    Door_Sample();

    /**
     * @brief ��������� ������ ������ ��� �������
     * @param Mode ����� ������: 0 - OFF, 1 - MOVE, 2 - SIZE, 3 - DELETE, 4 - SPAWN
     */
    void Set_Mode(int Mode);

    /**
     * @brief ��������� ����� �������� �������
     * @return true, ���� ������ ������ ���� ������, ����� - false
     */
    bool Get_Delete_Flag();

    /**
     * @brief �������� ����������� ���������� ������� �� �����
     * @return true, ���� ������ ����� ���� ��������, ����� - false
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
    /**
     * @brief ��������� ��������������� �������������� �������
     * @return �������������� �������������
     */
    QRectF boundingRect() const override;

    /**
     * @brief ��������� �������
     * @param Painter ������ ��� ���������
     * @param Option ����� �����
     * @param Widget ������
     */
    void paint(QPainter* Painter, const QStyleOptionGraphicsItem* Option, QWidget* Widget) override;

    /**
     * @brief ��������� ������� ����������� ����
     * @param Event ������� ����������� ����
     */
    void mouseMoveEvent(QGraphicsSceneMouseEvent* Event) override;

    /**
     * @brief ��������� ������� ������� ����
     * @param Event ������� ������� ����
     */
    void mousePressEvent(QGraphicsSceneMouseEvent* Event) override;

    /**
     * @brief ��������� ������� ���������� ����
     * @param Event ������� ���������� ����
     */
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* Event) override;

    /**
     * @brief ��������� ������� ����������� ��������� ���� ��� ��������
     * @param Event ������� ����������� ��������� ����
     */
    void hoverMoveEvent(QGraphicsSceneHoverEvent* Event) override;

    /**
     * @brief ��������� ������� ����� ��������� ���� � �������
     * @param Event ������� ����� ��������� ����
     */
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* Event) override;

private:
    /**
     * @brief ������������ ������� ������ �������
     */
    enum Mods {
        OFF = 0, ///< ��������
        MOVE = 1, ///< �����������
        SIZE = 2, ///< ��������� �������
        DELETE = 3, ///< ��������
        SPAWN = 4 ///< ��������
    };

    /**
     * @brief ������������ ������ �������
     */
    enum Edges {
        NOTHING = 0, ///< ��� �������
        TOP = 1, ///< ������� �������
        BOT = 2, ///< ������ �������
        LEFT = 3, ///< ����� �������
        RIGHT = 4, ///< ������ �������
    };

    qreal Length = 100, ///< ����� �����
        Old_Length = Length, ///< ���������� ����� �����
        Width = 30, ///< ������ �����
        Old_Width = Width, ///< ���������� ������ �����
        Min_Size = 25; ///< ����������� ������ �����
    QPointF Return_Position; ///< ������� �������� �������
    QColor Default_Color, ///< ���� ������� �� ���������
        Coliding_Color, ///< ���� ��� ��������
        Object_Color; ///< ���� �������
    Mods Mode = SPAWN; ///< ����� ������ �������
    Edges Edge = NOTHING; ///< ������� �������
    bool Delete_Flag = false; ///< ���� �������� �������

    /**
     * @brief �������� ������� ��������
     * @return true, ���� ���� ��������, ����� - false
     */
    bool Check_Coliding();

    /**
     * @brief ��������� ����� �������
     * @param Color ���� �������
     */
    void Set_Obj_Color(QColor Color);
};
