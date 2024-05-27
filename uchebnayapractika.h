#pragma once

#include <QtWidgets/QMainWindow>
#include <QScreen>
#include <QFileDialog>
#include <QMessageBox>
#include <QAbstractButton>



#include "ui_uchebnayapractika.h"
#include "System_Item.h"
#include "Square_Sample.h"
#include "Params_Window.h"

using namespace std;

class uchebnayapractika : public QMainWindow
{
    Q_OBJECT

public:
    uchebnayapractika(QWidget *parent = nullptr);
    ~uchebnayapractika();

protected:
    void keyPressEvent(QKeyEvent* e) override;

private:
    Ui::uchebnayapractikaClass ui;
    
    enum Mods {
        M_OFF = 0,
        M_ADD = 1,
        M_DELETE = 2,
        M_MOVE = 3
    };

    enum System_Form {
        SQUARE = 0,
        CIRCLE = 1
    };

    const QRectF Screen_Geometry = geometry();
    const qreal Screen_H = Screen_Geometry.height(),
            Screen_W = Screen_Geometry.width();
    QString File_Name;
    System_Item* Item;
    Square_Sample* Square;
    QGraphicsScene Plan;

    QList <System_Item*> Items;
    
    Mods Mod;

    void Console_Widget(bool isKey);
    void Pout(QString String);
    void Add_Sys_Item(QString Path, System_Form Form);


public slots:
    void Console_Widget();
    void Info_Widget();
    void Tools_Widget();
    void Add_Widget();
    
    void Delete_All();
    void Add_Square();
    void Add_Circle();
    void Delete();
    void Move();
    void Undo();
    void Redo();

    void Open();
    void Save();

};
