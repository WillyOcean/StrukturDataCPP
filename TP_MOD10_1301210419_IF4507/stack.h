#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

#define top(s) s.Top
#define info(s) (s).info
#define nil NULL

typedef char infotype;

struct stack{
    infotype info[15];
    int Top;
};

void createStack(stack &s);
bool isEmpty(stack s);
bool isFull(stack s);
void push(stack &s, infotype x);
int pop(stack &s);
void printInfo(stack s);

#endif // STACK_H_INCLUDED
