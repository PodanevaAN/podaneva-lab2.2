#ifndef FILE_H
#define FILE_H


#include <string>
#include "Observable.h"

class File : public Observable {
private:
    std::string _name;// Приватное поле класса, хранящее имя файла
    bool _exist = false;// Приватное поле класса, указывающее, существует ли файл (изначально установлено в false)
    long _size = -1;// Приватное поле класса, хранящее размер файла (изначально установлено в -1)

public:
    explicit File(const std::string &name);// Определение явного конструктора класса, принимающего строку в качестве аргумента

    void checkFile(); //Метод проверки информации по файлу
};


#endif //FILE_H
