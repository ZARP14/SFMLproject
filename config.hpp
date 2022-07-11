#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <fstream>

class Config
{
public:
    /////////////////////функция для удобного использования конфигов/////////////////////
    struct result //в зависимости от типа данных которомуты присваиваешь функцию он возвращает необходимый тип данных, но их надо прописывать в этой структуре
    { //то есть если я int bebra = getConfigFunction() мне вернётся int а если буду присваивать переменной типа стринг то мне вернётся стринг
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
    /////////////////////функция для удобного использования конфигов/////////////////////
};

#endif // !CONFIG_HPP