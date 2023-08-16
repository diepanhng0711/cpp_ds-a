#include "./stack.h"

int main()
{
    int ch;
    Stack *s = (Stack *)malloc(sizeof(Stack));

    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    printStack(s);

    pop(s);

    cout << "\nAfter popping out\n";
    printStack(s);
}