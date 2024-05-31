/**
 * @file main.cpp
 * @brief Точка входа в приложение.
 */

#include "uchebnayapractika.h"
#include <QtWidgets/QApplication>

/**
  * @brief Главная функция, запускающая приложение.
  * @param argc Количество аргументов командной строки.
  * @param argv Массив аргументов командной строки.
  * @return Код завершения приложения.
  */
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);  ///< Создание объекта приложения Qt.
    uchebnayapractika w;         ///< Создание главного окна приложения.
    w.show();                    ///< Отображение главного окна.
    return a.exec();             ///< Запуск основного цикла обработки событий.
}
