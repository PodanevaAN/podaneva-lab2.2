#include "File.h"
#include "sys/stat.h"

File::File(const std::string &name) {// Определение конструктора класса File, принимающего строку в качестве аргумента
    _name = name;// Присваивание значению переменной _name переданную строку
}

void File::checkFile() {
    struct stat buff;
    bool exist = stat(_name.c_str(), &buff) == 0; //Узнаем существует ли файл

    if (exist) { //Если файл существует
        long size = buff.st_size; //Получаем новый размер файла
        if (!_exist || _size != size) { //Если прошлые данные не совпадают с новыми, значит состояние файла изменилось
            _size = size; //Запоминаем новый размер файла
            send(_size,exist); //Оповещаем наблюдателй
        }
    } else if (_exist) { //Если файл не существует, но существовал раньше
        send(-1,exist); //Оповещаем что файл не существует

    }

    _exist = exist;

}
