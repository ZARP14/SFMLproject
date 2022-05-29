#include "program.hpp"

#include <windows.h>
#undef min
#undef max

std::string 
Program::path()
{
    CHAR buffer[MAX_PATH] = { 0 };
    int size = GetModuleFileNameA(NULL, buffer, MAX_PATH);
    for (int i = 0; i < 2; ++i) while (buffer[--size] != L'\\');
    buffer[size + 1] = 0;
    return std::string(buffer);
}

