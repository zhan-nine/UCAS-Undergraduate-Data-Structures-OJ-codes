#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
int n,begin;
struct ListNode {
    int val;
    int dis;
    struct ListNode *next;
}list[1005];
void insert(struct ListNode *list,int x,int y,int dis){
    struct ListNode *p=(struct ListNode*)malloc(sizeof(struct ListNode));
    p->val=y;
    p->dis=dis;
    struct ListNode *temp=list[x].next;
    while(temp!=NULL&&temp->next!=NULL&&temp->next->val<y)temp=temp->next;
    p->next=list[x].next;
    list[x].next=p;
}
int get_num(){
    int x=0;
    char c;
    while(isdigit(c=getchar()))x=x*10+c-'0';
    ungetc(c,stdin);
    return x;
}
bool vis[1005];
int dis[1005];
int main() {
    memset(dis,0x3f,sizeof(dis));
    scanf("%d%d",&n,&begin);
    dis[begin]=0;
    getchar();
    do
    {
        int x,y,val;
        x=get_num();
        getchar();
        y=get_num();
        getchar();
        val=get_num();
        insert(list,x,y,val);
        
    } while (getchar()!=EOF);
    int queue[1005],head=0,tail=0;
    queue[tail++]=begin;
    while(head<tail)
    {
        int x=queue[head++];
        if(vis[x])continue;
        vis[x]=1;
        struct ListNode *temp=list[x].next;
        while(temp!=NULL)
        {
            if(dis[temp->val]>dis[x]+temp->dis)
            {
                dis[temp->val]=dis[x]+temp->dis;
                queue[tail++]=temp->val;
            }
            temp=temp->next;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i==begin)continue;
        printf("%d",dis[i]);
        if(i!=n)printf(",");
        else printf("\n");
    }
    return 0;
}