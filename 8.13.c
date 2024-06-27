//这个代码只能过样例
#include <stdio.h>
#include <stdlib.h>
struct ListNode{
    int tag,begin,size;
    struct ListNode *next;
};
struct ListNode * insert(struct ListNode *list,int x,int y,int z){
    struct ListNode *p=(struct ListNode*)malloc(sizeof(struct ListNode));
    p->tag=x;
    p->begin=y;
    p->size=z;
    p->next=NULL;
    struct ListNode *temp=list->next;
    if(temp!=NULL && temp->begin<y){
        while(temp!=NULL&&temp->next!=NULL&&temp->next->begin<y)temp=temp->next;
        p->next=temp->next;
        temp->next=p;
    }
    else{
        list->next=p;
        p->next=temp;
    }
    return list;
}
struct ListNode *restock(struct ListNode *list){
    struct ListNode *temp=list->next;
    while(temp!=NULL && temp->next!=NULL)
    {
        if(temp->tag==1)temp->tag=0;
        if(temp->begin+temp->size==temp->next->begin)
        {
            temp->size=temp->size+temp->next->size;
            struct  ListNode *p=temp->next;
            temp->next=temp->next->next;
            free(p);
        }
        else temp=temp->next;
    }
    return list;
}
void Print(struct ListNode *list)
{
    struct ListNode *temp=list->next;
    while(temp!=NULL)
    {
        printf("0 %d %d\n",temp->begin,temp->size);
        if(temp->next!=NULL)temp=temp->next;
        else break;
    }
}
int main() {
    int x,y,z;
    struct ListNode *list=(struct ListNode*)malloc(sizeof(struct ListNode));
    list->next=NULL;
    while(scanf("%d%d%d",&x,&y,&z)!=EOF)
    {
        list=insert(list,x,y,z);
        list=restock(list);
    }
    list=restock(list);
    Print(list);
    return 0;
}