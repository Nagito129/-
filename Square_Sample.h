/**
 * @file Square_Sample.h
 * @brief Объявление класса Square_Sample для работы с квадратным образцом
 */

#pragma once

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>

/**
  * @brief Класс для работы с квадратным образцом
  */
class Square_Sample : public QGraphicsItem
{
public:
    /**
     * @brief Конструктор класса Square_Sample
     * @param Name Название образца
     * @param Length Длина образца
     * @param Width Ширина образца
     * @param Angle Угол поворота образца
     */
    Square_Sample(QString Name, qreal Length, qreal Width, qreal Angle);

    /**
     * @brief Конструктор класса Square_Sample
     * @param Name Название образца
     * @param Length Длина образца
     * @param Width Ширина образца
     */
    Square_Sample(QString Name, qreal Length, qreal Width);

    /**
     * @brief Установка цвета и загрузки образца
     * @param Color Цвет загрузки
     * @param Workload Загрузка
     */
    void Set_Workload(QColor Color, qreal Workload);

    /**
     * @brief Проверка возможности размещения образца
     * @return Возможность размещения образца
     */
    bool Spawn_Accept();

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
     * @brief Получение угла поворота
     * @return Угол поворота
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

    Mods Mode = SPAWN; ///< Режим работы

    QString Name; ///< Название образца
    qreal Length, ///< Длина образца
        Width, ///< Ширина образца
        Angle = 0, ///< Угол поворота
        Workload_Status; ///< Загрузка

    QColor Color_Status, ///< Цвет загрузки
        Coliding_Color, ///< Цвет столкновения
        Object_Color; ///< Цвет объекта

    bool Delete_Flag = false; ///< Флаг удаления
    QPointF Return_Position; ///< Позиция возврата

    /**
     * @brief Проверка столкновений
     * @return Результат проверки столкновений
     */
    bool Check_Coliding();

    /**
     * @brief Установка цвета объекта
     * @param Color Цвет
     */
    void Set_Obj_Color(QColor Color);
};

