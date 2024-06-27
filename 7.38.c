#include <stdio.h>
#include <stdlib.h>
int n;
struct ListNode {
    int val;
    struct ListNode *next;
}list[1005];
void insert(struct ListNode *list,int x,int y){
    struct ListNode *p=(struct ListNode*)malloc(sizeof(struct ListNode));
    p->val=y;
    struct ListNode *temp=list[x].next;
    while(temp!=NULL&&temp->next!=NULL&&temp->next->val<y)temp=temp->next;
    p->next=list[x].next;
    list[x].next=p;
}
char data[1005];
void dfs(struct ListNode *list,int x){
    if(data[x]=='+'||data[x]=='-'||data[x]=='*'||data[x]=='/')
    {
        struct ListNode *temp=list[x].next;
        int a=temp->val;
        temp=temp->next;
        int b=temp->val;
        //printf("%d %d\n",a,b);
        dfs(list,a);
        dfs(list,b);
    }
    printf("%c",data[x]);
}
int main() {
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        data[i]=getchar();
        
        if(data[i]=='+'||data[i]=='-'||data[i]=='*'||data[i]=='/')
        {
            int x,y;
            scanf("%d%d",&x,&y);
            insert(list,i,x);
            insert(list,i,y);
        }
        getchar();
    }
    dfs(list,0);
    return 0;
}