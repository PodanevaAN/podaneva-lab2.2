#ifndef IOBSERVER_H
#define IOBSERVER_H
#include <QObject>

class IObserver : public QObject  { // Определение интерфейса IObserver, который наследует от класса QObject
    Q_OBJECT
public slots:
    virtual void update(long size) = 0; //Виртуальный общий метод для всех наблюдателей
};

#endif //IOBSERVER_H
