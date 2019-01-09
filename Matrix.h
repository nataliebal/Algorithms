//
// Created by oriya on 1/9/19.
//

#ifndef UNTITLED9_MATRIX_H
#define UNTITLED9_MATRIX_H

#include <vector>
#include "Searchable.h"

using namespace std;
using Point =std::pair<int, int>;

template<class T>
class Matrix {
    vector<vector<State<T>>> matrix;
public:
    Matrix(vector<vector<State<T>>> matrix) {
        this->matrix = matrix;
    }

    State<T> &operator[](Point location) {
        return this->matrix[location.first][location.second];
    }

    const vector<vector<State<T>>> &getMatrix() const {
        return this->matrix;
    }

    void setMatrix(const vector<vector<State<T>>> &matrix) {
        this->matrix = matrix;
    }
};


#endif //UNTITLED9_MATRIX_H
