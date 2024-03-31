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
bool Strisasymmetric(LString *str)
{
    chunk *p=str->head;
    int t=1;
    while(t<=str->length/2)
    {
        chunk *q=str->head;
        for(int i=0;i<str->length-t;i++)
        {
            q=q->next;
        }
        //printf("%c %c\n",p->ch[0],q->ch[0]);
        if(p->ch[0]!=q->ch[0])
        {
            return false;
        }
        p=p->next;
        t++;
    }
    return true;
}
int main() {
    int n;
    scanf("%d",&n);
    LString *str=(LString *)malloc(sizeof(LString));
    init(str);
    for(int i=1;i<=n;i++)
    {
        char c;
        while((c=getchar())==' '||c=='\n');
        StrInsert(str,c);
    }
    // chunk *p=str->head;
    //  while(p!=NULL)
    //  {
    //      for(int i=0;i<CHUNKSIZE;i++)
    //      {
    //          printf("%c",p->ch[i]);
    //      }
    //      p=p->next;
    //  }
    //  //printf("%d\n",str->length);
    if(Strisasymmetric(str))
    {
        puts("1");
    }
    else
    {
        puts("0");
    }
    return 0;
}