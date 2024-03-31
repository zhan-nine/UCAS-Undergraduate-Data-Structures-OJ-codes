#include <stdio.h>
#include <stdbool.h>
char s[1005];
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
        return 0;
    }
    return s[top];
}
int read(char *s)
{
    int i=0;
    char c;
    while(c=getchar(),c=='\n'||c==' ');
    if(c==EOF)return 0;
    do
    {
        s[i++]=c;
        if(c=='@')return i;
    }while((c=getchar())!=EOF);
    if(c==EOF)return 0;
    return i;
}
int main() {
    bool flag=0;
    int len;
    while(len=read(s))
    {
        flag=0;
        //printf("%d\n",len);
        int len1;
        if(len%2==0)len1=len/2-1;
        else len1=len/2;
        for(int i=0;i<len1;i++)
        {
            push(st,s[i]);
        }
        int p=len/2;
        //printf("%d\n",p);
        for(int i=p;i<len-1;i++)
        {
            if(top && pop(st)==s[i])
            {
                continue;
            }
            else
            {
                flag=1;
                break;
            }
        }
        if(!flag)puts("1");
        else puts("0");
    }
    return 0;
}