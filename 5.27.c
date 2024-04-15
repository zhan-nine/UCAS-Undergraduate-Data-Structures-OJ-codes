#include <stdio.h>
#include <stdlib.h>
int v1[1005],v2[1005],v3[1005];
int B1[105][105],B2[105][105],C[105][105];
typedef struct OLNode
{
    int i,j;
    int e;
    struct OLNode *right,*down;
}OLNode;
typedef struct{
    OLNode *rhead,*chead;
    int mu,nu,tu;
}CrossList;
void CreateSMatrix_OL(CrossList *M,int m,int n)
{
    M->mu=m;
    M->nu=n;
    M->tu=0;
    M->rhead=(OLNode*)malloc(sizeof(OLNode)*m);
    M->chead=(OLNode*)malloc(sizeof(OLNode)*n);
    for(int i=0;i<m;i++)
    {
        (M->rhead)[i].right=NULL;
        (M->rhead)[i].down=NULL;
        (M->rhead)[i].i=i;
        (M->rhead)[i].j=0;
        (M->rhead)[i].e=0;
    }
    for(int i=0;i<n;i++)
    {
        (M->chead)[i].right=NULL;
        (M->chead)[i].down=NULL;
        (M->chead)[i].i=0;
        (M->chead)[i].j=i;
        (M->chead)[i].e=0;
    }
    return;
}
void OLInsert(CrossList *M,int i,int j,int e)
{
    OLNode *p,*q;
    p=(OLNode*)malloc(sizeof(OLNode));
    p->i=i;p->j=j;p->e=e;
    if(((M->rhead)+i)==NULL || (M->rhead)[i].j>j)
    {
        p->right=(M->rhead)+i;
       (M->rhead)[i]=*p;
    }
    else if(((M->rhead)+i)!=NULL && (M->rhead)[i].j==j)
    {
        (M->rhead)[i].e+=e;
        free(p);
        return;
    }
    else
    {
        q=(M->rhead)+i;
        while(q->right&&q->right->j<j)
        {
            q=q->right;
        }
        p->right=q->right;
        q->right=p;
    }
    if(((M->chead)+j)==NULL||((M->chead)[j]).i>i)
    {
        p->down=((M->chead)+j);
        (M->chead)[j]=*p;
    }
    else
    {
        q=(M->chead)+j;
        while(q->down&&q->down->i<i)
        {
            q=q->down;
        }
        p->down=q->down;
        q->down=p;
    }
    return;  
}
CrossList *OLadd(CrossList *m1,CrossList *m2,int m,int n)
{
    CrossList *m3=(CrossList*)malloc(sizeof(CrossList));
    CreateSMatrix_OL(m3,m,n);
    OLNode *p,*q;
    for(int i=0;i<m;i++)
    {
        p=(m1->rhead)+i;
        q=(m2->rhead)+i;
        while(p!=NULL && q!=NULL)
        {
            if(p->j<q->j)
            {
                OLInsert(m3,i,p->j,p->e);
                p=p->right;
            }
            else if(p->j>q->j)
            {
                OLInsert(m3,i,q->j,q->e);
                q=q->right;
            }
            else
            {
                if(p->e+q->e!=0)OLInsert(m3,i,p->j,p->e+q->e);
                p=p->right;
                q=q->right;
            }
        
        }
        while(p!=NULL)
        {
            OLInsert(m3,i,p->j,p->e);
            p=p->right;
        }
        while(q!=NULL)
        {
            OLInsert(m3,i,q->j,q->e);
            q=q->right;
        }
    }
    return m3;
}
void OLprint(CrossList *M,int m,int n)
{
    OLNode *p;
    int num3=0;
    for(int i=0;i<m;i++)
    {
        p=(M->rhead)+i;
        while(p!=NULL && p->right!=NULL)
        {
            if(p->e!=0)
            {
                v3[num3++]=p->e;
                C[i][p->j]=1;
                //p->e=1;
            }
            p=p->right;
        }
        if(p!=NULL && p->e!=0)
        {
            v3[num3++]=p->e;
            C[i][p->j]=1;
            //p->e=1;
        }
    }
    for(int i=0;i<num3;i++)
    {
        printf("%d",v3[i]);
        if(i!=num3-1)putchar(' ');
    }
    putchar('\n');
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d",C[i][j]);
            if(j!=n-1)putchar(' ');
        }
        putchar('\n');
    }
}
int main() {
    CrossList *m1=(CrossList*)malloc(sizeof(CrossList)),*m2=(CrossList*)malloc(sizeof(CrossList));
    int m,n,num1=0,num2=0;
    int t1=0,t2=0;
    //init
    scanf("%d %d",&m,&n);
    CreateSMatrix_OL(m1,m,n);
    CreateSMatrix_OL(m2,m,n);
    char ch;
    getchar();
    if((ch=getchar())!='\n')
    {
        ungetc(ch,stdin);
        do
        {
            scanf("%d",&v1[num1++]);
            //printf("%d\n",v1[num1-1]);
        }while((ch=getchar())!='\n');
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&B1[i][j]);
            if(B1[i][j])
            {
                OLInsert(m1,i,j,v1[t1++]);
            }
        }
    }
    getchar();
    if((ch=getchar())!='\n')
    {
        ungetc(ch,stdin);
        do
        {
            scanf("%d",&v2[num2++]);
            //printf("%d\n",v2[num1-1]);
        }while((ch=getchar())!='\n');
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&B2[i][j]);
            if(B2[i][j])
            {
                OLInsert(m2,i,j,v2[t2++]);
            }
        }
    }
    CrossList *m3=OLadd(m1,m2,m,n);
    //OLprint(m1,m,n);
    //OLprint(m2,m,n);
    OLprint(m3,m,n);
    return 0;
}