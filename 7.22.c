#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
struct ListNode {
    int val;
    struct ListNode *next;
}list[1005];
int n;
int get_num(){
    int x=0;
    char c;
    while(isdigit(c=getchar()))x=x*10+c-'0';
    ungetc(c,stdin);
    return x;
}
void insert(struct ListNode *list,int x,int y){
    struct ListNode *p=(struct ListNode*)malloc(sizeof(struct ListNode));
    p->val=y;
    struct ListNode *temp=list[x].next;
    while(temp!=NULL&&temp->next!=NULL&&temp->next->val<y)temp=temp->next;
    p->next=list[x].next;
    list[x].next=p;
}
bool flag[1005];
bool dfs(struct ListNode *list,int x,int y){
    if(x==y){
        return true;
    }
    flag[x]=1;
    struct ListNode *temp=list[x].next;
    while(temp!=NULL){
        if(temp->val==y){
            //printf("yes\n");
            return true;
        }
        if(dfs(list,temp->val,y))return true;
        temp=temp->next;
    }
    flag[x]=0;
    return false;
}
int main() {
    scanf("%d",&n);
    getchar();
    do{
        int x,y;
        x=get_num();
        getchar();
        y=get_num();
        insert(list,x,y);
    }while(getchar()==',');
    int x,y;
    x=get_num();
    getchar();
    y=get_num();
    if(dfs(list,x,y))puts("yes");
    else puts("no");
    return 0;
}