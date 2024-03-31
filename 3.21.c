#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
char st[1005];
int top=0;
void push(char *s,int x)
{
    s[top++]=x;
}
char pop(char *s)
{
    if(top>0)
    {
        top--;
    }
    else
    {
        printf("error\n");
        exit(0);
    }
    return s[top];
}
char s[1005];
int main() {
    scanf("%s",s);
    int i=0;
    bool flag=0;
    while(s[i]!='\0')
    {
        if(isalpha(s[i]))
        {
            putchar(s[i]);
        }
        else if(s[i]=='+' || s[i]=='-')
        {
            if(top!=0 && !flag)
            {
                while(top>0)
                {
                    if(st[top-1]=='(')
                    {
                        pop(st);
                        continue;
                    }
                    putchar(pop(st));

                }
                
            }
            push(st,s[i]);
        }
        else if(s[i]=='*' || s[i]=='/')
        {
            if (!(top==0 || st[top-1]=='+' || st[top-1]=='-') && !flag)
            {
                while(top>0 && (st[top-1]=='*' || st[top-1]=='/'))
                {
                    putchar(pop(st));
                }
                
            }
            push(st,s[i]);
        }
        else if(s[i]=='(')
        {
            push(st,s[i]);
            flag=1;
        }
        else if(s[i]==')')
        {
            while(top)
            {
                if(st[top-1]=='(')
                {
                    pop(st);
                    break;
                }
                putchar(pop(st));
            }
            flag=0;
        }
        i++;
    }
    while(top>0)
    {
        putchar(pop(st));
    }
    return 0;
}