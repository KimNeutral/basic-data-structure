//
// Created by kim dae young on 7/23/18.
//

#include <iostream>

#define STACK_MAX 10

using namespace std;

template<typename T>
class ArrayStack {
private :
    T arr[STACK_MAX];
    int top = 0;

public:
    void push(T value) {
        if (top > STACK_MAX - 1) {
            cout << "ArrayStack is full!" << endl;
            return;
        }
        arr[top++] = value;
    }

    T pop() {
        if (top == 0) {
            cout << "ArrayStack is empty!" << endl;
            return NULL;
        }
        return arr[top--];
    }

    T peek() {
        if (top == 0) {
            cout << "ArrayStack is empty!" << endl;
            return NULL;
        }
        return arr[top - 1];
    }
};

int main()
{
    ArrayStack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.push(8);
    stack.push(9);
    stack.push(10);
    stack.push(11);
    stack.pop();

    cout << stack.peek() << endl;

    return 0;
}