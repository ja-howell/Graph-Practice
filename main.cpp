// File: main.cpp

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList<int> myList;
    int listData;

    listData = myList.popFront();
    cout << "popFront" << endl;
    cout << listData << endl 
         << myList << endl;

    listData = myList.popBack();
    cout << "popBack" << endl;
    cout << listData << endl 
         << myList << endl;

    myList.pushAt(1,1);
    cout << "pushAt" << endl;
    cout << myList << endl;

    cout << "getFront" << endl;
    cout << myList.getFront() << endl;
    cout << "getBack" << endl;
    cout << myList.getBack() << endl;
    cout << "getAt" << endl;
    cout << myList.getAt(0) << endl;

    myList.pushFront(2);
    cout << "getFront" << endl;
    cout << myList.getFront() << endl;
    cout << "getBack" << endl;
    cout << myList.getBack() << endl;
    myList.pushFront(3);
    myList.pushBack(4);
    cout << myList << endl;

    myList.pushAt(1,5);
    cout << myList << endl;
    myList.pushAt(0,6);
    listData = myList.popAt(3);
    cout << listData << endl 
         << myList << endl;

    myList.pushAt(4, 7);
    cout << myList << endl;

    listData = myList.popFront();
    cout << listData << endl 
         << myList << endl;

    listData = myList.popBack();
    cout << listData << endl 
         << myList << endl;

    listData = myList.popAt(5);
    cout << listData << endl 
         << myList << endl;

    cout << myList.getAt(2) << endl;

    LinkedList<int> copyList(myList);

    cout << myList << endl
         << copyList << endl;
    
    copyList.pushFront(1);
     cout << myList << endl
          << copyList << endl;   
    
    return 0;
}// end main()