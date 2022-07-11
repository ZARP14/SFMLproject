#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <fstream>

class Config
{
public:
    /////////////////////������� ��� �������� ������������� ��������/////////////////////
    struct result //� ����������� �� ���� ������ ���������� ������������ ������� �� ���������� ����������� ��� ������, �� �� ���� ����������� � ���� ���������
    { //�� ���� ���� � int bebra = getConfigFunction() ��� ������� int � ���� ���� ����������� ���������� ���� ������ �� ��� ������� ������
        std::string res;

        operator int()
        {
            return std::stoi(res);
        }

        operator std::string()
        {
            return res;
        }
        
        operator float()
        {
            return std::stof(res);
        }
    };

    result getConfigFunction(std::ifstream& file);
    /////////////////////������� ��� �������� ������������� ��������/////////////////////
};

#endif // !CONFIG_HPP