//
// Created by kim dae young on 7/25/18.
//

#include <iostream>

#define MAX_SIZE 100

using namespace std;

template<typename T>
class ArrayQueue {
private:
    T items[MAX_SIZE];
    int front = 0;
    int rear = 0;
    int count = 0;

public:
    void Enqueue(T value) {
        if (count > MAX_SIZE) {
            cout << "ArrayQueue is full!" << endl;
            return;
        }
        items[rear] = value;
        rear = (rear + 1) % MAX_SIZE;
        count ++;
    }

    T Dequeue() {
        if (count <= 0) {
            cout << "ArrayQueue is empty!" << endl;
            return NULL;
        }

        T value = items[front];

        front = (front + 1) % MAX_SIZE;
        count --;

        return value;
    }

    int Count() {
        return count;
    }
};

int main() {
    ArrayQueue<int> queue;

    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);
    queue.Enqueue(40);
    queue.Enqueue(50);
    queue.Enqueue(60);

    cout << queue.Dequeue() << endl;
    cout << queue.Dequeue() << endl;
    cout << queue.Dequeue() << endl;
    cout << queue.Dequeue() << endl;
    cout << queue.Dequeue() << endl;
    cout << queue.Dequeue() << endl;
    cout << queue.Dequeue() << endl;
    return 0;
}

