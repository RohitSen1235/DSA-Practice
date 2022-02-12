#include "stack.h"

int main ()
{
    Stack S;
    
    for( int i=0;i<4;i++)
    {
        S.push(i+1);
    }
    
    S.display();
    S.pop();
    S.display();
    S.pop();
    S.display();
    S.pop();
    S.display();
    S.pop();
    S.display();
    S.pop();
    S.display();
    S.pop();
    S.display();
    return 0;
}