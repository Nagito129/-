#include "Application.h"

Application::Application(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setFixedSize(1085, 703);
    setWindowIcon(QIcon("Icon/Icon.png"));

    // Настройка виджета отображения
    //Room = new QGraphicsScene;
    Room.setSceneRect(-370, -270, 740, 540);
    Room.setBackgroundBrush(QImage("Textures/Wood.jpg"));
    Room.setItemIndexMethod(QGraphicsScene::NoIndex);

    ui.Room_View->setScene(&Room);
    ui.Room_View->setRenderHint(QPainter::Antialiasing);
    ui.Room_View->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui.Room_View->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Отрисовка стен
    Room.addRect(-400, -300, 800, 25, QPen(QColor(0, 0, 0, 0)), QBrush(QImage("Textures/Bricks.jpg")));
    Room.addRect(-400, 275, 800, 25, QPen(QColor(0, 0, 0, 0)), QBrush(QImage("Textures/Bricks.jpg")));
    Room.addRect(-400, -300, 25, 600, QPen(QColor(0, 0, 0, 0)), QBrush(QImage("Textures/Bricks.jpg")));
    Room.addRect(375, -300, 25, 600, QPen(QColor(0, 0, 0, 0)), QBrush(QImage("Textures/Bricks.jpg")));

    Room.addLine(-375, -275, -375, 275, QPen(Qt::black, 2));
    Room.addLine(375, -275, 375, 275, QPen(Qt::black, 2));
    Room.addLine(-375, -275, 375, -275, QPen(Qt::black, 2));
    Room.addLine(-375, 275, 375, 275, QPen(Qt::black, 2));

    Room.addLine(-399, -299, -399, 299, QPen(Qt::black, 3));
    Room.addLine(399, -299, 399, 299, QPen(Qt::black, 3));
    Room.addLine(-399, -299, 399, -299, QPen(Qt::black, 3));
    Room.addLine(-399, 299, 399, 299, QPen(Qt::black, 3));

    // Отрисовка двери
    Room.addRect(-50, 272, 100, 27, QPen(Qt::black, 2), QBrush(QColor(97, 79, 70)));

    // Отрисовка окон
    Room.addRect(150, -299, 150, 25, QPen(QColor(84, 101, 103), 2), QBrush(QColor(164, 199, 205)));
    Room.addRect(-300, -299, 150, 25, QPen(QColor(84, 101, 103), 2), QBrush(QColor(164, 199, 205)));
    
    connect(ui.Add_Sofa_Button, SIGNAL(pressed()), this, SLOT(Add_Sofa()));
    connect(ui.Delete_Sofa_Button, SIGNAL(pressed()), this, SLOT(Delete_Sofa()));
    
    connect(ui.Add_Armchair_Button, SIGNAL(pressed()), this, SLOT(Add_Armchair()));
    connect(ui.Delete_Armchair_Button, SIGNAL(pressed()), this, SLOT(Delete_Armchair()));
    
    connect(ui.Add_Wardrobe_Button, SIGNAL(pressed()), this, SLOT(Add_Wardrobe()));
    connect(ui.Delete_Wardrobe_Button, SIGNAL(pressed()), this, SLOT(Delete_Wardrobe()));

    connect(ui.Add_Table_Button, SIGNAL(pressed()), this, SLOT(Add_Table()));
    connect(ui.Delete_Table_Button, SIGNAL(pressed()), this, SLOT(Delete_Table()));

    connect(ui.Add_Chair_Button, SIGNAL(pressed()), this, SLOT(Add_Chair()));
    connect(ui.Delete_Chair_Button, SIGNAL(pressed()), this, SLOT(Delete_Chair()));

    connect(ui.Delete_All_Button, SIGNAL(pressed()), this, SLOT(Delete()));
    connect(ui.Open_Button, SIGNAL(pressed()), this, SLOT(Open()));
    connect(ui.Save_Button, SIGNAL(pressed()), this, SLOT(Save()));
}

void Application::Add_Sofa()
{
    Sofa = new Sofa_Sample();
    Room.addItem(Sofa);
    Sofas.append(Sofa);
    Sofa->setPos(0, 0);

    if (!Room.collidingItems(Sofa).isEmpty()) {
        delete Sofas[Sofas.size() - 1];
        Sofas.pop_back();
        QMessageBox::warning(this, "Error", "Center is taken");
    }
    else {
        ui.Path->setText("PATH: " + File_Name + "\t(Unsaved)");
    }
}

