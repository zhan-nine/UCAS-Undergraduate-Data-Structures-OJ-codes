#include <stdio.h>
#include <stdlib.h>
char stack[1005];
int t=0;
void push(char x)
{
    stack[t++]=x;
}
char pop()
{
    if(t==0)
    {
        printf("0\n");
        exit(0);
    }
    return stack[--t];
}
char s[1005];
int main() {
    scanf("%s", s);
    int temp=0;
    while(s[temp]!='&') push(s[temp++]);
    temp++;
    while(s[temp]!='@')
    {
        if(s[temp++]==pop())continue;
        printf("0\n");
        return 0;
    }
    if(t!=0)printf("0\n");
    else printf("1\n");
    return 0;
}