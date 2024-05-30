/**
 * @file Square_Sample.h
 * @brief ���������� ������ Square_Sample ��� ������ � ���������� ��������
 */

#pragma once

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>

 /**
  * @brief ����� ��� ������ � ���������� ��������
  */
class Square_Sample : public QGraphicsItem
{
public:
    /**
     * @brief ����������� ������ Square_Sample
     * @param Name �������� �������
     * @param Length ����� �������
     * @param Width ������ �������
     * @param Angle ���� �������� �������
     */
    Square_Sample(QString Name, qreal Length, qreal Width, qreal Angle);

    /**
     * @brief ����������� ������ Square_Sample
     * @param Name �������� �������
     * @param Length ����� �������
     * @param Width ������ �������
     */
    Square_Sample(QString Name, qreal Length, qreal Width);

    /**
     * @brief ��������� ����� � �������� �������
     * @param Color ���� ��������
     * @param Workload ��������
     */
    void Set_Workload(QColor Color, qreal Workload);

    /**
     * @brief �������� ����������� ���������� �������
     * @return ����������� ���������� �������
     */
    bool Spawn_Accept();

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
     * @brief ��������� ���� ��������
     * @return ���� ��������
     */
    int Get_Angle();

protected:
    QRectF boundingRect() const override;
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

    Mods Mode = SPAWN; ///< ����� ������

    QString Name; ///< �������� �������
    qreal Length, ///< ����� �������
        Width, ///< ������ �������
        Angle = 0, ///< ���� ��������
        Workload_Status; ///< ��������

    QColor Color_Status, ///< ���� ��������
        Coliding_Color, ///< ���� ������������
        Object_Color; ///< ���� �������

    bool Delete_Flag = false; ///< ���� ��������
    QPointF Return_Position; ///< ������� ��������

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

