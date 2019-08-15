// File: LinkedList.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

template <typename E>
class LinkedList {
private:
    class Node {
        public:
            Node * previous;
            Node * next;
            E element;

            Node(Node * const previous, const E& element, Node * const next) :
                previous(previous), element(element), next(next)
                {}
    };

    Node * head;
    Node * tail;
    int numNodes;
    
public:
    LinkedList() {
        head = new Node(nullptr, E(), nullptr);
        tail = new Node(head, E(), nullptr);
        head->next = tail;
    }// end 

    virtual ~LinkedList() {}// end

    virtual string toString() const {
        ostringstream oss;

        return oss.str();
    }// end
};// end LinkedList

template <typename E>
ostream& operator <<(ostream& os, const LinkedList<E>& o) {
    os << o.toString();
    return os;
}// end <<()

#endif