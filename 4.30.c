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
    while(p->succ!=NULL)
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
            if(q->chdata==p->chdata)return ans;//匹配成功
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
void delete(Node *str)
{
    Node *p=str->succ;
    while(p!=NULL)
    {
        Node *q=p->succ;
        free(p);
        p=q;
    }
    free(str);
}
void Strprint(Node *str)
{
    Node *p=str;
    while(p!=NULL && p->chdata==0)p=p->succ;
    while(p!=NULL)
    {
        printf("%c",p->chdata);
        p=p->succ;
    }
}
int main() {
    Node *s=(Node *)malloc(sizeof(Node));
    init(s);
    char ch;
    int len=0;
    while((ch=getchar())!='\n')
    {
        Strinsert(s,ch);
        len++;
    }
    for(int i=len-1;i>0;i--)
    {
        for(int j=0;i+j<len;j++)
        {
            Node *t=(Node *)malloc(sizeof(Node));
            init(t);
            Node *p=s;
            for(int k=0;k<=j;k++) p=p->succ;
            Node *temp=p;
            for(int k=0;k<i;k++)
            {
                Strinsert(t,p->chdata);
                p=p->succ;
            }
            Node *q=(Node *)malloc(sizeof(Node));
            init(q);
            q->succ=temp->succ;
            int kmp=KMP(q,t);
            if(kmp!=-1)
            {
                Strprint(t);
                //putchar(' ');
                //Strprint(q);
                printf(" %d\n",j);
                return 0;
            }
            delete(t);
        }
    }
    puts("-1");
    return 0;
}