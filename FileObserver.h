#ifndef FILEOBSERVER_H
#define FILEOBSERVER_H

#include "IObserver.h"

class FileObserver : public IObserver {
private:
    long _size = -1; //размер файла. -1 если файл не существует

public slots:
    void update(long size) override; //Переопределяем метод
};


#endif //FILEOBSERVER_H
