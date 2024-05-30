

#include <QKeyEvent>

#include "uchebnayapractika.h"

uchebnayapractika::uchebnayapractika(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    ui.cmd_Scene->append("=== Program is running ===\n");

//Cosmetika progi:
    setWindowTitle("NS Editor");
    setWindowIcon(QIcon("Textures/Icons/Main Icons/NSE_Icon.png"));

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

    connect(ui.Square_Button, SIGNAL(pressed()), this, SLOT(Add_Square()));
    connect(ui.Circle_Button, SIGNAL(pressed()), this, SLOT(Add_Circle()));

    connect(ui.Wall_Button, SIGNAL(pressed()), this, SLOT(Add_Wall()));
    connect(ui.Window_Button, SIGNAL(pressed()), this, SLOT(Add_Window()));
    connect(ui.Door_Button, SIGNAL(pressed()), this, SLOT(Add_Door()));
    connect(ui.Stairs_Button, SIGNAL(pressed()), this, SLOT(Add_Stairs()));

    connect(ui.Hide_Button, SIGNAL(pressed()), this, SLOT(Console_Widget()));

    ui.Scene->setScene(&Plan);
    ui.Scene->setRenderHint(QPainter::Antialiasing);

}

uchebnayapractika::~uchebnayapractika()
{
    Delete_All();
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





void uchebnayapractika::keyPressEvent(QKeyEvent* e)/////////////////////////////////////////////////////////////////
{
    if (e->key() == Qt::Key_F1) {
        Console_Widget(true);
    }
    if (e->key() == Qt::Key_Enter || e->key() == Qt::Key_Return) {
        if (Mode == M_ADD) {
            if (is_Build) {
                if (Build_Parts[Build_Parts.size() - 1]->Spawn_Accept()) {
                    Mode = M_OFF;
                    ui.Editor->setDisabled(false);
                }
            }
            else if (Form == SQUARE) {
                if (Items[Items.size() - 1]->Square->Spawn_Accept()) {
                    Mode = M_OFF;
                    ui.Editor->setDisabled(false);
                    Items[Items.size() - 1]->Set_Position(Items[Items.size() - 1]->Square->x(), Items[Items.size() - 1]->Square->y() * -1);
                }
                else {
                    QMessageBox::warning(this, "Error", "Objects is coliding");
                }
            }
            else if (Form == CIRCLE) {
                if (Items[Items.size() - 1]->Circle->Spawn_Accept()) {
                    Mode = M_OFF;
                    ui.Editor->setDisabled(false);
                    Items[Items.size() - 1]->Set_Position(Items[Items.size() - 1]->Circle->x(), Items[Items.size() - 1]->Circle->y() * -1);
                }
                else {
                    QMessageBox::warning(this, "Error", "Objects is coliding");
                }
            }
        }
        if (Mode == M_DELETE) {
            for (int i = Items.size() - 1; i >= 0; i--) {
                if (Items[i]->Get_Delete_Flag()) {
                    delete Items[i];
                    Items.remove(i);
                }
            }
            for (int i = Build_Parts.size() - 1; i >= 0; i--) {
                if (Build_Parts[i]->Get_Delete_Flag()) {
                    delete Build_Parts[i];
                    Build_Parts.remove(i);
                }
            }
        }
    }
    if (e->key() == Qt::Key_Escape && Mode == M_ADD) {
        if (is_Build) {
            delete Build_Parts[Build_Parts.size() - 1];
            Build_Parts.pop_back();
        }
        else {
            delete Items[Items.size() - 1];
            Items.pop_back();
        }
        ui.Editor->setDisabled(false);
        Mode = M_OFF;
    }
}



void uchebnayapractika::Delete_All()
{
    while (!Items.isEmpty())
    {
        delete Items[0];
        Items.pop_front();
    }
    while (!Build_Parts.isEmpty())
    {
        delete Build_Parts[0];
        Build_Parts.pop_front();
    }
    ui.Editor->setDisabled(false);
}

void uchebnayapractika::Add_Square()
{
    Add_Sys_Item("Square_Icon.png", SQUARE);
}

void uchebnayapractika::Add_Circle()
{
    Add_Sys_Item("Circle_Icon.png", CIRCLE);
}

void uchebnayapractika::Add_Wall()
{
    is_Build = true;
    Mode = M_ADD;
    ui.Editor->setDisabled(this);
    Part = new B_Parts(1);
    Plan.addItem(Part->Wall);
    Part->Wall->setPos(0, 0);
    Build_Parts.append(Part);
}

void uchebnayapractika::Add_Window()
{
    is_Build = true;
    Mode = M_ADD;
    ui.Editor->setDisabled(this);
    Part = new B_Parts(2);
    Plan.addItem(Part->Window);
    Part->Window->setPos(0, 0);
    Build_Parts.append(Part);
}

void uchebnayapractika::Add_Door()
{
    is_Build = true;
    Mode = M_ADD;
    ui.Editor->setDisabled(this);
    Part = new B_Parts(3);
    Plan.addItem(Part->Door);
    Part->Door->setPos(0, 0);
    Build_Parts.append(Part);
}

void uchebnayapractika::Add_Stairs()
{
    is_Build = true;
    Mode = M_ADD;
    ui.Editor->setDisabled(this);
    Part = new B_Parts(4);
    Plan.addItem(Part->Stairs);
    Part->Stairs->setPos(0, 0);
    Build_Parts.append(Part);
}

void uchebnayapractika::Add_Sys_Item(QString Path, System_Form Form)///////////////////////////////////////////////////
{
    is_Build = false;
    Mode = M_ADD;
    this->Form = Form;
    ui.Editor->setDisabled(true);

    Params_Window Window;
    Window.setModal(1);
    Window.exec();
    QStringList Params = Window.Get_Params();

    Pout("<QStringList> Params:");
    for (int i = 0; i < Params.size(); i++) {
        Pout("=== " + Params[i]);
    }

    Item = new System_Item;
    
    if (Form == CIRCLE) {
        Item->is_Square = false;
    }
    
    Item->Set_Params(Params, Path);
    ui.verticalLayout_6->addWidget(Item);
    Items.append(Item);

    if (Form == SQUARE) {
        Plan.addItem(Item->Square);
        Item->Square->setPos(0, 0);
    }

    else if (Form == CIRCLE) {
        Plan.addItem(Item->Circle);
        Item->Circle->setPos(0, 0);
    }
}

void uchebnayapractika::Set_Items_And_Parts_Mode(int Mode)
{
    for (int i = 0; i < Items.size(); i++) {
        Items[i]->Set_Mode(Mode);
    }
    for (int i = 0; i < Build_Parts.size(); i++) {
        Build_Parts[i]->Set_Mode(Mode);
    }
}

void uchebnayapractika::Delete()
{
    if (!ui.Add_Widget->isHidden()) {
        ui.Add_Widget->hide();
    }
    Mode = M_DELETE;
    Set_Items_And_Parts_Mode(3);
    
}

void uchebnayapractika::Move()
{
    if (!ui.Add_Widget->isHidden()) {
        ui.Add_Widget->hide();
    }
    Mode = M_MOVE;
    Set_Items_And_Parts_Mode(1);
}

void uchebnayapractika::Open()
{
    Delete_All();
    File_Name = QFileDialog::getOpenFileName(this, "Open a file", "Projects/", "(*.xml)");
    QFile File(File_Name);

    if (!File.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Error", "File not open\n" + File.errorString());
        return;
    }
    ui.Project_Name_Label->setText(File_Name);
    QXmlStreamReader Xml;
    Xml.setDevice(&File);
    Xml.readNext();
    QStringList Params;
    QString Type;
    int Angle;
    while (!Xml.atEnd()) {
        Params.clear();
        if (Xml.isStartElement()) {
            if (Xml.name().toString() == "Wall") {
                Params.append("1");
                foreach(const QXmlStreamAttribute & attr, Xml.attributes()) {
                    Params.append(attr.value().toString());
                }
                Part = new B_Parts(Params);
                Plan.addItem(Part->Wall);
                Part->Wall->setPos(Params[1].toInt(), Params[2].toInt());
                Build_Parts.append(Part);
            }
            else if (Xml.name().toString() == "Window") {
                Params.append("2");
                foreach(const QXmlStreamAttribute & attr, Xml.attributes()) {
                    Params.append(attr.value().toString());
                }
                Part = new B_Parts(Params);
                Plan.addItem(Part->Window);
                Part->Window->setPos(Params[1].toInt(), Params[2].toInt());
                Build_Parts.append(Part);
            }
            else if (Xml.name().toString() == "Door") {
                Params.append("3");
                foreach(const QXmlStreamAttribute & attr, Xml.attributes()) {
                    Params.append(attr.value().toString());
                }
                Part = new B_Parts(Params);
                Plan.addItem(Part->Door);
                Part->Door->setPos(Params[1].toInt(), Params[2].toInt());
                Build_Parts.append(Part);
            }
            else if (Xml.name().toString() == "Stairs") {
                Params.append("4");
                foreach(const QXmlStreamAttribute & attr, Xml.attributes()) {
                    Params.append(attr.value().toString());
                }
                Part = new B_Parts(Params);
                Plan.addItem(Part->Stairs);
                Part->Stairs->setPos(Params[1].toInt(), Params[2].toInt());
                Build_Parts.append(Part);
            }
            else if (Xml.name().toString() == "Item") {
                foreach(const QXmlStreamAttribute & attr, Xml.attributes()) {
                    if (attr.name().toString() == "type")
                        Type = attr.value().toString();
                    else if (attr.name().toString() == "angle")
                        Angle = attr.value().toInt();
                    else
                        Params.append(attr.value().toString());
                }
                Item = new System_Item;
                QString Path;
                if (Type.toInt() == CIRCLE) {
                    Item->is_Square = false;
                    Path = "Circle_Icon.png";
                }
                else if (Type.toInt() == SQUARE) {
                    Item->is_Square = true;
                    Path = "Square_Icon.png";
                }
                Item->Set_Params(Params, Path, Angle);
                ui.verticalLayout_6->addWidget(Item);
                Items.append(Item);
                if (Type.toInt() == SQUARE) {
                    Plan.addItem(Item->Square);
                    Item->Square->setPos(Params[7].toInt(), Params[8].toInt());
                }

                else if (Type.toInt() == CIRCLE) {
                    Plan.addItem(Item->Circle);
                    Item->Circle->setPos(Params[7].toInt(), Params[8].toInt());
                }
            }
        }
        Xml.readNext();
    }
    File.close();
}

void uchebnayapractika::Save()
{
    if (Items.isEmpty() && Build_Parts.isEmpty()) {
        QMessageBox::warning(this, "Error", "Scene empty");
        return;
    }

    if (File_Name.isEmpty()) {
        File_Name = QFileDialog::getSaveFileName(this, "Save file", "C\\", "XML File (*.xml)");
        QFile File(File_Name);
        if (!File.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, "Error", "File not open\n" + File.errorString());
            return;
        }
        Write_In_File(File);
        File.close();
    }

    else{
        QMessageBox::StandardButton Choice;
        Choice = QMessageBox::question(this, "Save", "Save to the current file?", QMessageBox::Yes | QMessageBox::No);

        if (Choice == QMessageBox::Yes) {
            QFile File(File_Name);

            if (!File.open(QFile::WriteOnly | QFile::Text)) {
                QMessageBox::warning(this, "Error", "File not open\n" + File.errorString());
                return;
            }

            Write_In_File(File);
            File.close();
        }

        else {
            File_Name = QFileDialog::getSaveFileName(this, "Save file", "C\\", "XML File (*.xml)");
            QFile File(File_Name);

            if (!File.open(QFile::WriteOnly | QFile::Text)) {
                QMessageBox::warning(this, "Error", "File not open\n" + File.errorString());
                return;
            }

            Write_In_File(File);
            File.close();
        }
    }

    QMessageBox::information(this, "Progress", "The room is saved!\n Path: " + File_Name);
}

