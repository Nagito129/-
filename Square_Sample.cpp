/**
 * @file Square_Sample.cpp
 * @brief Реализация класса Square_Sample для работы с объектом "Квадрат".
 */

#include "Square_Sample.h"

 /**
  * @brief Конструктор класса Square_Sample с параметрами.
  * @param Name Имя квадрата.
  * @param Length Длина квадрата.
  * @param Width Ширина квадрата.
  * @param Angle Угол поворота квадрата.
  */
Square_Sample::Square_Sample(QString Name, qreal Length, qreal Width, qreal Angle)
{
    this->Name = Name;
    this->Length = Length;
    this->Width = Width;
    this->Angle = Angle;
    Coliding_Color.setRgb(210, 20, 20);
    Coliding_Color.setAlpha(140);
    this->setRotation(Angle);
    Mode = OFF;
    this->setZValue(1);
}

/**
 * @brief Конструктор класса Square_Sample без угла поворота.
 * @param Name Имя квадрата.
 * @param Length Длина квадрата.
 * @param Width Ширина квадрата.
 */
Square_Sample::Square_Sample(QString Name, qreal Length, qreal Width)
{
    this->Name = Name;
    this->Length = Length;
    this->Width = Width;
    Coliding_Color.setRgb(210, 20, 20);
    Coliding_Color.setAlpha(140);
    this->setZValue(1);
}

/**
 * @brief Устанавливает рабочую нагрузку и цвет квадрата.
 * @param Color Цвет квадрата.
 * @param Workload Рабочая нагрузка.
 */
void Square_Sample::Set_Workload(QColor Color, qreal Workload)
{
    Color_Status = Color;
    Workload_Status = Workload;
    Set_Obj_Color(Color_Status);
}

/**
 * @brief Проверяет возможность появления квадрата без столкновений.
 * @return true, если квадрат не сталкивается с другими объектами.
 */
bool Square_Sample::Spawn_Accept()
{
    if (scene()->collidingItems(this).isEmpty()) {
        Mode = OFF;
        Color_Status.setAlpha(255);
        Set_Obj_Color(Color_Status);
        return true;
    }
    else {
        return false;
    }
}

/**
 * @brief Устанавливает режим работы квадрата.
 * @param Mode Режим работы (0 - OFF, 1 - MOVE, 3 - DELETE).
 */
void Square_Sample::Set_Mode(int Mode)
{
    if (Mode == 0) {
        this->Mode = OFF;
    }
    else if (Mode == 1) {
        this->Mode = MOVE;
    }
    else if (Mode == 3) {
        this->Mode = DELETE;
    }
}

/**
 * @brief Получает флаг удаления квадрата.
 * @return true, если квадрат подлежит удалению.
 */
bool Square_Sample::Get_Delete_Flag()
{
    return Delete_Flag;
}

/**
 * @brief Получает ограничивающий прямоугольник квадрата.
 * @return Ограничивающий прямоугольник.
 */
QRectF Square_Sample::boundingRect() const
{
    return QRectF(0 - Length / 2, 0 - Width / 2, Length, Width);
}

/**
 * @brief Отрисовывает квадрат.
 * @param Painter Указатель на объект QPainter.
 * @param Option Указатель на опции стиля.
 * @param Widget Указатель на виджет.
 */
void Square_Sample::paint(QPainter* Painter, const QStyleOptionGraphicsItem* Option, QWidget* Widget)
{
    if (Mode == SPAWN) {
        Object_Color.setAlpha(140);
    }
    Painter->setBrush(Object_Color);
    Painter->drawRect(0 - Length / 2, 0 - Width / 2, Length, Width);
}

/**
 * @brief Обрабатывает событие перемещения мыши.
 * @param Event Указатель на событие QGraphicsSceneMouseEvent.
 */
void Square_Sample::mouseMoveEvent(QGraphicsSceneMouseEvent* Event)
{
    if (Mode == SPAWN || Mode == MOVE) {
        this->setPos(mapToScene(Event->pos()));
        Check_Coliding();
    }
}

/**
 * @brief Обрабатывает событие нажатия кнопки мыши.
 * @param Event Указатель на событие QGraphicsSceneMouseEvent.
 */
void Square_Sample::mousePressEvent(QGraphicsSceneMouseEvent* Event)
{
    if (Mode == MOVE) {
        this->setZValue(1);
        Return_Position = this->pos();
        Object_Color.setAlpha(140);
        update();
    }

    if (Mode == DELETE) {
        if (Delete_Flag == false) {
            Delete_Flag = true;
            Object_Color.setRgb(59, 106, 171);
            this->setScale(1.05);
        }
        else {
            Delete_Flag = false;
            Object_Color = Color_Status;
            this->setScale(1);
        }
    }

    Q_UNUSED(Event);
}

/**
 * @brief Обрабатывает событие отпускания кнопки мыши.
 * @param Event Указатель на событие QGraphicsSceneMouseEvent.
 */
void Square_Sample::mouseReleaseEvent(QGraphicsSceneMouseEvent* Event)
{
    if (Mode == MOVE) {
        this->setZValue(0);

        if (Check_Coliding()) {
            this->setPos(Return_Position);
        }
        Object_Color = Color_Status;
        Object_Color.setAlpha(255);
        update();
    }
    Q_UNUSED(Event);
}

/**
 * @brief Обрабатывает событие прокрутки колесика мыши.
 * @param Event Указатель на событие QGraphicsSceneWheelEvent.
 */
void Square_Sample::wheelEvent(QGraphicsSceneWheelEvent* Event)
{
    if (Mode == SPAWN || Mode == MOVE) {
        if (Event->delta() > 0) {
            this->setRotation(Angle += 15);
        }
        else {
            this->setRotation(Angle -= 15);
        }
        Check_Coliding();
    }
}

/**
 * @brief Устанавливает цвет объекта.
 * @param Color Новый цвет объекта.
 */
void Square_Sample::Set_Obj_Color(QColor Color)
{
    Object_Color = Color;
    update(boundingRect());
}

/**
 * @brief Проверяет столкновение объекта с другими объектами.
 * @return true, если объект сталкивается с другими объектами.
 */
bool Square_Sample::Check_Coliding()
{
    if (scene()->collidingItems(this).isEmpty()) {
        Color_Status.setAlpha(140);
        Set_Obj_Color(Color_Status);
        return false;
    }
    else {
        Set_Obj_Color(Coliding_Color);
        return true;
    }
}

/**
 * @brief Получает угол поворота объекта.
 * @return Угол поворота.
 */
int Square_Sample::Get_Angle() {
    return Angle;
}
