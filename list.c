//请注意，本文档仅供意会，实际使用时有bug
#include <stdio.h>
#include <stdlib.h>
struct List{
    int data;
    struct List *next;
};
struct List *head;
void insert(struct List *head,int x)
{
    while(head!=NULL)
    {
        head=head->next;
    }
    struct List *p=(struct List *)malloc(sizeof(struct List));
    p->data=x;
    p->next=NULL;
    head->next=p;
    return;
}
void print(struct List *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    return;
}
/*
struct List *delete(struct List *head,int x)
{
    struct List *p=head;
    while(p->next!=NULL)
    {
        if(p->next->data==x)
        {
            struct List *q=p->next;
            p->next=q->next;
            free(q);
        }
        p=p->next;
    }
    return head;
}
*/
struct List *Insert_new(struct List *head,int x)
{
    struct List *p=head;
    while(p->next!=NULL && p->next->data<x)
    {
        p=p->next;
    }
    struct List *q=(struct List *)malloc(sizeof(struct List));
    q->data=x;
    q->next=p->next;
    p->next=q;
}
int main() {
    int x;
    while(scanf("%d",&x))
    {
        insert(head,x);
        if(getchar()=='\n')break;
    }
    scanf("%d",&x);
    Insert_new(head,x);
    print(head);
    return 0;
}