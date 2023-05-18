#ifndef FILEOBSERVER_H
#define FILEOBSERVER_H

class FileObserver : public IObserver {
private:
    long _size = -1; //размер файла. -1 если файл не существует
    bool _exist = 0;//файл не существует
public slots:
    void updateSize(long size) ;//переопределены
    void updateExist(bool exist);//Переопределяем метод
};

#endif //FILEOBSERVER_H