void Application::Delete_Sofa()
{
    if (!Sofas.isEmpty()) {
        delete Sofas[Sofas.size() - 1];
        Sofas.pop_back();
    }
    ui.Path->setText("PATH: " + File_Name + "\t(Unsaved)");
    if (Room_Is_Empty()) {
        ui.Path->setText("PATH:");
    }
}

void Application::Add_Armchair()
{
    Armchair = new Armchair_Sample();
    Room.addItem(Armchair);
    Armchairs.append(Armchair);
    Armchair->setPos(0, 0);

    if (!Room.collidingItems(Armchair).isEmpty()) {
        delete Armchairs[Armchairs.size() - 1];
        Armchairs.pop_back();
        QMessageBox::warning(this, "Error", "Center is taken");
    }
    else {
        ui.Path->setText("PATH: " + File_Name + "\t(Unsaved)");
    }
}

void Application::Delete_Armchair()
{
    if (!Armchairs.isEmpty()) {
        delete Armchairs[Armchairs.size() - 1];
        Armchairs.pop_back();
    }
    ui.Path->setText("PATH: " + File_Name + "\t(Unsaved)");
    if (Room_Is_Empty()) {
        ui.Path->setText("PATH:");
    }
}

void Application::Add_Wardrobe()
{
    Wardrobe = new Wardrobe_Sample();
    Room.addItem(Wardrobe);
    Wardrobes.append(Wardrobe);
    Wardrobe->setPos(0, 0);

    if (!Room.collidingItems(Wardrobe).isEmpty()) {
        delete Wardrobes[Wardrobes.size() - 1];
        Wardrobes.pop_back();
        QMessageBox::warning(this, "Error", "Center is taken");
    }
    else {
        ui.Path->setText("PATH: " + File_Name + "\t(Unsaved)");
    }
}

void Application::Delete_Wardrobe()
{
    if (!Wardrobes.isEmpty()) {
        delete Wardrobes[Wardrobes.size() - 1];
        Wardrobes.pop_back();
    }
    ui.Path->setText("PATH: " + File_Name + "\t(Unsaved)");
    if (Room_Is_Empty()) {
        ui.Path->setText("PATH:");
    }
}

void Application::Add_Table()
{
    Table = new Table_Sample();
    Room.addItem(Table);
    Tables.append(Table);
    Table->setPos(0, 0);

    if (!Room.collidingItems(Table).isEmpty()) {
        delete Tables[Tables.size() - 1];
        Tables.pop_back();
        QMessageBox::warning(this, "Error", "Center is taken");
    }
    else {
        ui.Path->setText("PATH: " + File_Name + "\t(Unsaved)");
    }
}

void Application::Delete_Table()
{
    if (!Tables.isEmpty()) {
        delete Tables[Tables.size() - 1];
        Tables.pop_back();
    }
    ui.Path->setText("PATH: " + File_Name + "\t(Unsaved)");
    if (Room_Is_Empty()) {
        ui.Path->setText("PATH:");
    }
}

void Application::Add_Chair()
{
    Chair = new Chair_Sample();
    Room.addItem(Chair);
    Chairs.append(Chair);
    Chair->setPos(0, 0);

    if (!Room.collidingItems(Chair).isEmpty()) {
        delete Chairs[Chairs.size() - 1];
        Chairs.pop_back();
        QMessageBox::warning(this, "Error", "Center is taken");
    }
    else {
        ui.Path->setText("PATH: " + File_Name + "\t(Unsaved)");
    }
}

void Application::Delete_Chair()
{
    if (!Chairs.isEmpty()) {
        delete Chairs[Chairs.size() - 1];
        Chairs.pop_back();
    }
    ui.Path->setText("PATH: " + File_Name + "\t(Unsaved)");
    if (Room_Is_Empty()) {
        ui.Path->setText("PATH:");
    }
}

void Application::Delete()
{
    if (Sofas.isEmpty() && Armchairs.isEmpty() && Wardrobes.isEmpty() && Tables.isEmpty() && Chairs.isEmpty()) {
        QMessageBox::warning(this, "Error", "Scene empty");
        return;
    }
    QMessageBox::StandardButton Choice = QMessageBox::question(this, "Delete", "Are you sure you want to clear the stage?", QMessageBox::Yes | QMessageBox::No);
    if (Choice == QMessageBox::No) {
        return;
    }
    else if (Choice == QMessageBox::Yes) {
        Delete_All();
        File_Name = "";
        ui.Path->setText("PATH:");
        QMessageBox::information(this, "Progress", "The scene is cleared!");
    }
}

