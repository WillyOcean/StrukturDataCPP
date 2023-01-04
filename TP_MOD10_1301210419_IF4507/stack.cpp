#include "stack.h"

void createStack(stack &s){
    top(s) = 0;
}

bool isEmpty(stack s){
    if (top(s) == 0){
        return true;
    }else{
        return false;
    }
}

bool isFull(stack s){
    return(top(s) == 15);
}

void push(stack &s, infotype x){
    if (isFull(s)){
        cout << "Stack Penuh" << endl;
    }else{
        top(s) = top(s) + 1;
        info(s)[top(s)] = x;
    }
}

int pop(stack &s){
    infotype x;
    x = info(s)[top(s)];
    top(s) = top(s) - 1;
    return x;
}

void printInfo(stack s){
    int i;
    i = top(s);

    while (i >= 1){
        cout << info(s)[i] << endl;
        i--;
    }

}
