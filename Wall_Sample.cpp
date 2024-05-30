#include "Wall_Sample.h"

Wall_Sample::Wall_Sample(qreal Lenght, qreal Width, qreal Angle)
{
	this->Lenght = Lenght;
	this->Width = Width;
	this->Angle = Angle;
	Old_Width = Width;
	Old_Lenght = Lenght;
	
	setAcceptHoverEvents(true);

	Object_Color.setRgb(94, 94, 94);
	Default_Color.setRgb(94, 94, 94);
	Default_Color.setAlpha(140);
	Coliding_Color.setRgb(210, 20, 20);
	Coliding_Color.setAlpha(140);
}

Wall_Sample::Wall_Sample()
{
	setAcceptHoverEvents(true);
	
	Object_Color.setRgb(94, 94, 94);
	Object_Color.setAlpha(140);
	Default_Color.setRgb(94, 94, 94);
	Default_Color.setAlpha(140);
	Coliding_Color.setRgb(210, 20, 20);
	Coliding_Color.setAlpha(140);
}

void Wall_Sample::Set_Mode(int Mode)
{
	if (Mode == 0) {
		this->Mode = OFF;
	}
	if (Mode == 1) {
		this->Mode = MOVE;
	}
	if (Mode == 3) {
		this->Mode = DELETE;
	}
}

bool Wall_Sample::Get_Delete_Flag()
{
	return Delete_Flag;
}

bool Wall_Sample::Spawn_Accept()
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

QRectF Wall_Sample::boundingRect() const
{
	return QRectF(0 - Lenght / 2, 0 - Width / 2, Lenght, Width);
}

void Wall_Sample::paint(QPainter* Painter, const QStyleOptionGraphicsItem* Option, QWidget* Widget)
{
	Painter->setBrush(Object_Color);
	Painter->drawRect(0 - Lenght / 2, 0 - Width / 2, Lenght, Width);
}

void Wall_Sample::mouseMoveEvent(QGraphicsSceneMouseEvent* Event)
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
			Lenght = (qAbs(Event->pos().x())) * 2;

			if (Edge == LEFT) {
				this->setPos((Lenght - Old_Lenght) / 2, this->pos().y());
			}
			else if (Edge == RIGHT) {
				this->setPos(-(Lenght - Old_Lenght) / 2, this->pos().y());
			}

			Check_Coliding();
		}
	}
	
	if (Mode == MOVE || (Mode == SPAWN && Edge == NOTHING)) {
			this->setPos(mapToScene(Event->pos()));

			Check_Coliding();
	}
}

void Wall_Sample::mousePressEvent(QGraphicsSceneMouseEvent* Event)
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

void Wall_Sample::mouseReleaseEvent(QGraphicsSceneMouseEvent* Event)
{
	if (Mode == SIZE || Mode == MOVE) {
		this->setZValue(0);

		if (Check_Coliding() && Mode == SIZE) {
			Width = Old_Width;
			Lenght = Old_Lenght;
			this->setPos(Return_Position);
		}

		else {
			if (Old_Lenght != Lenght) {
				Old_Lenght = Lenght;
			}
			if (Old_Width != Width) {
				Old_Width = Width;
			}
			if (Width < Min_Size) {
				Width = Min_Size;
				Old_Width = Width;
			}
			if (Lenght < Min_Size) {
				Lenght = Min_Size;
				Old_Lenght = Width;
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
void Wall_Sample::hoverMoveEvent(QGraphicsSceneHoverEvent* Event)
{
	if (Mode == MOVE || Mode == SIZE || Mode == SPAWN) {
		if (Event->pos().x() > Lenght / 2 - 3 && Event->pos().x() < Lenght / 2 && Event->pos().y() < Width / 2 - 3 && Event->pos().y() > -Width / 2 + 3) {
			Edge = LEFT;
			if (Mode == MOVE) {
				Mode = SIZE;
			}
			this->setCursor(QCursor(Qt::SizeHorCursor));
		}

		else if (Event->pos().x() > -Lenght / 2 && Event->pos().x() < -Lenght / 2 + 3 && Event->pos().y() < Width / 2 - 3 && Event->pos().y() > -Width / 2 + 3) {
			Edge = RIGHT;
			if (Mode == MOVE) {
				Mode = SIZE;
			}
			this->setCursor(QCursor(Qt::SizeHorCursor));
		}

		else if (Event->pos().y() < -Width / 2 + 3 && Event->pos().y() > -Width / 2 && Event->pos().x() < Lenght / 2 - 3 && Event->pos().x() > -Lenght / 2 + 3) {
			Edge = TOP;
			if (Mode == MOVE) {
				Mode = SIZE;
			}
			this->setCursor(QCursor(Qt::SizeVerCursor));
		}

		else if (Event->pos().y() < Width / 2 && Event->pos().y() > Width / 2 - 3 && Event->pos().x() < Lenght / 2 - 3 && Event->pos().x() > -Lenght / 2 + 3) {
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

void Wall_Sample::hoverLeaveEvent(QGraphicsSceneHoverEvent* Event)
{
	if (Mode == SIZE) {
		this->setCursor(QCursor(Qt::ArrowCursor));
		Mode = MOVE;
	}
}

bool Wall_Sample::Check_Coliding()
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

void Wall_Sample::Set_Obj_Color(QColor Color)
{
	Object_Color = Color;
	update();
}
