
#include<stdio.h>
#include<stdlib.h>
struct List{
    int data;
    struct List *next;
}*head=NULL;

struct List *ADD(struct List *head,int x){
    struct List *q=head;
    if(q==NULL)
    {
        q=(struct List *)malloc(sizeof(struct List));
        q->data=x;
        q->next=NULL;
        return q;
    }
    while(q->next!=NULL)q=q->next;
    struct List *p=(struct List *)malloc(sizeof(struct List));
    p->data=x;
    p->next=NULL;
    q->next=p;
    return head;
}
void print(struct List *head){
    while(head !=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}
struct List *addnew_order(struct List *head,int x){
    struct List *p=head;
    if(p!=NULL && p->data>=x)
    {
        struct List *q=(struct List *)malloc(sizeof(struct List));
        q->data=x;
        q->next=p;
        return q;
    }
    while(p->next !=NULL && p->next->data < x)
        p=p->next;
    struct List *q=(struct List *)malloc(sizeof(struct List));
    q->data=x;
    q->next=p->next;
    p->next=q;
    return head;
}
int main(){
    int a,x=0;
    while(scanf("%d",&a)){
        
        head=ADD(head,a);
        if(getchar()=='\n')break;
    }
    scanf("%d",&x);
    head=addnew_order(head,x);
    print(head);
    return 0;
}


