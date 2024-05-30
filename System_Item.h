/**
 * @file System_Item.h
 * @brief Объявление класса System_Item для работы с элементами системы
 */

#pragma once

#include <QWidget>
#include "ui_System_Item.h"
#include "Square_Sample.h"
#include "Circle_Sample.h"

 /**
  * @brief Класс для работы с элементами системы
  */
class System_Item : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса System_Item
     * @param parent Родительский виджет
     */
    System_Item(QWidget* parent = nullptr);

    /**
     * @brief Деструктор класса System_Item
     */
    ~System_Item();

    /**
     * @brief Установка параметров элемента
     * @param Params Параметры
     * @param Icon Иконка
     */
    void Set_Params(QStringList Params, QString Icon);

    /**
     * @brief Установка параметров элемента с углом
     * @param Params Параметры
     * @param Icon Иконка
     * @param Angle Угол
     */
    void Set_Params(QStringList Params, QString Icon, int Angle);

    /**
     * @brief Получение параметров элемента
     * @return Параметры
     */
    QStringList Get_Params();

    /**
     * @brief Установка позиции элемента
     * @param x Координата x
     * @param y Координата y
     */
    void Set_Position(qreal x, qreal y);

    /**
     * @brief Установка режима работы
     * @param Mode Режим работы
     */
    void Set_Mode(int Mode);

    /**
     * @brief Получение флага удаления
     * @return Флаг удаления
     */
    bool Get_Delete_Flag();

    /**
     * @brief Флаг определения квадрата
     */
    bool is_Square = true;

    /**
     * @brief Цвет элемента
     */
    QColor Color;

    /**
     * @brief Загрузка элемента
     */
    qreal Workload;

    /**
     * @brief Образец квадрата
     */
    Square_Sample* Square;

    /**
     * @brief Образец круга
     */
    Circle_Sample* Circle;

private:
    QStringList Params; ///< Параметры
    Ui::Sistem_Item sys; ///< Интерфейс
    void Status_Color(); ///< Цвет статуса
    void Set_Workload(); ///< Установка загрузки

public slots:
    void Set_Firm();
    void Set_Seria();
    void Set_Weidh();
    void Info();
};

