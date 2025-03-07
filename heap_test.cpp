#include "heap.h"
#include <iostream>
#include <fstream>
#include <functional>
using namespace std;

int main(int argc, char* argv[])
{
    //std::less c1;
    Heap<int, std::less<int>> test;
    test.push(6);
    cout << test.top() << endl;
    test.push(3);
    cout << test.top() << endl;
    test.push(5);
    cout << test.top() << endl;
    test.push(1);
    cout << test.top() << endl;
    test.push(4);
    cout << test.top() << endl;
    test.push(2);
    cout << test.top() << endl;
    
    cout << test.top() << endl;
    test.pop();
    cout << test.top() << endl;
    test.pop();
    cout << test.top() << endl;
    test.pop();
    cout << test.top() << endl;
    test.pop();
    cout << test.top() << endl;
    test.pop();
    cout << test.top() << endl;
    test.pop();
}