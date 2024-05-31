/**
 * @file Window_Sample.h
 * @brief Объявление класса Window_Sample для работы с образцом окна
 */

#pragma once

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>

/**
  * @brief Класс для работы с образцом окна
  */
class Window_Sample : public QGraphicsItem
{
public:
    /**
     * @brief Конструктор класса Window_Sample
     * @param Length Длина образца
     * @param Width Ширина образца
     */
    Window_Sample(qreal Length, qreal Width);

    /**
     * @brief Конструктор класса Window_Sample без параметров
     */
    Window_Sample();

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
     * @brief Проверка возможности размещения образца
     * @return Возможность размещения образца
     */
    bool Spawn_Accept();

    /**
     * @brief Получение длины образца
     * @return Длина образца
     */
    int Get_Length();

    /**
     * @brief Получение ширины образца
     * @return Ширина образца
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

    qreal Length = 100, ///< Длина образца
        Old_Length = Length, ///< Старая длина образца
        Width = 30, ///< Ширина образца
        Old_Width = Width, ///< Старая ширина образца
        Min_Size = 25; ///< Минимальный размер
    QPointF Return_Position; ///< Позиция возврата
    QColor Default_Color, ///< Цвет по умолчанию
        Coliding_Color, ///< Цвет столкновения
        Object_Color; ///< Цвет объекта
    Mods Mode = SPAWN; ///< Режим работы
    Edges Edge = NOTHING; ///< Границы
    bool Delete_Flag = false; ///< Флаг удаления

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