void Application::Open()
{
    File_Name = QFileDialog::getOpenFileName(this, "Open a file", "Saves/", "(*.room)");
    QFile File(File_Name);

    ui.Path->setText("PATH: " + File_Name);
    ui.Path->setStyleSheet("QLabel {color: #000000}");

    if (!File.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Error", "File not open\n" + File.errorString());
        ui.Path->setStyleSheet("QLabel {color: #DC0000}");
        return;
    }
    
    while (!File.atEnd())
    {
        QStringList Furniture_Parameters = QString::fromUtf8(File.readLine()).split(u'|');
        Furnitures.append(Furniture_Parameters);
    }
    
    ui.Path->setText("PATH: " + File_Name + "\t(Saved)");
    File.close();

    Arrange_Furniture();
}

void Application::Save()
{
    if (Sofas.isEmpty() && Armchairs.isEmpty() && Wardrobes.isEmpty() && Tables.isEmpty() && Chairs.isEmpty()) {
        QMessageBox::warning(this, "Error", "Scene empty");
        return;
    }

    QMessageBox::StandardButton Choice;
    if (!File_Name.isEmpty()) {
        Choice = QMessageBox::question(this, "Save", "Save to the current file?", QMessageBox::Yes | QMessageBox::No);
    }

    if (Choice == QMessageBox::Yes) {
        QFile File(File_Name);
        
        if (!File.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, "Error", "File not open\n" + File.errorString());
            ui.Path->setStyleSheet("QLabel {color: #DC0000}");
            return;
        }
        
        Write_In_File(File);

        
        File.close();
    }

    if (Choice == QMessageBox::No || File_Name.isEmpty()) {
        File_Name = "Saves/Save_" + QString::number(QDir("Saves").count()) + ".room";
        QFile File(File_Name);
        
        if (!File.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, "Error", "File not open\n" + File.errorString());
            ui.Path->setStyleSheet("QLabel {color: #DC0000}");
            return;
        }
        Write_In_File(File);
    }

    QMessageBox::information(this, "Progress", "The room is saved!\n Path: " + File_Name);
    ui.Path->setText("PATH: " + File_Name + "\t(Saved)");
}

bool Application::Room_Is_Empty()
{
    if (!Sofas.isEmpty() || !Armchairs.isEmpty() || !Wardrobes.isEmpty() || !Tables.isEmpty() || !Chairs.isEmpty()) {
        return false;
    }
    else {
        return true;
    }
}

void Application::Write_In_File(QFile& File)
{
    QTextStream Input(&File);

    for (int i = 0; i < Sofas.size(); i++) {
        Input << "s|" << Sofas[i]->x() << "," << Sofas[i]->y() << "|" << Sofas[i]->Get_Size() << "|"
            << Sofas[i]->Get_Angle() << "|" << Sofas[i]->Get_Color() << "\n";
    }
    for (int i = 0; i < Armchairs.size(); i++) {
        Input << "a|" << Armchairs[i]->x() << "," << Armchairs[i]->y() << "|" << Armchairs[i]->Get_Size() << "|"
            << Armchairs[i]->Get_Angle() << "|" << Armchairs[i]->Get_Color() << "\n";
    }
    for (int i = 0; i < Wardrobes.size(); i++) {
        Input << "w|" << Wardrobes[i]->x() << "," << Wardrobes[i]->y() << "|" << Wardrobes[i]->Get_Size() << "|"
            << Wardrobes[i]->Get_Angle() << "|" << Wardrobes[i]->Get_Alpha() << "\n";
    }
    for (int i = 0; i < Tables.size(); i++) {
        Input << "t|" << Tables[i]->x() << "," << Tables[i]->y() << "|" << Tables[i]->Get_Size() << "|"
            << Tables[i]->Get_Angle() << "|" << Tables[i]->Get_Alpha() << "\n";
    }
    for (int i = 0; i < Chairs.size(); i++) {
        Input << "c|" << Chairs[i]->x() << "," << Chairs[i]->y() << "|" << Chairs[i]->Get_Size() << "|"
            << Chairs[i]->Get_Color() << "|" << Chairs[i]->Get_Alpha() << "\n";
    }
}

void Application::Delete_All()
{
    while (!Sofas.isEmpty() || !Armchairs.isEmpty() || !Wardrobes.isEmpty() || !Tables.isEmpty() || !Chairs.isEmpty()) {
        if (!Sofas.isEmpty()) {
            delete Sofas[Sofas.size() - 1];
            Sofas.pop_back();
        }
        if (!Armchairs.isEmpty()) {
            delete Armchairs[Armchairs.size() - 1];
            Armchairs.pop_back();
        }
        if (!Wardrobes.isEmpty()) {
            delete Wardrobes[Wardrobes.size() - 1];
            Wardrobes.pop_back();
        }
        if (!Tables.isEmpty()) {
            delete Tables[Tables.size() - 1];
            Tables.pop_back();
        }
        if (!Chairs.isEmpty()) {
            delete Chairs[Chairs.size() - 1];
            Chairs.pop_back();
        }
    }
}

