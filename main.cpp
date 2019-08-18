// File: main.cpp

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList<int> myList;
    int listData;

    listData = myList.popFront();
    cout << listData << endl 
         << myList << endl;
    listData = myList.popBack();
    cout << listData << endl 
         << myList << endl;
    myList.pushAt(1,1);
    cout << myList << endl;
    myList.pushFront(2);
    myList.pushFront(3);
    myList.pushBack(4);
    cout << myList << endl;
    myList.pushAt(1,5);
    myList.pushAt(0,6);
    myList.pushAt(5, 7);
    cout << myList << endl;
    listData = myList.popFront();
    cout << listData << endl 
         << myList << endl;
    listData = myList.popBack();
    cout << listData << endl 
         << myList << endl;

    cout << myList << endl;
    
    return 0;
}// end main()