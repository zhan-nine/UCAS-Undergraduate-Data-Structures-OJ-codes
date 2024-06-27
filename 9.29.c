#include <stdio.h>
#include <stdlib.h>
struct ListNode{
    int data;
    struct ListNode *next;
};
struct ListNode * insert(struct ListNode *list,int x){
    struct ListNode *p=(struct ListNode*)malloc(sizeof(struct ListNode));
    p->data=x;
    p->next=NULL;
    if(list==NULL)return p;
    struct ListNode *temp=list;
    //int bb=temp->data;
    if(temp->data<x)
    {
        while(temp!=NULL&&temp->next!=NULL&&temp->next->data<x)temp=temp->next;
        p->next=temp->next;
        temp->next=p;
    }
    else
    {
        p->next=temp;
        list=p;
    }
    return list;
}
void make_tail(struct ListNode *list){
    struct ListNode *temp=list;
    while(temp->next!=NULL)temp=temp->next;
    temp->next=list;
}
int Find(struct ListNode *list,int x){
    struct ListNode *temp=list;
    while(temp->data!=x)
    {
        temp=temp->next;
        if(temp==list)return 0;
    }
    return 1;
}
int main() {
    char ch;
    struct ListNode *h=NULL;
    int x;
    do
    {
        scanf("%d",&x);
        h=insert(h,x);
    }while((ch=getchar())!='\n');
    make_tail(h);
    struct ListNode *t=h;
    do
    {
        scanf("%d",&x);
        if(Find(t,x)==1)printf("1 ");
        else printf("0 ");
    }while((ch=getchar())!='\n');
    return 0;
}