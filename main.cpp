/**
 * @file main.cpp
 * @brief ����� ����� � ����������.
 */

#include "uchebnayapractika.h"
#include <QtWidgets/QApplication>

 /**
  * @brief ������� �������, ����������� ����������.
  * @param argc ���������� ���������� ��������� ������.
  * @param argv ������ ���������� ��������� ������.
  * @return ��� ���������� ����������.
  */
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);  ///< �������� ������� ���������� Qt.
    uchebnayapractika w;         ///< �������� �������� ���� ����������.
    w.show();                    ///< ����������� �������� ����.
    return a.exec();             ///< ������ ��������� ����� ��������� �������.
}