void uchebnayapractika::Write_In_File(QFile& File) {
    QXmlStreamWriter Xml(&File);
    Xml.setAutoFormatting(true);
    Xml.writeStartDocument();
    Xml.writeStartElement("Items");
    if (!Build_Parts.isEmpty()) {
        for (int i = 0; i < Build_Parts.size(); i++) {
            switch (Build_Parts[i]->Get_Part()) {
            case 1:
                Xml.writeStartElement("Wall");
                Xml.writeAttribute("x", QString().number(Build_Parts[i]->Wall->x()));
                Xml.writeAttribute("y", QString().number(Build_Parts[i]->Wall->y()));
                Xml.writeAttribute("Length", QString().number(Build_Parts[i]->Wall->Get_Length()));
                Xml.writeAttribute("Width", QString().number(Build_Parts[i]->Wall->Get_Width()));
                Xml.writeEndElement();
                break;
            case 2:
                Xml.writeStartElement("Window");
                Xml.writeAttribute("x", QString().number(Build_Parts[i]->Window->x()));
                Xml.writeAttribute("y", QString().number(Build_Parts[i]->Window->y()));
                Xml.writeAttribute("Length", QString().number(Build_Parts[i]->Window->Get_Length()));
                Xml.writeAttribute("Width", QString().number(Build_Parts[i]->Window->Get_Width()));
                Xml.writeEndElement();
                break;
            case 3:
                Xml.writeStartElement("Door");
                Xml.writeAttribute("x", QString().number(Build_Parts[i]->Door->x()));
                Xml.writeAttribute("y", QString().number(Build_Parts[i]->Door->y()));
                Xml.writeAttribute("Length", QString().number(Build_Parts[i]->Door->Get_Length()));
                Xml.writeAttribute("Width", QString().number(Build_Parts[i]->Door->Get_Width()));
                Xml.writeEndElement();
                break;
            case 4:
                Xml.writeStartElement("Stairs");
                Xml.writeAttribute("x", QString().number(Build_Parts[i]->Stairs->x()));
                Xml.writeAttribute("y", QString().number(Build_Parts[i]->Stairs->y()));
                Xml.writeAttribute("Length", QString().number(Build_Parts[i]->Stairs->Get_Length()));
                Xml.writeAttribute("Width", QString().number(Build_Parts[i]->Stairs->Get_Width()));
                Xml.writeEndElement();
                break;
            }
        }
    }
    if (!Items.isEmpty()) {
        for (int i = 0; i < Items.size(); i++) {
            Xml.writeStartElement("Item");
            QStringList Params = Items[i]->Get_Params();
            Xml.writeAttribute("type", Items[i]->is_Square ? "0" : "1");
            Xml.writeAttribute("name", Params[0]);
            Xml.writeAttribute("firm", Params[1]);
            Xml.writeAttribute("series", Params[2]);
            Xml.writeAttribute("height", Params[3]);
            Xml.writeAttribute("width", Params[4]);
            Xml.writeAttribute("length", Params[5]);
            Xml.writeAttribute("weight", Params[6]);
            Xml.writeAttribute("x", Items[i]->is_Square ? QString().number(Items[i]->Square->x()) : QString().number(Items[i]->Circle->x()));
            Xml.writeAttribute("y", Items[i]->is_Square ? QString().number(Items[i]->Square->y()) : QString().number(Items[i]->Circle->y()));
            Xml.writeAttribute("angle", Items[i]->is_Square ? QString().number(Items[i]->Square->Get_Angle()) : QString().number(Items[i]->Circle->Get_Angle()));
            Xml.writeEndElement();
        }
    }
    Xml.writeEndElement();
    Xml.writeEndDocument();
}