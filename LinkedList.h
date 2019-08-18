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

    Node * head = nullptr;
    Node * tail = nullptr;
    int numNodes = 0;
    
public:
    LinkedList() {
        head = new Node(nullptr, E(), nullptr);
        tail = new Node(head, E(), nullptr);
        head->next = tail;
    }// end 

    virtual ~LinkedList() {}// end

    void pushFront(const E& element){
        Node * tempNode = new Node(head, element, head->next);
        head->next->previous = tempNode;
        head->next = tempNode;
        numNodes++;
    }

    void pushBack(const E& element){
        Node * tempNode = new Node(tail->previous, element, tail);
        tail->previous->next = tempNode;
        tail->previous = tempNode;
        numNodes++;
    }

    void pushAt(const int index, const E& element){
       Node * place;
       if(index < 0 || index > numNodes){
           cout << "Error: index out of bounds" << endl;
           return;
       }
       if(index <= (numNodes/2)){
           place = head->next;
           for(int move = 0; move < index; move++){
               place = place->next;
           }
       }
       else{
           place = tail;
            for(int move = numNodes; move > index; move--){
                place = place->previous;
            }
       }
       Node * temp = new Node(place->previous, element, place);
       place->previous->next = temp;
       place->previous = temp;
       numNodes++;

    }

    E popFront(){
        if(numNodes <= 0){
            cout << "List is Empty" << endl;
            return -1;
        }

        Node * delNode = head->next;
        E removedElem = delNode->element;

        head->next = delNode->next;
        delNode->next->previous = head;

        delete delNode;
        delNode = nullptr;
        numNodes--;

        return removedElem;

    }

    E popBack(){
        if(numNodes <= 0){
            cout << "List is Empty" << endl;
            return -1;
        }

        Node * delNode = tail->previous;
        E removedElem = delNode->element;

        tail->previous = delNode->previous;
        delNode->previous->next = tail;

        delete delNode;
        delNode = nullptr;
        numNodes--;

        return removedElem;

    }

    E popAt(const int index){
        if(numNodes <= 0){
            cout << "List is Empty" << endl;
            return -1;
        }
        if(index < 0 || index > numNodes){
            cout << "Error: index out of bounds" << endl;
            return -1;
        }

        Node * delNode;

       if(index <= (numNodes/2)){
           delNode = head->next;
           for(int move = 0; move < index; move++){
               delNode = delNode->next;
           }
       }
       else{
           delNode = tail->previous;
            for(int move = numNodes - 1; move > index; move--){
                delNode = delNode->previous;
            }
       }

       E removedElem = delNode->element;
       delNode->previous->next = delNode->next;
       delNode->next->previous = delNode->previous;

        delete delNode;
        delNode = nullptr;
        numNodes--;

        return removedElem;
    }

    E getFront(){
        if(numNodes <= 0){
            cout << "List is Empty" << endl;
            return -1;
        }
        return head->next->element;
    }

    E getBack(){
        if(numNodes <= 0){
            cout << "List is Empty" << endl;
            return -1;
        }
        return tail->previous->element;
    }

    E getAt(const int index){
        if(numNodes <=0){
            cout << "List is Empty" << endl;
            return -1;            
        }
        if(index < 0 || index > numNodes){
            cout << "Error: index out of bounds" << endl;
            return -1;
        }
        Node * curNode;
        if(index <= (numNodes/2)){
           curNode = head->next;
           for(int move = 0; move < index; move++){
               curNode = curNode->next;
           }
       }
       else{
           curNode = tail->previous;
            for(int move = numNodes - 1; move > index; move--){
                curNode = curNode->previous;
            }
       }

       return curNode->element;

    }

    virtual string toString() const {
        ostringstream oss;
        oss << "[ ";
        Node * iter = head->next;
        while ( iter != tail ) {
            oss << iter->element << ", ";
            iter = iter->next;
        }
        oss << "]";
        return oss.str();
    }// end
};// end LinkedList

template <typename E>
ostream& operator <<(ostream& os, const LinkedList<E>& o) {
    os << o.toString();
    return os;
}// end <<()

#endif