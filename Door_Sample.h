/**
 * @file Door_Sample.h
 * @brief Объявление класса Door_Sample для работы с объектами дверей
 */

#pragma once

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>

/**
  * @brief Класс для работы с объектами дверей
  */
class Door_Sample :
                    public QGraphicsItem
{
public:
    /**
     * @brief Конструктор класса Door_Sample с параметрами длины и ширины
     * @param Length Длина двери
     * @param Width Ширина двери
     */
    Door_Sample(qreal Length, qreal Width);

    /**
     * @brief Конструктор класса Door_Sample без параметров
     */
    Door_Sample();

    /**
     * @brief Установка режима работы для объекта
     * @param Mode Режим работы: 0 - OFF, 1 - MOVE, 2 - SIZE, 3 - DELETE, 4 - SPAWN
     */
    void Set_Mode(int Mode);

    /**
     * @brief Получение флага удаления объекта
     * @return true, если объект должен быть удален, иначе - false
     */
    bool Get_Delete_Flag();

    /**
     * @brief Проверка возможности размещения объекта на сцене
     * @return true, если объект может быть размещен, иначе - false
     */
    bool Spawn_Accept();

    /**
     * @brief Получение длины объекта
     * @return Длина объекта
     */
    int Get_Length();

    /**
     * @brief Получение ширины объекта
     * @return Ширина объекта
     */
    int Get_Width();

protected:
    /**
     * @brief Получение ограничивающего прямоугольника объекта
     * @return Ограничивающий прямоугольник
     */
    QRectF boundingRect() const override;

    /**
     * @brief Отрисовка объекта
     * @param Painter Объект для рисования
     * @param Option Опции стиля
     * @param Widget Виджет
     */
    void paint(QPainter* Painter, const QStyleOptionGraphicsItem* Option, QWidget* Widget) override;

    /**
     * @brief Обработка события перемещения мыши
     * @param Event Событие перемещения мыши
     */
    void mouseMoveEvent(QGraphicsSceneMouseEvent* Event) override;

    /**
     * @brief Обработка события нажатия мыши
     * @param Event Событие нажатия мыши
     */
    void mousePressEvent(QGraphicsSceneMouseEvent* Event) override;

    /**
     * @brief Обработка события отпускания мыши
     * @param Event Событие отпускания мыши
     */
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* Event) override;

    /**
     * @brief Обработка события перемещения указателя мыши над объектом
     * @param Event Событие перемещения указателя мыши
     */
    void hoverMoveEvent(QGraphicsSceneHoverEvent* Event) override;

    /**
     * @brief Обработка события ухода указателя мыши с объекта
     * @param Event Событие ухода указателя мыши
     */
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* Event) override;

private:
    /**
     * @brief Перечисление режимов работы объекта
     */
    enum Mods {
        OFF = 0, ///< Отключен
        MOVE = 1, ///< Перемещение
        SIZE = 2, ///< Изменение размера
        DELETE = 3, ///< Удаление
        SPAWN = 4 ///< Создание
    };

    /**
     * @brief Перечисление сторон объекта
     */
    enum Edges {
        NOTHING = 0, ///< Нет стороны
        TOP = 1, ///< Верхняя сторона
        BOT = 2, ///< Нижняя сторона
        LEFT = 3, ///< Левая сторона
        RIGHT = 4, ///< Правая сторона
    };

    qreal Length = 100, ///< Длина двери
        Old_Length = Length, ///< Предыдущая длина двери
        Width = 30, ///< Ширина двери
        Old_Width = Width, ///< Предыдущая ширина двери
        Min_Size = 25; ///< Минимальный размер двери
    QPointF Return_Position; ///< Позиция возврата объекта
    QColor Default_Color, ///< Цвет объекта по умолчанию
        Coliding_Color, ///< Цвет при коллизии
        Object_Color; ///< Цвет объекта
    Mods Mode = SPAWN; ///< Режим работы объекта
    Edges Edge = NOTHING; ///< Сторона объекта
    bool Delete_Flag = false; ///< Флаг удаления объекта

    /**
     * @brief Проверка наличия коллизий
     * @return true, если есть коллизии, иначе - false
     */
    bool Check_Coliding();

    /**
     * @brief Установка цвета объекта
     * @param Color Цвет объекта
     */
    void Set_Obj_Color(QColor Color);
};
