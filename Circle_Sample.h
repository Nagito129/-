/**
 * @file Circle_Sample.h
 * @brief Объявление класса Circle_Sample для работы с круговыми объектами
 */

#pragma once
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPaintEvent>
#include <QGraphicsSceneMouseEvent>

/**
  * @brief Класс для работы с круговыми объектами
  */
class Circle_Sample :
                      public QGraphicsItem
{
public:
    /**
  * @brief Конструктор класса Circle_Sample с параметрами имени, длины, ширины и угла
  * @param Name Имя объекта
  * @param Length Длина
  * @param Width Ширина
  * @param Angle Угол поворота
  */
    Circle_Sample(QString Name, qreal Length, qreal Width, qreal Angle);

    /**
    * @brief Конструктор класса Circle_Sample с параметрами имени, длины и ширины
    * @param Name Имя объекта
    * @param Length Длина
    * @param Width Ширина
    */
    Circle_Sample(QString Name, qreal Length, qreal Width);

    /**
    * @brief Установка цвета и уровня нагрузки
    * @param Color Цвет
    * @param Workload Уровень нагрузки
    */
    void Set_Workload(QColor Color, qreal Workload);

    /**
    * @brief Проверка возможности размещения объекта на сцене
    * @return true, если объект может быть размещен, иначе - false
    */
    bool Spawn_Accept();

    /**
     * @brief Установка режима работы для объекта
     * @param Mode Режим работы: 0 - OFF, 1 - MOVE, 2 - SPAWN, 3 - DELETE
     */
    void Set_Mode(int Mode);

    /**
     * @brief Получение флага удаления объекта
     * @return true, если объект должен быть удален, иначе - false
     */
    bool Get_Delete_Flag();

    /**
    * @brief Получение угла поворота объекта
    * @return Угол поворота объекта
    */
    int Get_Angle();

protected:

    /**
     * @brief Получение ограничивающего прямоугольника объекта
     * @return Ограничивающий прямоугольник
     */
    QRectF boundingRect() const override;

    /**
   * @brief Получение формы объекта
   * @return Путь, задающий форму объекта
   */
    QPainterPath shape() const override;

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
     * @brief Обработка события вращения колеса мыши
     * @param Event Событие вращения колеса мыши
     */
    void wheelEvent(QGraphicsSceneWheelEvent* Event) override;

private:

    /**
     * @brief Перечисление режимов работы объекта
     */
    enum Mods {
        OFF = 0, ///< Отключен
        MOVE = 1, ///< Перемещение
        SPAWN = 2, ///< Создание
        DELETE = 3 ///< Удаление
    };

    Mods Mode = SPAWN; ///< Режим работы объекта
    QString Name; ///< Имя объекта
    qreal Length, ///< Длина объекта
        Width, ///< Ширина объекта
        Angle = 0, ///< Угол поворота объекта
        Workload_Status; ///< Уровень нагрузки объекта
    QColor Color_Status, ///< Цвет объекта
        Coliding_Color, ///< Цвет при коллизии
        Object_Color; ///< Цвет объекта
    bool Delete_Flag = false; ///< Флаг удаления объекта
    QPointF Return_Position; ///< Позиция возврата объекта

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
