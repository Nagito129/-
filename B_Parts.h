/**
 * @file B_Parts.h
 * @brief Объявление класса B_Parts для работы с элементами здания
 */

#pragma once

#include "Wall_Sample.h"
#include "Window_Sample.h"
#include "Door_Sample.h"
#include "Stairs_Sample.h"

/**
  * @brief Класс для работы с элементами здания
  */
class B_Parts
{
public:
    /**
     * @brief Конструктор класса B_Parts с параметром типа элемента
     * @param Part Тип элемента: 1 - стена, 2 - окно, 3 - дверь, 4 - лестница
     */
    B_Parts(int Part);

    /**
     * @brief Конструктор класса B_Parts с параметром списка параметров
     * @param Params Список параметров
     */
    B_Parts(QStringList Params);

    /**
     * @brief Деструктор класса B_Parts
     */
    ~B_Parts();

    /**
     * @brief Установка режима для элемента
     * @param Mode Режим: 0 - OFF, 1 - MOVE, 3 - DELETE
     */
    void Set_Mode(int Mode);

    /**
     * @brief Получение флага удаления элемента
     * @return true, если элемент должен быть удален, иначе - false
     */
    bool Get_Delete_Flag();

    /**
     * @brief Проверка возможности размещения элемента на сцене
     * @return true, если нет коллизий, иначе - false
     */
    bool Spawn_Accept();

    Wall_Sample* Wall; ///< Указатель на объект класса Wall_Sample
    Window_Sample* Window; ///< Указатель на объект класса Window_Sample
    Door_Sample* Door; ///< Указатель на объект класса Door_Sample
    Stairs_Sample* Stairs; ///< Указатель на объект класса Stairs_Sample

    /**
     * @brief Получение типа элемента
     * @return Тип элемента: 1 - стена, 2 - окно, 3 - дверь, 4 - лестница
     */
    int Get_Part();

private:
    /**
     * @brief Перечисление типов элементов здания
     */
    enum Build_Parts {
        WALL = 1, ///< Стена
        WINDOW = 2, ///< Окно
        DOOR = 3, ///< Дверь
        STAIRS = 4 ///< Лестница
    };

    Build_Parts Part; ///< Тип элемента
};
