/**
 * @file uchebnayapractika.h
 * @brief Объявление класса uchebnayapractika для работы с приложением
 */

#pragma once

#include <QtWidgets/QMainWindow>
#include <QScreen>
#include <QFileDialog>
#include <QMessageBox>
#include <QAbstractButton>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>

#include "ui_uchebnayapractika.h"
#include "System_Item.h"
#include "Square_Sample.h"
#include "Params_Window.h"
#include "B_Parts.h"

/**
  * @brief Класс для работы с приложением
  */
class uchebnayapractika : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса uchebnayapractika
     * @param parent Родительский виджет
     */
    uchebnayapractika(QWidget* parent = nullptr);

    /**
     * @brief Деструктор класса uchebnayapractika
     */
    ~uchebnayapractika();

protected:
    /**
     * @brief Обработчик события нажатия клавиши
     * @param e Событие нажатия клавиши
     */
    void keyPressEvent(QKeyEvent* e) override;

private:
    Ui::uchebnayapractikaClass ui; ///< Интерфейс

    /**
     * @brief Перечисление режимов работы
     */
    enum Mods {
        M_OFF = 0, ///< Отключено
        M_ADD = 1, ///< Добавление
        M_DELETE = 2, ///< Удаление
        M_MOVE = 3, ///< Перемещение
    };

    /**
     * @brief Перечисление форм элементов системы
     */
    enum System_Form {
        SQUARE = 0, ///< Квадрат
        CIRCLE = 1 ///< Круг
    };

    const QRectF Screen_Geometry = geometry(); ///< Геометрия экрана
    const qreal Screen_H = Screen_Geometry.height(), ///< Высота экрана
        Screen_W = Screen_Geometry.width(); ///< Ширина экрана
    QString File_Name = ""; ///< Имя файла
    System_Item* Item; ///< Элемент системы
    B_Parts* Part; ///< Деталь
    QGraphicsScene Plan; ///< Сцена

    QList <System_Item*> Items; ///< Список элементов
    QList <B_Parts*> Build_Parts; ///< Список деталей

    Mods Mode; ///< Режим
    System_Form Form; ///< Форма элемента
    bool is_Build; ///< Признак построения

    /**
     * @brief Вывод сообщения в консоль
     * @param isKey Флаг для обработки клавиатурного ввода
     */
    void Console_Widget(bool isKey);

    /**
     * @brief Вывод сообщения в консоль
     * @param String Сообщение для вывода
     */
    void Pout(QString String);

    /**
     * @brief Добавление элемента системы
     * @param Path Путь
     * @param Form Форма элемента
     */
    void Add_Sys_Item(QString Path, System_Form Form);

    /**
     * @brief Установка режима работы для элементов и деталей
     * @param Mode Режим работы
     */
    void Set_Items_And_Parts_Mode(int Mode);

    /**
     * @brief Запись в файл
     * @param File Файл для записи
     */
    void Write_In_File(QFile& File);

public slots:
    void Console_Widget();
    void Info_Widget();
    void Tools_Widget();
    void Add_Widget();

    void Delete_All();
    void Add_Square();
    void Add_Circle();
    void Add_Wall();
    void Add_Window();
    void Add_Door();
    void Add_Stairs();
    void Delete();
    void Move();

    void Open();
    void Save();
};

