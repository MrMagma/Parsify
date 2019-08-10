//
// Created by Joshua on 8/10/2019.
//

#ifndef PARSIFY_FILEREADINTERFACE_H
#define PARSIFY_FILEREADINTERFACE_H


#include <string>
#include <fstream>

class FileReadInterface {
public:
    explicit FileReadInterface(const std::string& path);
    char operator[](int);
    void close();
    unsigned long long length();
    ~FileReadInterface();
private:
    std::ifstream file;
    std::string buffer = "";
};


#endif //PARSIFY_FILEREADINTERFACE_H
