#include <iostream>
#include <vector>
#include "MySerialServer.h"
#include "StringReverseCH.h"
#include "FileCacheManager.h"
#include "MatrixBuilder.h"
#include "MyClientHandler.h"


void exit(CacheManager<Stringable, Stringable> *cacheManager);

int main() {
    MySerialServer s = MySerialServer();
    CacheManager<Stringable, Stringable> *cacheManager = new FileCacheManager();
    MyClientHandler *c = new MyClientHandler(cacheManager);
    string prob = "1,2,3\n4,5,6\n5,7,2\n0,0\n2,2 \n";
    c->solveProblem(prob);
//    s.open(5400, c);
    exit(cacheManager);
//    pthread_exit(NULL);
//    vector<vector<double>> v;
//    vector<double> myV;
//    int j = 0;
//    for (double i = 0; i < 3; ++i) {
//        for (j; j < 3; ++j) {
//            myV.push_back(j);
//        }
//        v.push_back(myV);
//    }
//    Point start = Point(0, 0);
//    Point end = Point(2, 2);
//    MatrixBuilder builder = MatrixBuilder();
//    SearchableMatrix searchableMatrix=builder.create(v, start, end);

    return 0;
}

//TODO
//CHECKS WHITCH IS THE FASTEST ALGORITHM
//RUNS ALL THE ALGORITHMS
//checks about goal point
//why does not save in file
void exit(CacheManager<Stringable, Stringable> *cacheManager) {
    ((FileCacheManager *) cacheManager)->saveMap();
}