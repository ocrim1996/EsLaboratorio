//
// Created by Mirco Ceccarelli on 27/07/17.
//

#ifndef ESLABORATORIO_LOADRESOURCES_H
#define ESLABORATORIO_LOADRESOURCES_H

#include <QApplication>
#include <QProgressBar>
#include <QTimer>
#include <iostream>
#include <QTextEdit>
#include <QPushButton>
#include "File.h"
#include "Subject.h"
#include "Observer.h"

using namespace std;

class LoadResources : public Subject {
public:
    LoadResources();
    void load(std::vector<const char*> filenames) throw(runtime_error);
    void handleFile(const char * itr);

    virtual void registerObserver(Observer *o) override;
    virtual void removeObserver(Observer *o) override;
    virtual void notifyObservers() const override;

    int getNumberOfResources() const {
        return numberOfResources;
    }

private:
    list<Observer*> observers;
    int numberOfResources;


};


#endif //ESLABORATORIO_LOADRESOURCES_H
