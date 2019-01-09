//
// Created by oriya on 1/9/19.
//

#ifndef UNTITLED9_SEARCHABLEMATRIX_H
#define UNTITLED9_SEARCHABLEMATRIX_H

#include "Searchable.h"
#include "Matrix.h"
using Point =std::pair<int, int>;
class SearchableMatrix: public Searchable<Point>{
    Matrix<State<Point>>* matrix;
public:
    SearchableMatrix(State<Point> *innitialState, State<Point> *goalState,
                     vector<vector<State<Point> *>> searchable) ;

    State<Point> *getInitialState() override;

    State<Point> *getGoalState() override;

    virtual vector<State<Point >> getAllPossibleStates(State<Point> s) ;

    Matrix<State<Point>> *getMatrix() const;

    void setMatrix(Matrix<State<Point>> *matrix);


};
#endif //UNTITLED9_SEARCHABLEMATRIX_H

