#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <QObject>
#include <vector>
#include "IObserver.h"

class Observable : public QObject { // Определение класса Observable, который наследует от класса QObject
    Q_OBJECT
private:
    std::vector<IObserver*> observers;

public:
    void attach(IObserver *observer);

    void detach(IObserver *observer);

    void notify(long size);
signals:
    void notifyExist(bool exist); // Сигнал, испускающий информацию о существовании файла (true - файл существует, false - файл не существует)
    void notifySize (long size); // Сигнал, испускающий информацию о размере файла
};


#endif //OBSERVABLE_H
