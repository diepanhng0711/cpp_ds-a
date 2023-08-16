#include<bits/stdc++.h>
#include<stdlib.h>

#define MAX 10

using namespace std;

class Queue {
    private:
        int items[MAX];
        int front;
        int rear;
    
    public:
        Queue() {
            this->front = -1;
            this->rear = -1;
        }

    bool isFull() {
        if (this->front == 0 && this->rear == MAX -1) return true;
        return false;
    }

    bool isEmpty() {
        if (this->front == -1) return true;
        return false;
    }

    void enQueue(int element) {
        if(isFull()) {
            cout << "Queue is full";
        } else {
            if (this->front == -1) this->front = 0;
            this->rear++;
            this->items[rear] = element;
            cout << endl << element << " is inserted" << endl;
        }
    }

    int deQueue() {
        int element;
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        } else {
            element = this->items[this->front];
            if (this->front >= this->rear) {
                this->front = -1;
                this->rear = -1;
            } else {
                front++;
            }
            cout << endl << "Deleted -> " << element << endl;
            return element;
        }
    }

    void display() {
        int i;
        if (isEmpty()) {
            cout << endl << "Empty Queue" << endl;
        } else {
            cout << endl << "Front index-> " << front;
            cout << endl << "Items -> ";
            for (i = front; i <= rear; i++) cout << items[i] << "  ";
            cout << endl << "Rear index-> " << rear << endl;
        }
    }
};