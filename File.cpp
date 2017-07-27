//
// Created by Mirco Ceccarelli on 27/07/17.
//

#include "File.h"

File::File(const char *filename) : file(fopen(filename, "r")), sizeInBytes(0) {
    if (!file) {
        throw runtime_error("File non trovato!");
    } else {
        fseek(file, 0, SEEK_END);
        sizeInBytes = static_cast<int>(ftell(file));
        cout << "File " << filename << " aperto con successo, la dimensione è " << sizeInBytes << " bytes." << endl;
    }
}

File::~File() {
    if (fclose(file)) {
        throw runtime_error("Errore chiusura File");
    }
}