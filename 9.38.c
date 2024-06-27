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
void Print(struct ListNode *list)
{
    struct ListNode *temp=list;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        if(temp->next!=NULL){
            temp=temp->next;
            putchar(' ');
        }
        else{
            putchar('\n');
            break;
        }
    }
}
int main() {
    struct ListNode *list=NULL;
    int x;
    while(scanf("%d",&x)!=EOF)
    {
        if(x==-1)continue;
        list=insert(list,x);
    }
    Print(list);
    return 0;
}