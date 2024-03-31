#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define CHUNKSIZE 1
typedef struct Chunk{
    char ch[CHUNKSIZE];
    struct Chunk *next;
}chunk;
typedef struct{
    struct Chunk *head;
    struct Chunk *tail;
    int length;
} LString;
void init(LString *str){
    str->head=str->tail=NULL;
    str->length=0;
}
void StrInsert(LString *str,char c)
{
    if(str->head==NULL)
    {
        str->head=(chunk *)malloc(sizeof(chunk));
        str->head->next=NULL;
        str->tail=str->head;
        str->head->ch[0]=c;
        str->length++;
        return;
    }
    chunk *p=str->head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    chunk *q=(chunk *)malloc(sizeof(chunk));
    q->next=NULL;
    q->ch[0]=c;
    p->next=q;
    str->tail=q;
    str->length++;
    return;
}
struct node{
    char ch;
    int first_pos;
    struct node *next;
};
LString *Strdelete(LString *str,char ch)
{
    chunk *p=str->head;
    if(p==NULL || str->length==0)return str;
    while(str->length>0 && p->ch[0]==ch)
    {
        str->head=str->head->next;
        free(p);
        p=str->head;
        str->length--;
    }
    while(str->length>0 && p!=NULL && p->next!=NULL)
    {
        if(p->next->ch[0]==ch)
        {
            chunk *q=p->next->next;
            free(p->next);
            p->next=q;
            str->length--;
            //putchar(ch);
        }
        else p=p->next;
    }
    p=str->head;
    while(str->length>0 && p!=NULL && p->next!=NULL)
    {
         
         //putchar(p->ch[0]);
         p=p->next;
         
    }
    //putchar('\n');
    str->tail=p;
    return str;
}
LString *Strcopy(LString *str)
{
    LString *p=(LString *)malloc(sizeof(LString));
    init(p);
    chunk *q=str->head;
    while(q!=NULL)
    {
        StrInsert(p,q->ch[0]);
        q=q->next;
    }
    return p;
}
LString *Compare(LString *s,LString *t)
{
    chunk *p=t->head;
    LString *s2=Strcopy(s);
    while(p!=NULL)
    {
        s2=Strdelete(s2,p->ch[0]);
        p=p->next;
    }
    return s2;
}
int Strfind(LString *str,char ch)
{
    chunk *p=str->head;
    int temp=0;
    while(p!=NULL)
    {
        if(p->ch[0]==ch)return temp;
        p=p->next;
        temp++;
    }
    return -1;
}
int main() {
    LString *s=(LString *)malloc(sizeof(LString)),*t=(LString *)malloc(sizeof(LString));
    init(s); init(t);
    char c;
    while((c=getchar())!=' '&&c!=EOF)StrInsert(s,c);
    while((c=getchar())!='\n'&&c!=EOF)StrInsert(t,c);
    LString *s2=Compare(s,t);
    if(s2->length==0)puts("-1");
    else
    {
        //printf("%d\n",s2->length);
        int a[1005],temp=0;
        while(s2->length!=0)
        {
            putchar(s2->head->ch[0]);
            a[temp++]=Strfind(s,s2->head->ch[0]);
            s2=Strdelete(s2,s2->head->ch[0]);
        }
        putchar(' ');
        //printf("%d\n",temp);
        for(int i=0;i<temp;i++)printf("%d",a[i]);
        putchar('\n');
    }
    //  //printf("%d\n",str->length);

    return 0;
}