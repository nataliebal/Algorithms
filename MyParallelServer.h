//
// Created by oriya on 1/3/19.
//

#ifndef UNTITLED9_MYPARALLELSERVER_H
#define UNTITLED9_MYPARALLELSERVER_H

#include "Server.h"

class MyParallelServer: public Server{
public:
    void open(int port, ClientHandler* clientHandler) override;

    bool stop() override;

    static void* start(void* myParams);
};
#endif //UNTITLED9_MYPARALLELSERVER_H
