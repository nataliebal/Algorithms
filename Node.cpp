//
// Created by oriya on 1/8/19.
//

#include "Node.h"

double Node::getValue() const {
    return value;
}

void Node::setValue(double value) {
    Node::value = value;
}

const std::vector<Node *> &Node::getAdjusters() const {
    return adjusters;
}

void Node::setAdjusters(const std::vector<Node *> &adjusters) {
    Node::adjusters = adjusters;
}
