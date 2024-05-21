
//Общая инфа
/*
    Как пользоваться консолью;
    == F1 - открыть закрыть (так же если хотите можете на крестик ее закрыть)
    == При закрытии консоль не очищается
    == Что бы вывести ваш текст в консоль юзайте функцию "Pout(QString)"
*/

#include <QKeyEvent>

#include "uchebnayapractika.h"

uchebnayapractika::uchebnayapractika(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    ui.cmd_Scene->append("=== Program is running ===\n");

//Cosmetika progi:
    setWindowTitle("NS Editor");
    setWindowIcon(QIcon("Textures/Icons/NSE_Icon.png"));

    this->setGeometry(Screen_W / 2, Screen_H / 2, 1200, 700);
    this->setMinimumSize(1000, 712);

    ui.Save_Button->setFixedSize(30, 30);
    ui.Open_File_Button->setFixedSize(30, 30);
    ui.Edit_Button->setFixedSize(30, 30);
    ui.Info_Button->setFixedSize(30, 30);
    ui.Delete_Button->setFixedSize(30, 30);
    
    ui.Save_Button->setIcon(QIcon("Textures/Icons/Main Icons/Save_btn_Icon.png"));
    ui.Open_File_Button->setIcon(QIcon("Textures/Icons/Main Icons/Open_btn_Icon.png"));
    ui.Edit_Button->setIcon(QIcon("Textures/Icons/Main Icons/Editor_btn_Icon.png"));
    ui.Info_Button->setIcon(QIcon("Textures/Icons/Main Icons/Info_btn_Icon.png"));
    ui.Delete_Button->setIcon(QIcon("Textures/Icons/Main Icons/Delete_btn_Icon.png"));

    ui.TDelete_Button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui.TDelete_Button->setIcon(QIcon("Textures/Icons/Tools Icons/Delete_Icon.png"));
    ui.TAdd_Button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui.TAdd_Button->setIcon(QIcon("Textures/Icons/Tools Icons/Add_Icon.png"));
    ui.TUndo_Button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui.TUndo_Button->setIcon(QIcon("Textures/Icons/Tools Icons/Undo_Icon.png"));
    ui.TRedo_Button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui.TRedo_Button->setIcon(QIcon("Textures/Icons/Tools Icons/Redo_Icon.png"));
    ui.TMove_Button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui.TMove_Button->setIcon(QIcon("Textures/Icons/Tools Icons/Move_Icon.png"));

    ui.Wall_Button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui.Wall_Button->setIcon(QIcon("Textures/Icons/Tools Icons/Wall_Icon.png"));
    ui.Stairs_Button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui.Stairs_Button->setIcon(QIcon("Textures/Icons/Tools Icons/Stairs_Icon.png"));
    ui.Door_Button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui.Door_Button->setIcon(QIcon("Textures/Icons/Tools Icons/Door_Icon.png"));
    ui.Window_Button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui.Window_Button->setIcon(QIcon("Textures/Icons/Tools Icons/Window_Icon.png"));
    ui.Square_Button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui.Square_Button->setIcon(QIcon("Textures/Icons/Tools Icons/Square_Icon.png"));
    ui.Circle_Button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui.Circle_Button->setIcon(QIcon("Textures/Icons/Tools Icons/Circle_Icon.png"));

    ui.verticalLayout_6->setDirection(QBoxLayout::BottomToTop);

    ui.Information->hide();
    ui.Editor->hide();
    ui.Add_Widget->hide();
    ui.Console->hide();

// Programnie buttons:
    connect(ui.Edit_Button, SIGNAL(pressed()), this, SLOT(Tools_Widget()));
    connect(ui.Info_Button, SIGNAL(pressed()), this, SLOT(Info_Widget()));
    connect(ui.Open_File_Button, SIGNAL(pressed()), this, SLOT(Open()));
    connect(ui.Save_Button, SIGNAL(pressed()), this, SLOT(Save()));
    connect(ui.Delete_Button, SIGNAL(pressed()), this, SLOT(Delete_All()));

    connect(ui.TAdd_Button, SIGNAL(pressed()), this, SLOT(Add_Widget()));
    connect(ui.TDelete_Button, SIGNAL(pressed()), this, SLOT(Delete()));
    connect(ui.TMove_Button, SIGNAL(pressed()), this, SLOT(Move()));
    connect(ui.TUndo_Button, SIGNAL(pressed()), this, SLOT(Undo()));
    connect(ui.TRedo_Button, SIGNAL(pressed()), this, SLOT(Redo()));

    connect(ui.Square_Button, SIGNAL(pressed()), this, SLOT(Add_Square()));
    connect(ui.Circle_Button, SIGNAL(pressed()), this, SLOT(Add_Circle()));

    connect(ui.Hide_Button, SIGNAL(pressed()), this, SLOT(Console_Widget()));
}