void Application::Arrange_Furniture()
{
    Delete_All();

    for (int i = 0; i < Furnitures.size(); i++) {
        if (Furnitures[i][0] == 's') {
            Sofa_From_File(i);
        }
        else if (Furnitures[i][0] == 'a') {
            Armchair_From_File(i);
        }
        else if (Furnitures[i][0] == 'w') {
            Wardrobe_From_File(i);
        }
        else if (Furnitures[i][0] == 't') {
            Table_From_File(i);
        }
        else if (Furnitures[i][0] == 'c') {
            Chair_From_File(i);
        }
        else if (Furnitures[i][0] == '\n'){
        }

        else{
            QMessageBox::warning(this, "Error", "Incorrect file");
            Delete_All();
            return;
        }
    }

    while (!Furnitures.isEmpty()) {
        Furnitures.pop_back();
    }
}

void Application::Sofa_From_File(int i)
{
    QStringList String_Position = Furnitures[i][1].split(u',');
    QPointF Position = QPointF(String_Position[0].toDouble(), String_Position[1].toDouble());
    
    qreal Size = Furnitures[i][2].toDouble();
    qreal Angle = Furnitures[i][3].toDouble();

    QStringList RGB = Furnitures[i][4].split(u',');
    QColor Color = QColor(RGB[0].toDouble(), RGB[1].toDouble(), RGB[2].toDouble());

    Sofa = new Sofa_Sample(Size, Angle, Color);
    Room.addItem(Sofa);
    Sofas.append(Sofa);
    Sofa->setPos(Position);
}

void Application::Armchair_From_File(int i)
{
    QStringList String_Position = Furnitures[i][1].split(u',');
    QPointF Position = QPointF(String_Position[0].toDouble(), String_Position[1].toDouble());

    qreal Size = Furnitures[i][2].toDouble();
    qreal Angle = Furnitures[i][3].toDouble();

    QStringList RGB = Furnitures[i][4].split(u',');
    QColor Color = QColor(RGB[0].toDouble(), RGB[1].toDouble(), RGB[2].toDouble());

    Armchair = new Armchair_Sample(Size, Angle, Color);
    Room.addItem(Armchair);
    Armchairs.append(Armchair);
    Armchair->setPos(Position);
}

void Application::Wardrobe_From_File(int i)
{
    QStringList String_Position = Furnitures[i][1].split(u',');
    QPointF Position = QPointF(String_Position[0].toDouble(), String_Position[1].toDouble());

    qreal Size = Furnitures[i][2].toDouble();
    qreal Angle = Furnitures[i][3].toDouble();

    QColor Alpha_Color = QColor(255, 255, 255, Furnitures[i][4].toDouble());

    Wardrobe = new Wardrobe_Sample(Size, Angle, Alpha_Color);
    Room.addItem(Wardrobe);
    Wardrobes.append(Wardrobe);
    Wardrobe->setPos(Position);
}

void Application::Table_From_File(int i)
{
    QStringList String_Position = Furnitures[i][1].split(u',');
    QPointF Position = QPointF(String_Position[0].toDouble(), String_Position[1].toDouble());

    qreal Size = Furnitures[i][2].toDouble();
    qreal Angle = Furnitures[i][3].toDouble();

    QColor Alpha_Color = QColor(255, 255, 255, Furnitures[i][4].toDouble());

    Table = new Table_Sample(Size, Angle, Alpha_Color);
    Room.addItem(Table);
    Tables.append(Table);
    Table->setPos(Position);
}

void Application::Chair_From_File(int i)
{
    QStringList String_Position = Furnitures[i][1].split(u',');
    QPointF Position = QPointF(String_Position[0].toDouble(), String_Position[1].toDouble());

    qreal Size = Furnitures[i][2].toDouble();
    
    QStringList RGB = Furnitures[i][3].split(u',');
    QColor Color = QColor(RGB[0].toDouble(), RGB[1].toDouble(), RGB[2].toDouble());

    QColor Alpha_Color = QColor(255, 255, 255, Furnitures[i][4].toDouble());

    Chair = new Chair_Sample(Size, Alpha_Color, Color);
    Room.addItem(Chair);
    Chairs.append(Chair);
    Chair->setPos(Position);
}
