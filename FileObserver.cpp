#include <iostream>
#include "FileObserver.h"

void FileObserver::updateSize(long size) { //Метод выводит информацию если состояние файла изменилось
    if (_size != size) { //Если предыдущий размер файл не совпадает с новым, значит файл изменился
            if (size == -1) { //Если размер -1 значит файл не существует
                std::cout << "File doesn't exist" << std::endl;
            } else { //Иначе выводим размер файла
                std::cout << "File exists. Size = " << size << std::endl;
            }
            _size = size; //Сохраняем новый размер
        }
}
void FileObserver::updateExist(bool exist) {

        _exist = exist;
}