uchebnayapractika::~uchebnayapractika()
{
    
}

void uchebnayapractika::Info_Widget()
{
    if (!ui.Information->isHidden()) {
        ui.Information->hide();
    }
    else if (!ui.Editor->isHidden()) {
        ui.Editor->hide();
        ui.Add_Widget->hide();

        ui.Information->show();
    }
    else {
        ui.Information->show();
    }
}

void uchebnayapractika::Tools_Widget() {
    if (!ui.Editor->isHidden()) {
        ui.Editor->hide();
        ui.Add_Widget->hide();
    }
    else if (!ui.Information->isHidden()){
        ui.Information->hide();
        ui.Editor->show();
    }
    else{
        ui.Editor->show();
    }
}

void uchebnayapractika::Add_Widget()
{
    if (ui.Add_Widget->isHidden()) {
        ui.Add_Widget->show();

    }
    else {
        ui.Add_Widget->hide();
    }
}

void uchebnayapractika::Console_Widget() {
    Console_Widget(false);
}

void uchebnayapractika::Console_Widget(bool isKey) {
    if (isKey && !ui.Console->isHidden() || !isKey) {
        ui.Console->hide();
    }
    else {
        ui.Console->show();
    }
}

void uchebnayapractika::Pout(QString String)
{
    ui.cmd_Scene->append(String);
}

//tyt bindi propisivaesh ("F1" - занята)
void uchebnayapractika::keyPressEvent(QKeyEvent* e)
{
    if (e->key() == Qt::Key_F1) {
        Console_Widget(true);
    }

}
//^^^^^^^^^^^^^^^^^^^^^^^^



//    Информация для мамулечки:
/*
Видосы что помогли мне при деланьи курсача:
https://www.youtube.com/watch?v=cPvRvX4o5Xc (основные приколы со сценой его еще Максим кидал)
https://www.youtube.com/watch?v=yCLy5Sz7WIA (Управлние предмаетами мышью)
https://www.youtube.com/watch?v=fmSs2mNGh9I&t=1s (тоже там пару приколов про столкновения рассказывается
но можешь всю логику с курсача моего взять)

    Функции для биндов тебе придется переопределять, делаешь это в протектеде 
по примеру что я тебе оставил, а так же в курсаче тоже дохуя примеров например с мышью

            Удачи!!!
*/
// === oblast' parta Mamulechki ===

void uchebnayapractika::Delete_All()
{

}

void uchebnayapractika::Add_Square()
{
    Add_Item("Square_Icon.png");
}

void uchebnayapractika::Add_Circle()
{
    Add_Item("Circle_Icon.png");
}

void uchebnayapractika::Add_Item(QString Path)
{
    Params_Window Window;
    Window.setModal(1);
    Window.exec();
    QStringList Params = Window.Get_Params();
    
    Pout("<QStringList> Params:");
    for (int i = 0; i < Params.size(); i++) {
        Pout("=== " + Params[i]);
    }

    Item = new System_Item;
    Item->Set_Params(Params, Path);
    ui.verticalLayout_6->addWidget(Item);
    
    
}

void uchebnayapractika::Delete()
{
    if (!ui.Add_Widget->isHidden()) {
        ui.Add_Widget->hide();
    }

}

void uchebnayapractika::Move()
{
    if (!ui.Add_Widget->isHidden()) {
        ui.Add_Widget->hide();
    }
}

void uchebnayapractika::Undo()
{

}

void uchebnayapractika::Redo()
{

}

// Mamulechka^^^^^^^^^^^^^^^^^^^^^^



// === oblast' parta Maxima ===

void uchebnayapractika::Open()
{
    File_Name = QFileDialog::getOpenFileName(this, "Open a file", "Projects/", "(*.xml)");
    QFile File(File_Name);

    if (!File.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Error", "File not open\n" + File.errorString());
        return;
    }


}

void uchebnayapractika::Save()
{
    
}

// Max ^^^^^^^^^^^^^^^^^^^^^^^^^