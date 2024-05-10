/********************************************************************************
** Form generated from reading UI file 'Application.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLICATION_H
#define UI_APPLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ApplicationClass
{
public:
    QWidget *centralWidget;
    QGraphicsView *Room_View;
    QLabel *Path;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *Delete_Wardrobe_Button;
    QPushButton *Add_Chair_Button;
    QPushButton *Delete_Armchair_Button;
    QPushButton *Delete_Chair_Button;
    QPushButton *Add_Sofa_Button;
    QPushButton *Add_Wardrobe_Button;
    QPushButton *Delete_Table_Button;
    QPushButton *Add_Table_Button;
    QPushButton *Add_Armchair_Button;
    QPushButton *Delete_Sofa_Button;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label_14;
    QPushButton *Save_Button;
    QPushButton *Open_Button;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QPushButton *Delete_All_Button;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ApplicationClass)
    {
        if (ApplicationClass->objectName().isEmpty())
            ApplicationClass->setObjectName("ApplicationClass");
        ApplicationClass->resize(1085, 703);
        centralWidget = new QWidget(ApplicationClass);
        centralWidget->setObjectName("centralWidget");
        Room_View = new QGraphicsView(centralWidget);
        Room_View->setObjectName("Room_View");
        Room_View->setGeometry(QRect(10, 10, 800, 600));
        Room_View->setFrameShape(QFrame::StyledPanel);
        Room_View->setFrameShadow(QFrame::Sunken);
        Room_View->setCacheMode(QGraphicsView::CacheNone);
        Path = new QLabel(centralWidget);
        Path->setObjectName("Path");
        Path->setGeometry(QRect(10, 610, 799, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("System")});
        font.setPointSize(12);
        font.setBold(false);
        font.setStrikeOut(false);
        Path->setFont(font);
        Path->setFrameShape(QFrame::Box);
        Path->setFrameShadow(QFrame::Raised);
        Path->setLineWidth(2);
        Path->setMidLineWidth(1);
        Path->setTextFormat(Qt::PlainText);
        Path->setScaledContents(false);
        Path->setAlignment(Qt::AlignCenter);
        Path->setMargin(0);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(820, 10, 260, 201));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName("gridLayout");
        Delete_Wardrobe_Button = new QPushButton(verticalLayoutWidget);
        Delete_Wardrobe_Button->setObjectName("Delete_Wardrobe_Button");

        gridLayout->addWidget(Delete_Wardrobe_Button, 4, 1, 1, 1);

        Add_Chair_Button = new QPushButton(verticalLayoutWidget);
        Add_Chair_Button->setObjectName("Add_Chair_Button");

        gridLayout->addWidget(Add_Chair_Button, 2, 0, 1, 1);

        Delete_Armchair_Button = new QPushButton(verticalLayoutWidget);
        Delete_Armchair_Button->setObjectName("Delete_Armchair_Button");

        gridLayout->addWidget(Delete_Armchair_Button, 1, 1, 1, 1);

        Delete_Chair_Button = new QPushButton(verticalLayoutWidget);
        Delete_Chair_Button->setObjectName("Delete_Chair_Button");

        gridLayout->addWidget(Delete_Chair_Button, 2, 1, 1, 1);

        Add_Sofa_Button = new QPushButton(verticalLayoutWidget);
        Add_Sofa_Button->setObjectName("Add_Sofa_Button");

        gridLayout->addWidget(Add_Sofa_Button, 0, 0, 1, 1);

        Add_Wardrobe_Button = new QPushButton(verticalLayoutWidget);
        Add_Wardrobe_Button->setObjectName("Add_Wardrobe_Button");

        gridLayout->addWidget(Add_Wardrobe_Button, 4, 0, 1, 1);

        Delete_Table_Button = new QPushButton(verticalLayoutWidget);
        Delete_Table_Button->setObjectName("Delete_Table_Button");

        gridLayout->addWidget(Delete_Table_Button, 3, 1, 1, 1);

        Add_Table_Button = new QPushButton(verticalLayoutWidget);
        Add_Table_Button->setObjectName("Add_Table_Button");

        gridLayout->addWidget(Add_Table_Button, 3, 0, 1, 1);

        Add_Armchair_Button = new QPushButton(verticalLayoutWidget);
        Add_Armchair_Button->setObjectName("Add_Armchair_Button");

        gridLayout->addWidget(Add_Armchair_Button, 1, 0, 1, 1);

        Delete_Sofa_Button = new QPushButton(verticalLayoutWidget);
        Delete_Sofa_Button->setObjectName("Delete_Sofa_Button");

        gridLayout->addWidget(Delete_Sofa_Button, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(820, 320, 131, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sitka Small")});
        font1.setPointSize(12);
        font1.setWeight(QFont::ExtraBold);
        font1.setItalic(false);
        font1.setHintingPreference(QFont::PreferFullHinting);
        label->setFont(font1);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(820, 340, 251, 21));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Sitka Small")});
        font2.setPointSize(12);
        font2.setBold(true);
        label_2->setFont(font2);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(830, 360, 221, 21));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Sitka Small")});
        font3.setPointSize(12);
        label_3->setFont(font3);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(820, 360, 49, 16));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Sitka Small")});
        font4.setPointSize(20);
        label_4->setFont(font4);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(820, 380, 49, 16));
        label_5->setFont(font4);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(830, 380, 221, 21));
        label_6->setFont(font3);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(820, 400, 49, 16));
        label_7->setFont(font4);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(830, 400, 221, 21));
        label_8->setFont(font3);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(820, 420, 251, 21));
        label_9->setFont(font2);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(830, 460, 221, 21));
        label_10->setFont(font3);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(820, 440, 49, 16));
        label_11->setFont(font4);
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(820, 460, 49, 16));
        label_13->setFont(font4);
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(830, 440, 221, 21));
        label_14->setFont(font3);
        Save_Button = new QPushButton(centralWidget);
        Save_Button->setObjectName("Save_Button");
        Save_Button->setGeometry(QRect(820, 250, 261, 31));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(false);
        Save_Button->setFont(font5);
        Open_Button = new QPushButton(centralWidget);
        Open_Button->setObjectName("Open_Button");
        Open_Button->setGeometry(QRect(820, 290, 261, 31));
        QFont font6;
        font6.setPointSize(12);
        Open_Button->setFont(font6);
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(820, 510, 261, 21));
        label_15->setFont(font3);
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(820, 530, 261, 21));
        label_16->setFont(font3);
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(820, 550, 261, 21));
        label_17->setFont(font3);
        label_18 = new QLabel(centralWidget);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(820, 490, 131, 21));
        label_18->setFont(font1);
        label_19 = new QLabel(centralWidget);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(820, 570, 131, 21));
        label_19->setFont(font1);
        label_20 = new QLabel(centralWidget);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(820, 590, 261, 21));
        label_20->setFont(font3);
        label_21 = new QLabel(centralWidget);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(820, 610, 261, 21));
        label_21->setFont(font3);
        label_22 = new QLabel(centralWidget);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(820, 630, 261, 21));
        label_22->setFont(font3);
        Delete_All_Button = new QPushButton(centralWidget);
        Delete_All_Button->setObjectName("Delete_All_Button");
        Delete_All_Button->setGeometry(QRect(820, 210, 261, 31));
        Delete_All_Button->setFont(font6);
        ApplicationClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ApplicationClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1085, 22));
        ApplicationClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ApplicationClass);
        mainToolBar->setObjectName("mainToolBar");
        ApplicationClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ApplicationClass);
        statusBar->setObjectName("statusBar");
        ApplicationClass->setStatusBar(statusBar);

        retranslateUi(ApplicationClass);

        QMetaObject::connectSlotsByName(ApplicationClass);
    } // setupUi

    void retranslateUi(QMainWindow *ApplicationClass)
    {
        ApplicationClass->setWindowTitle(QCoreApplication::translate("ApplicationClass", "Room", nullptr));
        Path->setText(QCoreApplication::translate("ApplicationClass", "PATH:", nullptr));
        Delete_Wardrobe_Button->setText(QCoreApplication::translate("ApplicationClass", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\210\320\272\320\260\321\204", nullptr));
        Add_Chair_Button->setText(QCoreApplication::translate("ApplicationClass", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\321\203\320\273", nullptr));
        Delete_Armchair_Button->setText(QCoreApplication::translate("ApplicationClass", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\232\321\200\320\265\321\201\320\273\320\276", nullptr));
        Delete_Chair_Button->setText(QCoreApplication::translate("ApplicationClass", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\321\202\321\203\320\273", nullptr));
        Add_Sofa_Button->setText(QCoreApplication::translate("ApplicationClass", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\264\320\270\320\262\320\260\320\275", nullptr));
        Add_Wardrobe_Button->setText(QCoreApplication::translate("ApplicationClass", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\210\320\272\320\260\321\204", nullptr));
        Delete_Table_Button->setText(QCoreApplication::translate("ApplicationClass", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\321\202\320\276\320\273", nullptr));
        Add_Table_Button->setText(QCoreApplication::translate("ApplicationClass", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\320\276\320\273", nullptr));
        Add_Armchair_Button->setText(QCoreApplication::translate("ApplicationClass", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\321\200\320\265\321\201\320\273\320\276", nullptr));
        Delete_Sofa_Button->setText(QCoreApplication::translate("ApplicationClass", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\264\320\270\320\262\320\260\320\275", nullptr));
        label->setText(QCoreApplication::translate("ApplicationClass", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        label_2->setText(QCoreApplication::translate("ApplicationClass", "\320\237\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\321\213\320\265 \320\277\321\200\320\265\320\264\320\274\320\265\321\202\321\213:", nullptr));
        label_3->setText(QCoreApplication::translate("ApplicationClass", "\320\240\320\260\320\267\320\274\320\265\321\200 - \320\233\320\232\320\234 + \320\232\320\276\320\273\320\265\321\201\320\276", nullptr));
        label_4->setText(QCoreApplication::translate("ApplicationClass", "-", nullptr));
        label_5->setText(QCoreApplication::translate("ApplicationClass", "-", nullptr));
        label_6->setText(QCoreApplication::translate("ApplicationClass", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202 - \320\232\320\276\320\273\320\265\321\201\320\276", nullptr));
        label_7->setText(QCoreApplication::translate("ApplicationClass", "-", nullptr));
        label_8->setText(QCoreApplication::translate("ApplicationClass", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265 - \320\233\320\232\320\234", nullptr));
        label_9->setText(QCoreApplication::translate("ApplicationClass", "\320\232\321\200\321\203\320\263\320\273\321\213\320\265 \320\277\321\200\320\265\320\264\320\274\320\265\321\202\321\213:", nullptr));
        label_10->setText(QCoreApplication::translate("ApplicationClass", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265 - \320\233\320\232\320\234", nullptr));
        label_11->setText(QCoreApplication::translate("ApplicationClass", "-", nullptr));
        label_13->setText(QCoreApplication::translate("ApplicationClass", "-", nullptr));
        label_14->setText(QCoreApplication::translate("ApplicationClass", "\320\240\320\260\320\267\320\274\320\265\321\200 - \320\232\320\276\320\273\320\265\321\201\320\276", nullptr));
        Save_Button->setText(QCoreApplication::translate("ApplicationClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        Open_Button->setText(QCoreApplication::translate("ApplicationClass", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        label_15->setText(QCoreApplication::translate("ApplicationClass", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\277\321\200\320\265\320\264\320\274\320\265\321\202\320\276\320\262 \320\277\321\200\320\276\320\270\321\201-", nullptr));
        label_16->setText(QCoreApplication::translate("ApplicationClass", "\321\205\320\276\320\264\320\270\321\202 \320\277\320\276 \320\277\321\200\320\270\320\275\321\206\320\270\320\277\321\203 \320\277\320\276\321\201\320\273\320\265\320\264-", nullptr));
        label_17->setText(QCoreApplication::translate("ApplicationClass", "\320\275\320\270\320\271 \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275 - \320\277\320\265\321\200\320\262\321\213\320\271 \321\203\320\264\320\260\320\273\320\265\320\275", nullptr));
        label_18->setText(QCoreApplication::translate("ApplicationClass", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265:", nullptr));
        label_19->setText(QCoreApplication::translate("ApplicationClass", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265:", nullptr));
        label_20->setText(QCoreApplication::translate("ApplicationClass", "\320\237\321\200\320\265\320\264\320\274\320\265\321\202 \320\264\320\276\320\261\320\260\320\262\320\273\321\217\320\265\321\202\321\201\321\217 \320\262 \321\206\320\265\320\275\321\202\321\200,", nullptr));
        label_21->setText(QCoreApplication::translate("ApplicationClass", "\320\265\321\201\320\273\320\270 \321\202\320\260\320\274 \320\265\321\201\321\202\321\214 \320\264\320\273\321\217 \320\275\320\265\320\263\320\276 \320\274\320\265\321\201\321\202\320\276,", nullptr));
        label_22->setText(QCoreApplication::translate("ApplicationClass", "\320\270\320\275\320\260\321\207\320\265 \320\275\320\265\321\202", nullptr));
        Delete_All_Button->setText(QCoreApplication::translate("ApplicationClass", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\201\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ApplicationClass: public Ui_ApplicationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLICATION_H
