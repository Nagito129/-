#pragma once

#include <QtWidgets/QMainWindow>
#include <QScreen>
#include <QFileDialog>
#include <QMessageBox>
#include <QAbstractButton>



#include "ui_uchebnayapractika.h"
#include "System_Item.h"
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
    
    const QRectF Screen_Geometry = geometry();
    const qreal Screen_H = Screen_Geometry.height(),
            Screen_W = Screen_Geometry.width();

    QString File_Name;
    System_Item* Item;
    QVector <System_Item> Sys_Item_Widgets;

    void Console_Widget(bool isKey);
    void Pout(QString String);
    void Add_Item(QString Path);

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
