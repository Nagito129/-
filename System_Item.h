/**
 * @file System_Item.h
 * @brief ���������� ������ System_Item ��� ������ � ���������� �������
 */

#pragma once

#include <QWidget>
#include "ui_System_Item.h"
#include "Square_Sample.h"
#include "Circle_Sample.h"

 /**
  * @brief ����� ��� ������ � ���������� �������
  */
class System_Item : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief ����������� ������ System_Item
     * @param parent ������������ ������
     */
    System_Item(QWidget* parent = nullptr);

    /**
     * @brief ���������� ������ System_Item
     */
    ~System_Item();

    /**
     * @brief ��������� ���������� ��������
     * @param Params ���������
     * @param Icon ������
     */
    void Set_Params(QStringList Params, QString Icon);

    /**
     * @brief ��������� ���������� �������� � �����
     * @param Params ���������
     * @param Icon ������
     * @param Angle ����
     */
    void Set_Params(QStringList Params, QString Icon, int Angle);

    /**
     * @brief ��������� ���������� ��������
     * @return ���������
     */
    QStringList Get_Params();

    /**
     * @brief ��������� ������� ��������
     * @param x ���������� x
     * @param y ���������� y
     */
    void Set_Position(qreal x, qreal y);

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
     * @brief ���� ����������� ��������
     */
    bool is_Square = true;

    /**
     * @brief ���� ��������
     */
    QColor Color;

    /**
     * @brief �������� ��������
     */
    qreal Workload;

    /**
     * @brief ������� ��������
     */
    Square_Sample* Square;

    /**
     * @brief ������� �����
     */
    Circle_Sample* Circle;

private:
    QStringList Params; ///< ���������
    Ui::Sistem_Item sys; ///< ���������
    void Status_Color(); ///< ���� �������
    void Set_Workload(); ///< ��������� ��������

public slots:
    void Set_Firm();
    void Set_Seria();
    void Set_Weidh();
    void Info();
};

