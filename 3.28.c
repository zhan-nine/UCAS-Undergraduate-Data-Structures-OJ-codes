#include <stdio.h>
#include <stdlib.h>
int ans;
struct node{
    int data;
    struct node *next;
};
struct node *push(struct node *head,int x)
{
    if(head==NULL)
    {
        head=(struct node *)malloc(sizeof(struct node));
        head->data=x;
        head->next=head;
        return head;
    }
    struct node *p=head;
    while(p->next!=head)
    {
        p=p->next;
    }
    struct node *q=(struct node *)malloc(sizeof(struct node));
    q->data=x;
    q->next=head;
    p->next=q;
    return head;
}
struct node *pop(struct node *head)
{
    struct node *p=head;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next=head->next;
    ans=head->data;
    free(head);
    return p->next;
}
int main() {
    int n,x;
    struct node *head=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        getchar();
        head=push(head,x);
        //printf("%d\n",x);
    }
    for(int i=0;i<n;i++)
    {
        head=pop(head);
        printf("%d",ans);
        if(i!=n-1)putchar(',');
    }
    putchar('\n');
    return 0;
}