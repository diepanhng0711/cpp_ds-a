#include<bits/stdc++.h>
#include<stdlib.h>

using namespace std;
#define MAX 100

typedef int Eltype;

int size = 0;

//Tạo stack
typedef struct stack_t{
    Eltype items[MAX];
    int top;
} Stack;

void createStack(Stack *s) {
    s->top = -1;
}

bool isFull(Stack *s) {
    return (s->top >= MAX - 1);
}

bool isEmpty(Stack *s) {
    return (s->top == -1);
}

void push(Stack *s, Eltype el) {
    if (isFull(s))  cout << "Stack is full!\n";
    else {
        s->items[++(s->top)] = el;
    }
    size++;
}

Eltype pop(Stack *s) {
    if(isEmpty(s)) {
        cout << "Empty stack!\n";
        return -9999999;
    } else {
        size--;
        return s->items[(s->top)--];
    }
}

Eltype peek(Stack *s) {
    if(isEmpty(s)) {
        cout << "Empty stack!\n";
        return -9999999;
    } else return s->items[s->top];
}

void printStack(Stack *s) {
    cout << "Stack: ";
    for (int i = 0; i < size; i++) {
        cout << s->items[i] << "  ";
    }
    cout << endl;
}