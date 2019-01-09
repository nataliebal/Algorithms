//
// Created by oriya on 1/3/19.
//

#ifndef UNTITLED9_SEARCHABLE_H
#define UNTITLED9_SEARCHABLE_H

#include "State.h"
#include <vector>

using namespace std;

template<class Node>
class Searchable {
protected:
    State<Node> *innitialState;
    State<Node> *goalState;
    vector<vector<State<Node> *>> searchable;

public:
    Searchable(State<Node> *innitialState, State<Node> *goalState, vector<vector<State<Node>*> > searchable) {
        this->innitialState = innitialState;
        this->goalState = goalState;
        this->searchable = searchable;
    }

    virtual State<Node> *getInitialState() = 0;

    virtual State<Node> *getGoalState() = 0;

    virtual vector<State<Node>> getAllPossibleStates(State<Node> s) = 0;
};

#endif //UNTITLED9_SEARCHABLE_H
