#ifndef FILE_H
#define FILE_H


#include <string>
#include "Observable.h"

class File : public Observable {
private:
    std::string _name;
    bool _exist = false;
    long _size = -1;

public:
    explicit File(const std::string &name);

    void checkFile(); //Метод проверки информации по файлу
};


#endif //FILE_H
