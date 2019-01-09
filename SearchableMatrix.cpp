//
// Created by oriya on 1/9/19.
//

#include "SearchableMatrix.h"

SearchableMatrix::SearchableMatrix(State<Point> *innitialState, State<Point> *goalState,
                                   vector<vector<State<Point> *>> searchable) : Searchable(innitialState, goalState,
                                                                                   searchable) {

}

State<Point> *SearchableMatrix::getInitialState() {
    return this->innitialState;
}

State<Point> *SearchableMatrix::getGoalState() {
    return this->goalState;
}

//TODO
vector<State<Point >> SearchableMatrix::getAllPossibleStates(State<Point> s) {
    return vector<State<Point>>();
}

Matrix<State<Point>> *SearchableMatrix::getMatrix() const {
    return this->matrix;
}

void SearchableMatrix::setMatrix(Matrix<State<Point>> *matrix) {
    SearchableMatrix::matrix = matrix;
}
