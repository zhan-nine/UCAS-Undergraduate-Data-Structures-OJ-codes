#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
char st[1005];
int t=0;
void push(char x)
{
    st[t++]=x;
}
char pop()
{
    if(t==0)
    {
        printf("0\n");
        exit(0);
    }
    return st[--t];
}
char s[1005];
int main() {
    scanf("%s", s);
    int temp=0;
    while(s[temp]!='\0' && s[temp]!='\n')
    {
        if(s[temp]=='(') push(s[temp]);
        else if(s[temp]==')') pop();
        temp++;
    }
    if(t!=0)printf("0\n");
    else printf("1\n");
    return 0;
}