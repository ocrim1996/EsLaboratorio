//
// Created by Mirco Ceccarelli on 27/07/17.
//

#ifndef ESLABORATORIO_SUBJECT_H
#define ESLABORATORIO_SUBJECT_H

#include "Observer.h"

class Subject {
protected:
    virtual ~Subject() { }
public:
    virtual void registerObserver(Observer * o) = 0;
    virtual void removeObserver(Observer * o) = 0;
    virtual void notifyObservers() const = 0;
};

#endif //ESLABORATORIO_SUBJECT_H
