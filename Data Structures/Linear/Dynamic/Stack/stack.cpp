#include<iostream>
using namespace std;

#define MAX 100
int size = 0;

//Khoi tao stack
struct stack_t {
    int items[MAX];
    int top;
};

typedef struct stack_t stack;

void createEmptyStack(stack *s) {
    s->top = -1;
}

//Kiem tra stack da day hay chua
int isFull(stack *s) {
    
}