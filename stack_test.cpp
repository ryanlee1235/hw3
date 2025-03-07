#include "stack.h"
#include <iostream>
#include <fstream>
#include <functional>
using namespace std;

int main(int argc, char* argv[])
{
    Stack<int> stack1;
    stack1.push(5);
    stack1.push(4);
    stack1.push(3);
    stack1.push(2);
    cout << stack1.top() << endl;
    cout << "Size: " << stack1.size() << endl;

    stack1.pop();
    cout << stack1.top() << endl;

    stack1.pop();
    cout << stack1.top() << endl;

    stack1.pop();
    cout << stack1.top() << endl;

    stack1.pop();

    /*
    stack1.pop();
    cout << stack1.top() << endl;
    */

    cout << "Empty?: " << stack1.empty() << endl;
    return 0;
}
