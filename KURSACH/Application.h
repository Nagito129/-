#pragma once

#include <QtWidgets/QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QList>

#include "ui_Application.h"
#include "Sofa_Sample.h"
#include "Armchair_Sample.h"
#include "Wardrobe_Sample.h"
#include "Table_Sample.h"
#include "Chair_Sample.h"


class Application : public QMainWindow
{
    Q_OBJECT

public:
    Application(QWidget *parent = nullptr);

public slots:
    void Add_Sofa();
    void Delete_Sofa();

    void Add_Armchair();
    void Delete_Armchair();

    void Add_Wardrobe();
    void Delete_Wardrobe();

    void Add_Table();
    void Delete_Table();

    void Add_Chair();
    void Delete_Chair();

    void Delete();
    void Open();
    void Save();

    
    

private:
    Ui::ApplicationClass ui;

    QGraphicsScene Room;

    Sofa_Sample* Sofa;
    QList <Sofa_Sample*> Sofas;
    
    Armchair_Sample* Armchair;
    QList <Armchair_Sample*> Armchairs;

    Wardrobe_Sample* Wardrobe;
    QList <Wardrobe_Sample*> Wardrobes;

    Table_Sample* Table;
    QList <Table_Sample*> Tables;

    Chair_Sample* Chair;
    QList <Chair_Sample*> Chairs;

    QList<QStringList> Furnitures;

    QString File_Name;

    bool Room_Is_Empty();
    void Write_In_File(QFile &File);
    void Delete_All();
    void Arrange_Furniture();
    void Sofa_From_File(int i);
    void Armchair_From_File(int i);
    void Wardrobe_From_File(int i);
    void Table_From_File(int i);
    void Chair_From_File(int i);
};
