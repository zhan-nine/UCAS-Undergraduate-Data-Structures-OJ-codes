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
LString *Strreverse(LString *str)
{
    int len=str->length;
    LString *str1=(LString *)malloc(sizeof(LString));
    init(str1);
    for(int i=len-1;i>=0;i--)
    {
        chunk *p=str->head;
        for(int j=0;j<i;j++)
        {
            p=p->next;
        }
        //printf("%c",p->ch[0]);
        StrInsert(str1,p->ch[0]);
        free(p);
    }
    free(str);
    return str1;
}
int main() {
    LString *str=(LString *)malloc(sizeof(LString));
    init(str);
    char c;
    while((c=getchar())!='\n'&&c!=EOF)StrInsert(str,c);
    str=Strreverse(str);

    chunk *p=str->head;
    while(p!=NULL)
    {
        for(int i=0;i<CHUNKSIZE;i++)
        {
            printf("%c",p->ch[i]);
        }
        p=p->next;
    }
    putchar('\n');//你妈妈的，一定要读回车符不然WA？？？？？
    //  //printf("%d\n",str->length);

    return 0;
}