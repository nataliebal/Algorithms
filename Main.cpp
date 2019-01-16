//
// Created by oriya on 1/15/19.
//

#include "Main.h"
#include "FileCacheManager.h"
#include "MyClientHandler.h"
#include "MyParallelServer.h"
#include "string"
#include "SolverSearcher.h"

using namespace std;

void Main::run() {
    c = new MyClientHandler(cacheManager);
    server->open(5400, c);
}


int Main::getNumberOfNodesEvaluated(string path) {
    if (path == "") return -1;

    vector<string> sep_lines;
    std::string delimiter = ",";

    size_t pos = 0;
    std::string token;
    while ((pos = path.find(delimiter)) != std::string::npos) {
        token = path.substr(0, pos);
        sep_lines.push_back(token);
        path.erase(0, pos + delimiter.length());
    }
    return sep_lines.size() + 1;
}

Main::~Main() {
    server->stop();
    delete (this->cacheManager);
    delete (this->c);
    delete (this->server);
}

Main::Main() {
    this->cacheManager = new FileCacheManager();
    this->server = new MyParallelServer();
}
