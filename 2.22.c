#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct list{
    char data;
    struct list *next,*front;
}*ha;
struct list *insert(struct list *head,char x)
{
    struct list *p,*q;
    p=(struct list *)malloc(sizeof(struct list));
    p->data=x;
    p->next=NULL;
    p->front=NULL;
    if(head==NULL)
    {
        head=p;
    }
    else
    {
        q=head;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        p->front=q;
        q->next=p;
        
    }
    return head;
}
void print(struct list *head)
{
    struct list *p;
    p=head;
    while(p!=NULL)
    {
        printf("%c",p->data);
        if(p->next!=NULL)printf(",");
        p=p->next;
    }
    printf("\n");
}
struct list *inverse(struct list *head)
{
    struct list *p;
    p=head;
    while(p->next!=NULL)
    {
        struct list *temp;
        temp=p->next;
        p->next=p->front;
        p->front=temp;
        p=temp;
    }
    p->next=p->front;
    p->front=NULL;
    return p;
}
int main() {
    char x;
    char c;
    while(scanf("%c%c", &x,&c))
    {
        ha=insert(ha,x);
        if(c!=',')break;
    }
    //puts("22");
    ha=inverse(ha);
    //puts("22");
    print(ha);
    return 0;
}