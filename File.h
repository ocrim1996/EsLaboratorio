//
// Created by Mirco Ceccarelli on 27/07/17.
//

#ifndef ESLABORATORIO_FILE_H
#define ESLABORATORIO_FILE_H

#include <string>
#include <iostream>

using namespace std;

class File {
public:
    explicit File(const char* filename);
    ~File();

    int getSizeInBytes() const {
        return sizeInBytes;
    }

private:
    int sizeInBytes;
    FILE* file;
};


#endif //ESLABORATORIO_FILE_H
