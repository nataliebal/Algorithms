//
// Created by oriya on 1/3/19.
//

#include "MyClientHandler.h"
#include "SolverSearcher.h"
#include "MatrixBuilder.h"
#include "MyString.h"
#include "Bfs.h"
#include "BestFirstSearch.h"
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


using namespace std;
#define END "end"

MyClientHandler::MyClientHandler(CacheManager<Stringable, Stringable> *cacheManager) {
    this->cacheManager = cacheManager;
    //TODO

//    this->solver = new SolverSearcher();
}


void MyClientHandler::handleClient(int new_socket) {
    //TO DO : WHAT IS THE SIZE OF INPUT?
    char buffer[5000];
    int erez = 0;
    int natalie = 0;
    string str;
    //reads from client as long as input is not stop
    string buff;
    while (str != END) {
        //pthread_mutex_lock(&lock);
        bzero(buffer, sizeof(str));
        erez = read(new_socket, buffer, 5000);
        if (erez < 0) {
            perror("cannot read from client");
        }
        buff += buffer;


        str = buffer;
        //pthread_mutex_unlock(&lock);
    }
    string shortest_path = solveProblem(buff);
    const char *ret = shortest_path.c_str();
    send(new_socket, ret, shortest_path.size(), 0);
}

Solver<Searchable<Point> *, Stringable *> *MyClientHandler::getSolver() const {
    return solver;
}

void MyClientHandler::setSolver(Solver<Searchable<Point> *, Stringable *> *solver) {
    this->solver = solver;
}

CacheManager<Stringable, Stringable> *MyClientHandler::getCacheManager() const {
    return cacheManager;
}

void MyClientHandler::setCacheManager(CacheManager<Stringable, Stringable> *cacheManager) {
    MyClientHandler::cacheManager = cacheManager;
}

string &MyClientHandler::solveProblem(string &problem) {
    Stringable *str = new MyString(problem);
    if (this->getCacheManager()->isProblemExist(str)) {
        return this->getCacheManager()->search(str)->toString();
    }
    string *solution;
    Searchable<Point> *searchable = cast_to_matrix(problem);
//    Searcher<Point> *dfs = new DfsAlgo(((SearchableMatrix *) searchable)->getMatrix()->getNumOfVertex(),
//                                       ((SearchableMatrix *) searchable)->getMatrix()->getNumOfColumns());
    Searcher<Point> *bfs=new BestFirstSearch<Point>();
    this->solver = new SolverSearcher(bfs);
    Stringable *str_able = this->solver->solve(searchable);
    string b=str_able->toString();
    reverse(b.begin(),b.end());
    solution=&b;
    this->cacheManager->save(str, str_able);
    return *solution;
}

Searchable<Point> *MyClientHandler::cast_to_matrix(string &problem) {
    vector<string> problem_lines;
    string my_problem = string(problem);
    char *prob = new char();
    strcpy(prob, my_problem.c_str());
    char *lines = strtok(prob, "\n ");
    vector<string> sep_lines;
    while (lines) {
        sep_lines.push_back(lines);
        lines = strtok(NULL, "\n");
    }
    vector<string>::iterator begin = sep_lines.begin();
    vector<string>::iterator end = sep_lines.end();
    end--;
    end--;
    vector<string> matrix_lines(begin, end);
    vector<vector<double>> num_matrix = cast_to_num_matrix(matrix_lines);
    Point *init;
    init = lexer_point(sep_lines.at(sep_lines.size() - 2));
    Point *goal;
    goal = lexer_point(sep_lines.at(sep_lines.size() - 1));
    MatrixBuilder builder;
    SearchableMatrix *searrchable_matrix = builder.create(&num_matrix, init, goal);
    return searrchable_matrix;
}

vector<vector<double>> &MyClientHandler::cast_to_num_matrix(vector<string> &matrix_lines) {
    vector<vector<double>> *victor = new vector<vector<double>>();
    vector<double> mini_victor;
    char *nums;
    char *nums_sep = new char();
    for (string line:matrix_lines) {
        mini_victor.clear();
        strcpy(nums_sep, line.c_str());
        nums = strtok(nums_sep, ",");
        while (nums) {
            mini_victor.push_back(stod(nums));
            nums = strtok(NULL, ",");
        }

        victor->push_back(mini_victor);
    }
    return *victor;
}

Point *MyClientHandler::lexer_point(string &str) {
    int i = stoi(str.substr(0, str.find(',')));
    int j = stoi(str.substr(str.find(',') + 1));
    Point *p = new Point(i, j);
    return p;
}
