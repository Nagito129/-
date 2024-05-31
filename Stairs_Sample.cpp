/**
 * @file Stairs_Sample.cpp
 * @brief Реализация класса Stairs_Sample для работы с объектом "Лестница".
 */

#include "Stairs_Sample.h"

/**
  * @brief Конструктор класса Stairs_Sample с параметрами.
  * @param Length Длина лестницы.
  * @param Width Ширина лестницы.
  */
Stairs_Sample::Stairs_Sample(qreal Length, qreal Width)
{
    this->Length = Length;
    this->Width = Width;
    Old_Width = Width;
    Old_Length = Length;

    setAcceptHoverEvents(true);

    Object_Color.setRgb(166, 166, 166);
    Default_Color.setRgb(166, 166, 166);
    Default_Color.setAlpha(140);
    Coliding_Color.setRgb(210, 20, 20);
    Coliding_Color.setAlpha(140);
    Mode = OFF;
    this->setZValue(1);
}

/**
 * @brief Конструктор класса Stairs_Sample без параметров.
 */
Stairs_Sample::Stairs_Sample()
{
    setAcceptHoverEvents(true);

    Object_Color.setRgb(166, 166, 166);
    Object_Color.setAlpha(140);
    Default_Color.setRgb(166, 166, 166);
    Default_Color.setAlpha(140);
    Coliding_Color.setRgb(210, 20, 20);
    Coliding_Color.setAlpha(140);
    this->setZValue(1);
}

/**
 * @brief Устанавливает режим работы лестницы.
 * @param Mode Режим работы (0 - OFF, 1 - MOVE, 3 - DELETE).
 */
void Stairs_Sample::Set_Mode(int Mode)
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
 * @brief Получает флаг удаления лестницы.
 * @return true, если лестница подлежит удалению.
 */
bool Stairs_Sample::Get_Delete_Flag()
{
    return Delete_Flag;
}

/**
 * @brief Проверяет возможность появления лестницы без столкновений.
 * @return true, если лестница не сталкивается с другими объектами.
 */
bool Stairs_Sample::Spawn_Accept()
{
    if (scene()->collidingItems(this).isEmpty()) {
        Mode = OFF;
        Object_Color.setAlpha(255);
        Set_Obj_Color(Object_Color);
        return true;
    }
    else {
        return false;
    }
}

/**
 * @brief Получает ограничивающий прямоугольник лестницы.
 * @return Ограничивающий прямоугольник.
 */
QRectF Stairs_Sample::boundingRect() const
{
    return QRectF(0 - Length / 2, 0 - Width / 2, Length, Width);
}

/**
 * @brief Отрисовывает лестницу.
 * @param Painter Указатель на объект QPainter.
 * @param Option Указатель на опции стиля.
 * @param Widget Указатель на виджет.
 */
void Stairs_Sample::paint(QPainter* Painter, const QStyleOptionGraphicsItem* Option, QWidget* Widget)
{
    Painter->setBrush(Object_Color);
    Painter->drawRect(0 - Length / 2, 0 - Width / 2, Length, Width);
    Painter->drawLine(-Length / 2, 0 - Width / 2, Length / 2, Width / 2);
    Painter->drawLine(Length / 2, 0 - Width / 2, -Length / 2, Width / 2);
}

/**
 * @brief Обрабатывает событие перемещения мыши.
 * @param Event Указатель на событие QGraphicsSceneMouseEvent.
 */
void Stairs_Sample::mouseMoveEvent(QGraphicsSceneMouseEvent* Event)
{
    if (Mode == SIZE || (Mode == SPAWN && (Edge == TOP || Edge == BOT || Edge == LEFT || Edge == RIGHT))) {
        if (Edge == TOP || Edge == BOT) {
            prepareGeometryChange();
            Width = (qAbs(Event->pos().y())) * 2;

            if (Edge == TOP) {
                this->setPos(this->pos().x(), -(Width - Old_Width) / 2);
            }
            else if (Edge == BOT) {
                this->setPos(this->pos().x(), (Width - Old_Width) / 2);
            }

            Check_Coliding();
        }

        if (Edge == LEFT || Edge == RIGHT) {
            prepareGeometryChange();
            Length = (qAbs(Event->pos().x())) * 2;

            if (Edge == LEFT) {
                this->setPos((Length - Old_Length) / 2, this->pos().y());
            }
            else if (Edge == RIGHT) {
                this->setPos(-(Length - Old_Length) / 2, this->pos().y());
            }

            Check_Coliding();
        }
    }

    if (Mode == MOVE || (Mode == SPAWN && Edge == NOTHING)) {
        this->setPos(mapToScene(Event->pos()));
        Check_Coliding();
    }
}

/**
 * @brief Обрабатывает событие нажатия кнопки мыши.
 * @param Event Указатель на событие QGraphicsSceneMouseEvent.
 */
