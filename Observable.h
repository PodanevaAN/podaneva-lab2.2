#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <QObject>
#include <vector>
#include "IObserver.h"

class Observable : public QObject {
    Q_OBJECT
private:
    std::vector<IObserver*> observers;

public:
    void attach(IObserver *observer);

    void detach(IObserver *observer);

    void notify(long size);
signals:
    void notifyExist(bool exist);
    void notifySize (long size);
};


#endif //OBSERVABLE_H
