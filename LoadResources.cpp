//
// Created by Mirco Ceccarelli on 27/07/17.
//

#include "LoadResources.h"

LoadResources::LoadResources() : numberOfResources(0) {
}

void LoadResources::registerObserver(Observer *o) {
    observers.push_back(o);
}

void LoadResources::removeObserver(Observer *o) {
    observers.remove(o);
}

void LoadResources::notifyObservers() const {
    for (const auto &itr : observers) {
        itr->update();
    }
}

void LoadResources::load(std::vector<const char *> filenames) throw(runtime_error) {

    try {
        numberOfResources = static_cast<int>(filenames.size());
        if (!numberOfResources) {
            throw runtime_error("Risorse non trovate");
        }
    } catch(runtime_error& e) {
        cerr << e.what() << endl;
    }

    for (auto& itr : filenames) {
        handleFile(itr);
    }
}

void LoadResources::handleFile(const char * itr) {
    try {

        File file(itr);

        filename = QString(itr);
        filesize = file.getSizeInBytes();
        loaded = true;
        notifyObservers();

    } catch(runtime_error& e) {

        cerr << e.what() << endl << endl;

        filename = QString(itr);
        loaded = false;
        notifyObservers();

    } catch(...) {
        cerr << "Eccezione Sconosciuta!" << endl;
    }
}