//
// Created by oriya on 1/3/19.
//

#ifndef UNTITLED9_SEARCHABLE_H
#define UNTITLED9_SEARCHABLE_H
template<class Node>
class Searchable{
public:
    virtual bool isEqual(Node first,Node second)=0;
    virtual Node getAdjsNode(Node node)=0;
    virtual Node getStartNode()=0;
};
#endif //UNTITLED9_SEARCHABLE_H
