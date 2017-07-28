//
// Created by Mirco Ceccarelli on 27/07/17.
//

#ifndef ESLABORATORIO_CONCRETEOBSERVER_H
#define ESLABORATORIO_CONCRETEOBSERVER_H

#include "LoadResources.h"
#include "Observer.h"

class ConcreteObserver : public Observer {
public:
    ConcreteObserver(LoadResources *resources_) : resources(resources_) {
        resources->registerObserver(this);
    }

    virtual ~ConcreteObserver() {
        resources->removeObserver(this);
    }

    virtual void update() override {}

    LoadResources * resources;
};

#endif //ESLABORATORIO_CONCRETEOBSERVER_H
