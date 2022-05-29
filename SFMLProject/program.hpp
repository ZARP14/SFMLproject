#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <string>
#include <iostream>
#include <fstream>

/////////////////////Это нужно для всякого разного с путями/////////////////////
#define CONFIG_PATH Program::path() + "resourse\\config\\"
#define TEXTURE_PATH Program::path() + "resourse\\textures\\"
/////////////////////Это нужно для всякого разного с путями/////////////////////

class Program
{
public:
    /////////////////////для динамического пути папки resourse/////////////////////
    static std::string path();
    /////////////////////для динамического пути папки resourse/////////////////////
};

#endif // !PROGRAM_HPP
