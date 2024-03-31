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
int Compare(LString *s,LString *t)
{
    chunk *p=s->head,*q=t->head;
    while(p!=NULL && q!=NULL)
    {
        if(p->ch[0]>q->ch[0])return 1;
        else if(p->ch[0]<q->ch[0])return -1;
        p=p->next;
        q=q->next;
    }
    if(p==NULL && q==NULL) return 0;
    else if(p==NULL) return -1;
    else return 1;
}
int main() {
    LString *s=(LString *)malloc(sizeof(LString)),*t=(LString *)malloc(sizeof(LString));
    init(s); init(t);
    char c;
    while((c=getchar())!=' '&&c!=EOF)StrInsert(s,c);
    while((c=getchar())!='\n'&&c!=EOF)StrInsert(t,c);
    printf("%d\n",Compare(s,t));
    return 0;
}