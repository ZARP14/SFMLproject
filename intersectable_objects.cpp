#include "intersectable_objects.hpp"

Intersectable_Objects::Intersectable_Objects()

{
    /////////////////////������� ����� ������������ ������ (������� ������ ��������) �� ��� �����/////////////////////
    ColLine_Right = Sprite.getGlobalBounds();
    ColLine_Left = ColLine_Right;
    ColLine_Top = Sprite.getGlobalBounds();
    ColLine_Down = ColLine_Top;
    /////////////////////������� ����� ������������ ������ (������� ������ ��������) �� ��� �����/////////////////////

    /////////////////////�� ��� ������ � ����� ����� ��������/////////////////////
    ColLine_Right.left += ColLine_Right.width - 1;
    ColLine_Right.width = 1;
    ColLine_Left.width = 1;
    ColLine_Right.height -= 10;
    ColLine_Left.height -= 10;
    /////////////////////�� ��� ������ � ����� ����� ��������/////////////////////

    /////////////////////�� ��� ������� � ������ ����� ��������/////////////////////
    ColLine_Down.top += ColLine_Top.height - 1;
    ColLine_Down.height = 1;
    ColLine_Top.height = 1;
    ColLine_Down.width -= 10;
    ColLine_Top.width -= 10;
    /////////////////////�� ��� ������� � ������ ����� ��������/////////////////////
}