void Stairs_Sample::mousePressEvent(QGraphicsSceneMouseEvent* Event)
{
    this->setZValue(1);

    if (Mode == SIZE || Mode == MOVE) {
        Return_Position = this->pos();
        Object_Color.setAlpha(140);
        update();
    }
    else if (Mode == DELETE) {
        if (Delete_Flag == false) {
            Delete_Flag = true;
            Object_Color.setRgb(59, 106, 171);
            this->setScale(1.05);
        }
        else {
            Delete_Flag = false;
            Object_Color = Default_Color;
            this->setScale(1);
        }
    }
}

/**
 * @brief Обрабатывает событие отпускания кнопки мыши.
 * @param Event Указатель на событие QGraphicsSceneMouseEvent.
 */
void Stairs_Sample::mouseReleaseEvent(QGraphicsSceneMouseEvent* Event)
{
    if (Mode == SIZE || Mode == MOVE) {
        this->setZValue(0);

        if (Check_Coliding() && Mode == SIZE) {
            Width = Old_Width;
            Length = Old_Length;
            this->setPos(Return_Position);
        }
        else {
            if (Old_Length != Length) {
                Old_Length = Length;
            }
            if (Old_Width != Width) {
                Old_Width = Width;
            }
            if (Width < Min_Size) {
                Width = Min_Size;
                Old_Width = Width;
            }
            if (Length < Min_Size) {
                Length = Min_Size;
                Old_Length = Width;
            }
        }

        if (Check_Coliding() && Mode == MOVE) {
            this->setPos(Return_Position);
        }

        Object_Color = Default_Color;
        Object_Color.setAlpha(255);
        update();
    }
}

/**
 * @brief Обрабатывает событие перемещения мыши с включенным режимом hover.
 * @param Event Указатель на событие QGraphicsSceneHoverEvent.
 */
void Stairs_Sample::hoverMoveEvent(QGraphicsSceneHoverEvent* Event)
{
    if (Mode == MOVE || Mode == SIZE || Mode == SPAWN) {
        if (Event->pos().x() > Length / 2 - 3 && Event->pos().x() < Length / 2 && Event->pos().y() < Width / 2 - 3 && Event->pos().y() > -Width / 2 + 3) {
            Edge = LEFT;
            if (Mode == MOVE) {
                Mode = SIZE;
            }
            this->setCursor(QCursor(Qt::SizeHorCursor));
        }
        else if (Event->pos().x() > -Length / 2 && Event->pos().x() < -Length / 2 + 3 && Event->pos().y() < Width / 2 - 3 && Event->pos().y() > -Width / 2 + 3) {
            Edge = RIGHT;
            if (Mode == MOVE) {
                Mode = SIZE;
            }
            this->setCursor(QCursor(Qt::SizeHorCursor));
        }
        else if (Event->pos().y() < -Width / 2 + 3 && Event->pos().y() > -Width / 2 && Event->pos().x() < Length / 2 - 3 && Event->pos().x() > -Length / 2 + 3) {
            Edge = TOP;
            if (Mode == MOVE) {
                Mode = SIZE;
            }
            this->setCursor(QCursor(Qt::SizeVerCursor));
        }
        else if (Event->pos().y() < Width / 2 && Event->pos().y() > Width / 2 - 3 && Event->pos().x() < Length / 2 - 3 && Event->pos().x() > -Length / 2 + 3) {
            Edge = BOT;
            if (Mode == MOVE) {
                Mode = SIZE;
            }
            this->setCursor(QCursor(Qt::SizeVerCursor));
        }
        else {
            if (Mode == SIZE) {
                Mode = MOVE;
            }
            Edge = NOTHING;
            this->setCursor(QCursor(Qt::ArrowCursor));
        }
    }
}

/**
 * @brief Обрабатывает событие выхода мыши из области объекта с включенным режимом hover.
 * @param Event Указатель на событие QGraphicsSceneHoverEvent.
 */
void Stairs_Sample::hoverLeaveEvent(QGraphicsSceneHoverEvent* Event)
{
    if (Mode == SIZE) {
        this->setCursor(QCursor(Qt::ArrowCursor));
        Mode = MOVE;
    }
}

/**
 * @brief Проверяет столкновение объекта с другими объектами.
 * @return true, если объект сталкивается с другими объектами.
 */
bool Stairs_Sample::Check_Coliding()
{
    if (scene()->collidingItems(this).isEmpty()) {
        Set_Obj_Color(Default_Color);
        update();
        return false;
    }
    else {
        Set_Obj_Color(Coliding_Color);
        update();
        return true;
    }
}

/**
 * @brief Устанавливает цвет объекта.
 * @param Color Новый цвет объекта.
 */
void Stairs_Sample::Set_Obj_Color(QColor Color)
{
    Object_Color = Color;
    update();
}

/**
 * @brief Получает длину лестницы.
 * @return Длина лестницы.
 */
int Stairs_Sample::Get_Length() {
    return Length;
}

/**
 * @brief Получает ширину лестницы.
 * @return Ширина лестницы.
 */
int Stairs_Sample::Get_Width() {
    return Width;
}
