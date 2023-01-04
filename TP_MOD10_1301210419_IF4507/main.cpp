#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
    stack s;

    createStack(s);

    push(s, 'A');
    push(s, 'T');
    push(s, 'A');
    push(s, 'D');
    push(s, 'R');
    push(s, 'U');
    push(s, 'T');
    push(s, 'K');
    push(s, 'U');
    push(s, 'R');
    push(s, 'T');
    push(s, 'S');

    printInfo(s);

    cout << "Setelah di pop :" << endl;

    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);

    printInfo(s);

    return 0;
}

