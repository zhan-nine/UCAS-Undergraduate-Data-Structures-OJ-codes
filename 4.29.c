#include <stdio.h>
#include <stdlib.h>

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
    Node *i,*j;
    i=str->succ;
    j=str;
    j->next=str;
    i->next=str;
    while(i!=NULL && i->succ!=NULL)
    {
        if(j==str || i->chdata == j->chdata)
        {
            j=j->succ;
            i=i->succ;
            if(i->chdata!=j->chdata)i->next=j;
            else i->next=j->next;
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
            q=t->succ;
            return ans;
            
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