#include <stdio.h>
#include <stdlib.h>
struct list {
    int data;
    struct list *next;
};
struct list *head;
void insert(int x)
{
    struct list *p,*q,*r;
    p=head;
    q=NULL;
    while(p!=NULL&&p->data<x)
    {
        q=p;
        p=p->next;
    }
    r=(struct list*)malloc(sizeof(struct list));
    r->data=x;
    r->next=p;
    if(q==NULL)
    {
        head=r;
    }
    else
    {
        q->next=r;
    }
    return;

}
int main() {
    int x;
    head=NULL;
    while(scanf("%d", &x)!=EOF){
        insert(x);
    }
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    return 0;
}