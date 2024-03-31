#include <stdio.h>
#include <stdlib.h>
struct list{
    char data;
    struct list *next;
}*ha,*hb,*hc;
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
struct list *merge(struct list *ha,struct list *hb)
{
    struct list *p,*q;
    p=ha;
    q=hb;
    while(q->next!=NULL)q=q->next;
    q->next=p;
    return hb;
}
int main() {
    int n,m,x;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        ha=insert(ha,x);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&x);
        hb=insert(hb,x);
    }
    hc=merge(ha,hb);
    struct list *p=hc;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    return 0;
}