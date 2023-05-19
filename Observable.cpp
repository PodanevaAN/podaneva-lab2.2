#include "Observable.h"
#include "algorithm"

void Observable::attach(IObserver *observer) {
    observers.push_back(observer); //Добавляет нового наблюдателя
     QObject::connect(this,&Observable::signalSize,observer,&IObserver::updateSize); //Устанавливает связь между сигналом и слотом updateSize у каждого наблюдателя
     QObject::connect(this,&Observable::signalExist,observer,&IObserver::updateExist);//Устанавливает связь между сигналом и слотом updateExist у каждого наблюдателя

}

void Observable::detach(IObserver *observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end()); //Удаляет наблюдателz
    QObject::disconnect(this,&Observable::signalSize,observer,&IObserver::updateSize);
    QObject::disconnect(this,&Observable::signalExist,observer,&IObserver::updateExist);

}

void Observable::send(long size, bool exist) { //Оповещает всех наблюдателей
//    for (const auto &observer: observers) { //Провходит по всем наблюдателям из вектора
//        if (observer != nullptr) { //Если наблюдатель не нулевой
//            observer->update(size); //Вызываем функцию для обновления информации
//        }
//    }
    emit signalSize(size); //Испускает сигнал signalSize с переданным размером, который будет обработан наблюдателями
    emit signalExist(exist); //Испускает сигнал signalExist с переданным наличием, который будет обработан наблюдателями
}

  
