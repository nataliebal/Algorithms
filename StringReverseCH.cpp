//
// Created by oriya on 1/3/19.
//

#include "StringReverseCH.h"
#include "StringReverser.h"
#include <iostream>
#include <sys/types.h>
#include <algorithm>
#include <unistd.h>
#include <list>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <iostream>
#include <netinet/in.h>



#define END "end"
pthread_mutex_t lock;

void StringReverseCH::handleClient(int new_socket) {
    //TO DO : WHAT IS THE SIZE OF INPUT?
    char buffer[5000];
    int erez = 0;
    int natalie = 0;
    string str;
    //reads from client as long as input is not stop
    while (str != END) {
        //pthread_mutex_lock(&lock);
       bzero(buffer, sizeof(str));
        erez = read(new_socket, buffer, 5000);
        if (erez < 0) {
            perror("cannot read from client");
        }
        string retStReverse = this->solver->solve(buffer);
        const char *ret = retStReverse.c_str();
        send(new_socket, ret, retStReverse.size(), 0);
         str=buffer;
        //pthread_mutex_unlock(&lock);
    }
}

StringReverseCH::StringReverseCH() {
    this->solver = new StringReverser();
}
