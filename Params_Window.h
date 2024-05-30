/**
 * @file Params_Window.h
 * @brief Объявление класса Params_Window для работы с окном параметров
 */

#pragma once

#include <QDialog>
#include <QValidator>
#include <QMessageBox>
#include "ui_Params_Window.h"

 /**
  * @brief Класс для работы с окном параметров
  */
class Params_Window : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса Params_Window
     * @param parent Родительский виджет
     */
    Params_Window(QWidget* parent = nullptr);

    /**
     * @brief Деструктор класса Params_Window
     */
    ~Params_Window();

    /**
     * @brief Получение параметров
     * @return Список параметров
     */
    QStringList Get_Params();

private:
    Ui::Params_WindowClass _ui; ///< Интерфейс окна

    QStringList Params; ///< Параметры

public slots:
    /**
     * @brief Установка параметров
     */
    void Set_Params();
};
