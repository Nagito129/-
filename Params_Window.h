/**
 * @file Params_Window.h
 * @brief ���������� ������ Params_Window ��� ������ � ����� ����������
 */

#pragma once

#include <QDialog>
#include <QValidator>
#include <QMessageBox>
#include "ui_Params_Window.h"

 /**
  * @brief ����� ��� ������ � ����� ����������
  */
class Params_Window : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief ����������� ������ Params_Window
     * @param parent ������������ ������
     */
    Params_Window(QWidget* parent = nullptr);

    /**
     * @brief ���������� ������ Params_Window
     */
    ~Params_Window();

    /**
     * @brief ��������� ����������
     * @return ������ ����������
     */
    QStringList Get_Params();

private:
    Ui::Params_WindowClass _ui; ///< ��������� ����

    QStringList Params; ///< ���������

public slots:
    /**
     * @brief ��������� ����������
     */
    void Set_Params();
};
