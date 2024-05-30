/**
 * @file uchebnayapractika.h
 * @brief ���������� ������ uchebnayapractika ��� ������ � �����������
 */

#pragma once

#include <QtWidgets/QMainWindow>
#include <QScreen>
#include <QFileDialog>
#include <QMessageBox>
#include <QAbstractButton>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>

#include "ui_uchebnayapractika.h"
#include "System_Item.h"
#include "Square_Sample.h"
#include "Params_Window.h"
#include "B_Parts.h"

 /**
  * @brief ����� ��� ������ � �����������
  */
class uchebnayapractika : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief ����������� ������ uchebnayapractika
     * @param parent ������������ ������
     */
    uchebnayapractika(QWidget* parent = nullptr);

    /**
     * @brief ���������� ������ uchebnayapractika
     */
    ~uchebnayapractika();

protected:
    /**
     * @brief ���������� ������� ������� �������
     * @param e ������� ������� �������
     */
    void keyPressEvent(QKeyEvent* e) override;

private:
    Ui::uchebnayapractikaClass ui; ///< ���������

    /**
     * @brief ������������ ������� ������
     */
    enum Mods {
        M_OFF = 0, ///< ���������
        M_ADD = 1, ///< ����������
        M_DELETE = 2, ///< ��������
        M_MOVE = 3, ///< �����������
    };

    /**
     * @brief ������������ ���� ��������� �������
     */
    enum System_Form {
        SQUARE = 0, ///< �������
        CIRCLE = 1 ///< ����
    };

    const QRectF Screen_Geometry = geometry(); ///< ��������� ������
    const qreal Screen_H = Screen_Geometry.height(), ///< ������ ������
        Screen_W = Screen_Geometry.width(); ///< ������ ������
    QString File_Name = ""; ///< ��� �����
    System_Item* Item; ///< ������� �������
    B_Parts* Part; ///< ������
    QGraphicsScene Plan; ///< �����

    QList <System_Item*> Items; ///< ������ ���������
    QList <B_Parts*> Build_Parts; ///< ������ �������

    Mods Mode; ///< �����
    System_Form Form; ///< ����� ��������
    bool is_Build; ///< ������� ����������

    /**
     * @brief ����� ��������� � �������
     * @param isKey ���� ��� ��������� ������������� �����
     */
    void Console_Widget(bool isKey);

    /**
     * @brief ����� ��������� � �������
     * @param String ��������� ��� ������
     */
    void Pout(QString String);

    /**
     * @brief ���������� �������� �������
     * @param Path ����
     * @param Form ����� ��������
     */
    void Add_Sys_Item(QString Path, System_Form Form);

    /**
     * @brief ��������� ������ ������ ��� ��������� � �������
     * @param Mode ����� ������
     */
    void Set_Items_And_Parts_Mode(int Mode);

    /**
     * @brief ������ � ����
     * @param File ���� ��� ������
     */
    void Write_In_File(QFile& File);

public slots:
    void Console_Widget();
    void Info_Widget();
    void Tools_Widget();
    void Add_Widget();

    void Delete_All();
    void Add_Square();
    void Add_Circle();
    void Add_Wall();
    void Add_Window();
    void Add_Door();
    void Add_Stairs();
    void Delete();
    void Move();

    void Open();
    void Save();
};

