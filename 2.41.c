#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct PolyTerm{
  int coef;
  int expn;
};
typedef struct PolyNode{
  struct PolyTerm data;
  struct PolyNode *next,*front;
} PolyNode, *PolyLink;

typedef PolyLink LinkedPoly;
LinkedPoly ha;
LinkedPoly insert(LinkedPoly head,int coef,int expn)
{
  if(head==NULL)
  {
    LinkedPoly q=(LinkedPoly)malloc(sizeof(LinkedPoly));
    q->data.coef=0;
    q->data.expn=0;
    q->next=NULL;
    q->front=NULL;
    head=q;
  }
  LinkedPoly p=head;
  while(p->data.expn<expn)
  {
    if(p->next==NULL || p->next==head)
    {
      LinkedPoly q=(LinkedPoly)malloc(sizeof(LinkedPoly));
      q->data.coef=0;
      q->data.expn=p->data.expn+1;
      q->next=NULL;
      q->front=p;
      p->next=q;
    }
    if(p->next!=head)p=p->next;
  }
  if(p->next==NULL)
  {
    p->next=head;
    head->front=p;
  }
  p->data.coef+=coef;
  if(p->data.coef==0 && p->next==head &&p!=head)
  {
    while(p->data.coef==0 && p->front!=NULL && p->front!=head)
    {
      LinkedPoly q=p;
      p->front->next=p->next;
      p->next->front=p->front;
      p=p->front;
      free(q);
    }
  }
  return head;
}
LinkedPoly derivative(LinkedPoly head)
{
  LinkedPoly p=head;
  if(head->next==NULL || head->next==head)
  {
    if(p->data.expn==0)
    {
      p->data.coef=0;
      return head;
    }
    p->data.coef*=p->data.expn;
    p->data.expn--;
    return head;
  }
  if(p->data.expn==0)
  {
    LinkedPoly q=p;
    p->front->next=p->next;
    p->next->front=p->front;
    p=p->next;
    free(q);
    head=p;
  }
  do
  {
    p->data.coef*=p->data.expn;
    p->data.expn--;
    p=p->next;
  }while(p!=head);
  return head;
}
void print(LinkedPoly head)
{
  if(head==NULL || head->next==head)
  {
    printf("%d\n",head->data.coef);
    return;
  }
  LinkedPoly p=head;
  p=p->front;
  int flag=0;
  do
  {
    if(p->data.coef!=0)
    {
      if(p->data.coef>0 && flag!=0)
      {
        printf(" + ");
      }
      if(p->data.coef>1)printf("%d",p->data.coef);
      if(p->data.coef==-1)
      {
        if(flag!=0)putchar(' ');
        printf("- ");
      }
      if(p->data.coef<-1)
      {
        if(flag!=0)putchar(' ');
        printf("- %d",-p->data.coef);
      }
      if(p->data.expn!=0)
      {
        printf("x");
        if(p->data.expn!=1)printf("^%d",p->data.expn);
      }
      flag=1;
    }
    p=p->front;
  }while(p!=head->front);
  printf("\n");

}
char s[105];
int main() {
    int sign=1;
    int coef=0,expn=0;
    ha=NULL;
    while(scanf("%s", s) != EOF) {
      //printf("%s\n", s);
      if(s[0]=='\n')break;
      if(s[0]=='+')
      {
        sign=1;
        continue;
      }
      else if(s[0]=='-')
      {
        sign=-1;
        continue;
      }
      coef=0,expn=0;
      for(int i=0;s[i]!='\0';i++)
      {
        if(isdigit(s[i]))
        {
          coef=coef*10+s[i]-'0';
        }
        if(s[i]=='x')
        {
          if(s[i+1]=='^')
          {
            for(int j=i+2;s[j]!='\0';j++)
            {
              expn=expn*10+s[j]-'0';
            }
          }
          else{
            expn=1;
          }
          break;

        }
      }
      if(coef==0)coef=1;
      coef*=sign;
      ha=insert(ha,coef,expn);
      //print(ha);
    }
    ha=derivative(ha);
    print(ha);
    return 0;
}