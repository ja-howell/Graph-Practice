// File: Queue.h

#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include <iostream>
using namespace std;

class Queue {
private:

    
public:
    Queue();
    virtual ~Queue();

    virtual string toString() const;
};// end Queue

ostream& operator <<(ostream& os, const Queue& o);

#endif