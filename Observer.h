//
// Created by Mirco Ceccarelli on 27/07/17.
//

#ifndef ESLABORATORIO_OBSERVER_H
#define ESLABORATORIO_OBSERVER_H

class Observer {
public:
    virtual ~Observer() {};
    virtual void update() = 0;
};

#endif //ESLABORATORIO_OBSERVER_H
