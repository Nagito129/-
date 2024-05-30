/**
 * @file B_Parts.h
 * @brief ���������� ������ B_Parts ��� ������ � ���������� ������
 */

#pragma once

#include "Wall_Sample.h"
#include "Window_Sample.h"
#include "Door_Sample.h"
#include "Stairs_Sample.h"

 /**
  * @brief ����� ��� ������ � ���������� ������
  */
class B_Parts
{
public:
    /**
     * @brief ����������� ������ B_Parts � ���������� ���� ��������
     * @param Part ��� ��������: 1 - �����, 2 - ����, 3 - �����, 4 - ��������
     */
    B_Parts(int Part);

    /**
     * @brief ����������� ������ B_Parts � ���������� ������ ����������
     * @param Params ������ ����������
     */
    B_Parts(QStringList Params);

    /**
     * @brief ���������� ������ B_Parts
     */
    ~B_Parts();

    /**
     * @brief ��������� ������ ��� ��������
     * @param Mode �����: 0 - OFF, 1 - MOVE, 3 - DELETE
     */
    void Set_Mode(int Mode);

    /**
     * @brief ��������� ����� �������� ��������
     * @return true, ���� ������� ������ ���� ������, ����� - false
     */
    bool Get_Delete_Flag();

    /**
     * @brief �������� ����������� ���������� �������� �� �����
     * @return true, ���� ��� ��������, ����� - false
     */
    bool Spawn_Accept();

    Wall_Sample* Wall; ///< ��������� �� ������ ������ Wall_Sample
    Window_Sample* Window; ///< ��������� �� ������ ������ Window_Sample
    Door_Sample* Door; ///< ��������� �� ������ ������ Door_Sample
    Stairs_Sample* Stairs; ///< ��������� �� ������ ������ Stairs_Sample

    /**
     * @brief ��������� ���� ��������
     * @return ��� ��������: 1 - �����, 2 - ����, 3 - �����, 4 - ��������
     */
    int Get_Part();

private:
    /**
     * @brief ������������ ����� ��������� ������
     */
    enum Build_Parts {
        WALL = 1, ///< �����
        WINDOW = 2, ///< ����
        DOOR = 3, ///< �����
        STAIRS = 4 ///< ��������
    };

    Build_Parts Part; ///< ��� ��������
};
