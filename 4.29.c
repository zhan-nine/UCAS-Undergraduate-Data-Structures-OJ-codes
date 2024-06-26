#include <stdio.h>
#include <stdlib.h>
//特别说明，评测机4.29数据很弱，不能保证您的代码正确性
typedef struct node{
    char chdata;
    struct node *next,*succ;
}Node;
void Strinsert(Node *str,char ch)
{
    Node *p=str;
    /*
    if(p==NULL)
    {
        puts("1");
        return;
    }
    */
    while(p!=NULL && p->succ!=NULL)
    {
        p=p->succ;
    }
    Node *q=(Node*)malloc(sizeof(Node));
    q->chdata=ch;
    q->next=NULL;
    q->succ=NULL;
    p->succ=q;
}
void Getnext(Node *str)
{
    if(str->succ==NULL)//单个字符的串不需要next指针
    {
        return;
    }
    Node *i,*j;
    i=str->succ;
    j=str;
    //j->next=str;
    i->next=str;
    while(i!=NULL && i->succ!=NULL)
    {
        if(j==str || i->chdata == j->chdata)
        {
            j=j->succ;
            i=i->succ;
            i->next=j;
        }
        else{
            j=j->next;
        }
    }
}
int KMP(Node *s,Node *t)
{
    Getnext(t);
    Node *p=s,*q=t;
    int ans=0,temp=0;
    while(p->succ!=NULL)
    {
        if(q->chdata==0 || p->chdata==q->chdata)
        {
            p=p->succ;
            q=q->succ;
            temp++;
        }
        else
        {
            q=q->next;
            ans+=temp;
            temp=0;
            //ans++;
            
        }
        if(q->succ==NULL)
        {
            if(q->chdata==p->chdata)return ans;//匹配成功。请注意，监测末尾字符是否相等很重要。
            q=t->succ;
        }
    }
    return -1;
}
void init(Node *str)
{
    str->next=NULL;
    str->succ=NULL;
    str->chdata=0;
}
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    Node *s=(Node *)malloc(sizeof(Node)),*t=(Node *)malloc(sizeof(Node));
    init(s); init(t);
    char ch;
    for(int i=0;i<n;i++)
    {
        while((ch=getchar())=='\n');
        Strinsert(s,ch);
    }
    for(int i=0;i<m;i++)
    {
        while((ch=getchar())=='\n');
        Strinsert(t,ch);
    }
    int ans=KMP(s,t);
    printf("%d\n",ans);
    return 0;
}