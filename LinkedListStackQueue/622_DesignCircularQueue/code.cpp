#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
    vector<int> data;
    int front, rear, count, k;
public:
    MyCircularQueue(int k) : data(k), front(0), rear(0), count(0), k(k) {}

    bool enQueue(int value) {
        if (isFull()) return false;
        data[rear] = value;
        rear = (rear + 1) % k;
        count++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % k;
        count--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return data[front];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return data[(rear - 1 + k) % k];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == k;
    }
};