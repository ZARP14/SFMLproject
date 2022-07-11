#include "config.hpp"

Config::result
Config::getConfigFunction(std::ifstream& file)
{
    std::string s;
    std::getline(file, s, ':');


    result r;
    file >> r.res;
    return r;
}