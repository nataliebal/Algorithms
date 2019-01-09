//
// Created by oriya on 1/3/19.
//

#ifndef UNTITLED9_SOLVERSEARCHER_H
#define UNTITLED9_SOLVERSEARCHER_H

#include "Solver.h"
#include "Searcher.h"

class SolverSearcher: public Solver<class Problem,class Solution>{
    Searcher<Problem,Solution> searcher;
public:
    Solution solve(Problem problem) override;
};
#endif //UNTITLED9_SOLVERSEARCHER_H
