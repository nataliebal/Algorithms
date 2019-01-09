//
// Created by oriya on 1/3/19.
//

#ifndef UNTITLED9_STRINGREVERSECH_H
#define UNTITLED9_STRINGREVERSECH_H

#include "ClientHandler.h"
#include "Solver.h"
#include "string"

using namespace std;

class StringReverseCH : public ClientHandler {
    Solver<string, string> *solver;
public:
    StringReverseCH();

     void handleClient(int socket)override;
};

#endif //UNTITLED9_STRINGREVERSECH_H
