/**
 * @file Circle_Sample.h
 * @brief ���������� ������ Circle_Sample ��� ������ � ��������� ���������
 */

#pragma once
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPaintEvent>
#include <QGraphicsSceneMouseEvent>

 /**
  * @brief ����� ��� ������ � ��������� ���������
  */
class Circle_Sample :
    public QGraphicsItem
{
public:
    /**
  * @brief ����������� ������ Circle_Sample � ����������� �����, �����, ������ � ����
  * @param Name ��� �������
  * @param Length �����
  * @param Width ������
  * @param Angle ���� ��������
  */
    Circle_Sample(QString Name, qreal Length, qreal Width, qreal Angle);

    /**
    * @brief ����������� ������ Circle_Sample � ����������� �����, ����� � ������
    * @param Name ��� �������
    * @param Length �����
    * @param Width ������
    */
    Circle_Sample(QString Name, qreal Length, qreal Width);

    /**
    * @brief ��������� ����� � ������ ��������
    * @param Color ����
    * @param Workload ������� ��������
    */
    void Set_Workload(QColor Color, qreal Workload);

    /**
    * @brief �������� ����������� ���������� ������� �� �����
    * @return true, ���� ������ ����� ���� ��������, ����� - false
    */
    bool Spawn_Accept();

    /**
     * @brief ��������� ������ ������ ��� �������
     * @param Mode ����� ������: 0 - OFF, 1 - MOVE, 2 - SPAWN, 3 - DELETE
     */
    void Set_Mode(int Mode);

    /**
     * @brief ��������� ����� �������� �������
     * @return true, ���� ������ ������ ���� ������, ����� - false
     */
    bool Get_Delete_Flag();

    /**
    * @brief ��������� ���� �������� �������
    * @return ���� �������� �������
    */
    int Get_Angle();

protected:

    /**
     * @brief ��������� ��������������� �������������� �������
     * @return �������������� �������������
     */
    QRectF boundingRect() const override;

    /**
   * @brief ��������� ����� �������
   * @return ����, �������� ����� �������
   */
    QPainterPath shape() const override;

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
     * @brief ��������� ������� �������� ������ ����
     * @param Event ������� �������� ������ ����
     */
    void wheelEvent(QGraphicsSceneWheelEvent* Event) override;

private:

    /**
     * @brief ������������ ������� ������ �������
     */
    enum Mods {
        OFF = 0, ///< ��������
        MOVE = 1, ///< �����������
        SPAWN = 2, ///< ��������
        DELETE = 3 ///< ��������
    };

    Mods Mode = SPAWN; ///< ����� ������ �������
    QString Name; ///< ��� �������
    qreal Length, ///< ����� �������
        Width, ///< ������ �������
        Angle = 0, ///< ���� �������� �������
        Workload_Status; ///< ������� �������� �������
    QColor Color_Status, ///< ���� �������
        Coliding_Color, ///< ���� ��� ��������
        Object_Color; ///< ���� �������
    bool Delete_Flag = false; ///< ���� �������� �������
    QPointF Return_Position; ///< ������� �������� �������

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