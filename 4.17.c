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
int Compare(chunk *p,chunk *q)
{
    while(p!=NULL && q!=NULL)
    {
        if(p->ch[0]>q->ch[0])return 1;
        else if(p->ch[0]<q->ch[0])return -1;
        p=p->next;
        q=q->next;
    }
    if(p==NULL && q==NULL) return 0;
    else if(p==NULL) return -1;
    else return 0;
}
void Replace (LString **str,LString *t,LString *v)
{
    LString *s=*str;
    chunk *p=(chunk *)malloc(sizeof(chunk));
    p->next=s->head;
    p->ch[0]=0;
    while(p!=NULL && p->next!=NULL)
    {
        chunk *q=p->next;
        if(Compare(q,t->head)==0)
        {
            for(int j=0;j< t->length;j++)
            {
                chunk *r=q->next;
                //printf("%c\n",q->ch[0]);
                p->next=r;
                free(q);
                q=r;
                s->length--;
                
            }
            
            chunk *u=v->head;
            
            for(int j=0;j< v->length;j++)
            {
                chunk *r=(chunk *)malloc(sizeof(chunk));
                r->ch[0]=u->ch[0];
                r->next=q;
                p->next=r;
                if(p->ch[0]==0) (*str)->head=p->next;//这句很重要。如果第一个字母被删去的话，那么head就被删了，*str->head变成null，后面会输出乱码。
                p=p->next;
                s->length++;
                u=u->next;
                //putchar(r->ch[0]);
                
            }
            //p=p->next;
        }
        else 
        {
            p=p->next;
        }
    }
}
int main() {
    LString *s=(LString *)malloc(sizeof(LString)),*t=(LString *)malloc(sizeof(LString)),*v=(LString *)malloc(sizeof(LString));
    init(s); init(t); init(v);
    char c;
    while((c=getchar())!='\n'&&c!=EOF&&c!=' ')StrInsert(s,c);
    while((c=getchar())!='\n'&&c!=EOF&&c!=' ')StrInsert(t,c);
    while((c=getchar())!='\n'&&c!=EOF)StrInsert(v,c);
    Replace(&s,t,v);
    chunk *p=s->head;
    //printf("%d\n",s->length);
    while(p!=NULL)
    {
        printf("%c",p->ch[0]);
        p=p->next;
    }
    putchar('\n');

    return 0;
}