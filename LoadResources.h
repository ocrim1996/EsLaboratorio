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

    bool didLoadFile() const {
        return loaded;
    }

    const QString &getFilename() const {
        return filename;
    }

    int getFilesize() const {
        return filesize;
    }

private:
    list<Observer*> observers;
    int numberOfResources;

    bool loaded;
    QString filename;
    int filesize;

};


#endif //ESLABORATORIO_LOADRESOURCES_H
