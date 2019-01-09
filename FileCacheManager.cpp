//
// Created by oriya on 1/3/19.
//

#include "FileCacheManager.h"
#include "MyString.h"

#define END_OF_PROBLEM "$"
#define END_OF_SOLUTION "@"

void FileCacheManager::save(Stringable *problem, Stringable *solution) {
    string str_problem = problem->toString();
    string str_solution = solution->toString();
    //if problem exists
    if (this->myData.count(str_problem)) {
        this->myData.at(str_problem) = str_solution;
    } else
        this->myData.insert(pair<string, string>(str_problem, str_solution));
}

bool FileCacheManager::isProblemExist(Stringable *problem) {
    string str_problem = problem->toString();
    return this->myData.count(str_problem) != 0;
}

Stringable *FileCacheManager::search(Stringable *problem) {

    if (isProblemExist(problem)) {
        
        return new MyString(this->myData.at(problem->toString()));
    }
}

void FileCacheManager::loadToMap() {
    this->file = fstream();
    this->file.open("blut.txt", ios::in|ios::out);
    if (!this->file) perror("cannot open file!");
    string line;
    bool isProblem = true;
    string problem;
    string solution;
    while (getline(this->file, line)) {
        if (line == END_OF_SOLUTION) {
            this->myData.insert(pair<string, string>(problem, solution));
            isProblem = true;
            problem = "";
            solution = "";
            continue;
        }
        if (line == END_OF_PROBLEM) {
            isProblem = false;
            continue;
        }
        if (isProblem) problem += line;
        else solution += line;
    }
}

FileCacheManager::FileCacheManager() {
    loadToMap();
}

void FileCacheManager::saveMap() {
    this->file.open("blut.txt", ios::app);
    for (pair<string, string> pr_sl:this->myData) {
        saveObjectInFile(pr_sl.first, pr_sl.second);
    }
}

void FileCacheManager::saveObjectInFile(string problem, string solution) {
    this->file << problem << endl;
    this->file << END_OF_PROBLEM << endl;
    this->file << solution << endl;
    this->file << END_OF_SOLUTION << endl;
}
