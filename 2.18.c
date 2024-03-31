#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct list{
    int data;
    struct list *next;
    int num;
}*ha;
struct list *insert(struct list *head,int x,int t)
{
    struct list *p,*q;
    p=(struct list *)malloc(sizeof(struct list));
    p->data=x;
    p->next=NULL;
    p->num=t;
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
bool delete(struct list *head,int x)
{
    struct list *p,*q;
    p=head;
    while(p->next!=NULL)
    {
        if(p->next->num==x)
        {
            q=p->next;
            p->next=q->next;
            free(q);
            return 1;
        }
        else
        {
            p=p->next;
        }
    }
    return 0;
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
    int x,t=0;
    char c;
    while(scanf("%d%c", &x,&c))
    {
        ha=insert(ha,x,t++);
        if(c!=' ')break;
    }
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(!delete(ha,n))printf("NULL\n");
        else print(ha);
    }
    return 0;
}