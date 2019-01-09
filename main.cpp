#include <iostream>
#include "MySerialServer.h"
#include "StringReverseCH.h"

int main() {
    MySerialServer s = MySerialServer();
    ClientHandler *c = new StringReverseCH();
    s.open(5400, c);
    pthread_exit(NULL);
    return 0;
}