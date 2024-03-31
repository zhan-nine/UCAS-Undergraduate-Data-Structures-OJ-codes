#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct list{
    int data;
    struct list *next;
}*ha;
struct list *insert(struct list *head,int x)
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
void delete(struct list *head,int minn,int maxn)
{
    struct list *p,*q;
    p=head;
    while(p->next!=NULL)
    {
        if(p->next->data>minn && p->next->data<maxn)
        {
            q=p->next;
            p->next=q->next;
            free(q);
        }
        else
        {
            p=p->next;
        }
    }
}
void print(struct list *head)
{
    struct list *p;
    p=head;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main() {
    int x;
    char c;
    while(scanf("%d%c", &x,&c))
    {
        ha=insert(ha,x);
        if(c!=' ')break;
    }
    int minn,maxn;
    scanf("%d%d",&minn,&maxn);
    delete(ha,minn,maxn);
    print(ha);
    return 0;
}