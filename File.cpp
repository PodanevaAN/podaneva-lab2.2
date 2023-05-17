#include "File.h"
#include "sys/stat.h"

File::File(const std::string &name) {
    _name = name;
}

void File::checkFile() {
    struct stat buff;
    bool exist = stat(_name.c_str(), &buff) == 0; //Узнаем существует ли файл

    if (exist) { //Если файл существует
        long size = buff.st_size; //Получаем новый размер файла
        if (!_exist || _size != size) { //Если прошлые данные не совпадают с новыми, значит состояние файла изменилось
            _size = size; //Запоминаем новый размер файла
            notify(_size); //Оповещаем наблюдателй
        }
    } else if (_exist) { //Если файл не существует, но существовал раньше
        notify(-1); //Оповещаем что файл не существует
    }

    _exist = exist;
}
