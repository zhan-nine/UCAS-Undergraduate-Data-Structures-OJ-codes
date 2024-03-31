#include <stdio.h>
#include <stdlib.h>
struct list{
    char data;
    struct list *next;
}*ha,*hb,*hc;
void delete(struct list *head,char x);
struct list *insert(struct list *head,char x)
{
    struct list *p,*q;
    p=(struct list *)malloc(sizeof(struct list));
    p->data=x;
    p->next=NULL;
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
        q->next=p;
    }
    return head;
}
void calc(struct list *ha,struct list *hb,struct list *hc)
{
    struct list *q,*r;
    q=hb;
    r=hc;
    while(q!=NULL && r!=NULL)
    {
        if(q->data==r->data)
        {
            delete(ha,q->data);
            q=q->next;
            r=r->next;
        }
        else if(q->data<r->data)
        {
            q=q->next;
        }
        else if(q->data>r->data)
        {
            r=r->next;
        }
    }
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
void delete(struct list *head,char x)
{
    struct list *p=head;
    while(p->next!=NULL)
    {
        if(p->next->data==x)
        {
            struct list *q=p->next;
            p->next=q->next;
            free(q);
        }
        else
        {
            p=p->next;
        }
        if(p->data>x)return;
    }
}
int main() {
    char x,c;
    while(scanf("%c%c", &x,&c))
    {
        ha=insert(ha,x);
        if(c!=',')break;
    }
    while(scanf("%c%c", &x,&c))
    {
        hb=insert(hb,x);
        if(c!=',')break;
    }
    while(scanf("%c%c", &x,&c))
    {
        hc=insert(hc,x);
        if(c!=',')break;
    }
    calc(ha,hb,hc);
    print(ha);
    return 0;
}