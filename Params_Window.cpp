/**
 * @file Params_Window.cpp
 * @brief Реализация класса Params_Window для работы с окном параметров.
 */

#include "Params_Window.h"

/**
  * @brief Конструктор класса Params_Window.
  * @param parent Указатель на родительский виджет.
  */
Params_Window::Params_Window(QWidget* parent)
    : QDialog(parent)
{
    _ui.setupUi(this); ///< Инициализация пользовательского интерфейса.
    this->setFixedSize(300, 200); ///< Установка фиксированного размера окна.
    this->setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint); ///< Удаление кнопки закрытия окна.
    this->setWindowIcon(QIcon("../../Textures/Icons/Tools Icons/Params_Icon.png")); ///< Установка иконки окна.
    this->setWindowTitle("System Parameters"); ///< Установка заголовка окна.

    // Установка валидаторов для полей ввода.
    _ui.Height_Edit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]*")));
    _ui.Width_Edit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]*")));
    _ui.Length_Edit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]*")));

    // Подключение сигнала нажатия кнопки к слоту установки параметров.
    connect(_ui.Next_Button, SIGNAL(pressed()), this, SLOT(Set_Params()));
}

/**
 * @brief Деструктор класса Params_Window.
 */
Params_Window::~Params_Window()
{
    // Пустой деструктор, так как нет необходимости в дополнительных действиях.
}

/**
 * @brief Получает список параметров.
 * @return Список параметров.
 */
QStringList Params_Window::Get_Params()
{
    return Params;
}

/**
 * @brief Устанавливает параметры на основе введенных данных.
 */
void Params_Window::Set_Params()
{
    // Проверка, что поля 'Height', 'Width' и 'Length' не пусты.
    if (_ui.Height_Edit->text() != "" && _ui.Width_Edit->text() != "" && _ui.Length_Edit->text() != "") {
        // Добавление параметров в список.
        Params.append(_ui.Name_Edit->text());
        Params.append(_ui.Firm_Edit->text());
        Params.append(_ui.Seria_Edit->text());
        Params.append(_ui.Height_Edit->text());
        Params.append(_ui.Width_Edit->text());
        Params.append(_ui.Length_Edit->text());
        Params.append(_ui.Weight_Edit->text());
        Params.append("0");
        Params.append("0");

        this->close(); ///< Закрытие окна после установки параметров.
    }
    else {
        // Вывод предупреждения, если какие-либо обязательные поля пусты.
        QMessageBox::warning(this, "Error", "'Height' or 'Width', or 'Length' is empty");
    }
}
