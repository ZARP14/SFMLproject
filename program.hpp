#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <string>
#include <iostream>
#include <fstream>

/////////////////////��� ����� ��� ������� ������� � ������/////////////////////
#define CONFIG_PATH Program::path() + "resourse\\config\\"
#define TEXTURE_PATH Program::path() + "resourse\\textures\\"
/////////////////////��� ����� ��� ������� ������� � ������/////////////////////

class Program
{
public:
    /////////////////////��� ������������� ���� ����� resourse/////////////////////
    static std::string path();
    /////////////////////��� ������������� ���� ����� resourse/////////////////////
};

#endif // !PROGRAM_HPP
