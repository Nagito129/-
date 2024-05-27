#pragma once

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPaintEvent>
#include <QMainWindow>

class Square_Sample : public QGraphicsItem
{
public:
    Square_Sample(QString Name, qreal Lenght, qreal Width, qreal Angle, qreal X, qreal Y);
    Square_Sample(QString Name, qreal Lenght, qreal Width);

    void Set_Workload(QColor Color, qreal Workload);

protected:
    QRectF boundingRect() const override;
    void paint(QPainter* Painter, const QStyleOptionGraphicsItem* Option, QWidget* Widget) override;

private:
    enum Mode {

    };

    QString Name;
    qreal Lenght,
        Width,
        Angle,
        Workload_Status,
        X, Y;
    QColor Color_Status;
};

