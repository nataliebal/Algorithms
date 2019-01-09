//
// Created by oriya on 1/8/19.
//

#ifndef UNTITLED9_NODE_H
#define UNTITLED9_NODE_H

#include <vector>
using namespace std;
class Node{
    double value;
    vector<Node*> adjusters;
public:
    Node(double value);
    double getValue() const;

    void setValue(double value);

    const vector<Node *> &getAdjusters() const;

    void setAdjusters(const vector<Node *> &adjusters);
};
#endif //UNTITLED9_NODE_H
