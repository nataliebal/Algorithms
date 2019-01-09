//
// Created by oriya on 1/3/19.
//

#ifndef UNTITLED9_FILECACHEMANAGER_H
#define UNTITLED9_FILECACHEMANAGER_H

#include <map>
#include <fstream>
#include "CacheManager.h"
#include "Stringable.h"


class FileCacheManager: public CacheManager<Stringable,Stringable>{
    map<string,string> myData;
    fstream file;
public:
    FileCacheManager();
    void save(Stringable* problem,Stringable* solution) override;

    bool isProblemExist(Stringable* problem) override;

    Stringable* search(Stringable* problem) override;

    void loadToMap();
    void saveMap();
    void saveObjectInFile(string problem,string solution);
};
#endif //UNTITLED9_FILECACHEMANAGER_H
