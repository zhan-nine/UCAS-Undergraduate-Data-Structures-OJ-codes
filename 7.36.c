#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
int n;
struct ListNode {
    int val;
    struct ListNode *next;
}list[1005];
int max(int a,int b){
    return a>b?a:b;
}
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
int ans[1005];
void dfs(struct ListNode *list,int x,int root,int depth){
    struct ListNode *temp=list[x].next;
    ans[root]=max(ans[root],depth);
    while(temp!=NULL){
        dfs(list,temp->val,root,depth+1);
        temp=temp->next;
    }
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
    for(int i=1;i<=n;i++)
    {
        dfs(list,i,i,0);
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d",ans[i]);
        if(i!=n)printf(",");
        else printf("\n");
    }
    return 0;
}