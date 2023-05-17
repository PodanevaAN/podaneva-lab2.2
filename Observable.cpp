#include "Observable.h"
#include "algorithm"

void Observable::attach(IObserver *observer) {
    observers.push_back(observer); //Добавляет нового наблюдателя
     QObject::connect(this,&Observable::notifySize,observer,&IObserver::update);
}

void Observable::detach(IObserver *observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end()); //Удаляет наблюдателя
}

void Observable::notify(long size) { //Оповещает всех наблюдателей
//    for (const auto &observer: observers) { //Провходит по всем наблюдателям из вектора
//        if (observer != nullptr) { //Если наблюдатель не нулевой
//            observer->update(size); //Вызываем функцию для обновления информации
//        }
//    }
    emit notifySize(size);
}
