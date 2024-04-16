#include <stdio.h>
#include <stdbool.h>
struct node{
    int firstchild,nextsibling;
}a[1005];
int L[1005],R[1005];
int pre[1005],mid[1005],post[1005];
int n,t;

void find_pre(int x)
{
    if(x==0) return;
    pre[++t]=x;
    find_pre(L[x]);
    find_pre(R[x]);
}
void find_mid(int x)
{
    if(x==0) return;
    find_mid(L[x]);
    mid[++t]=x;
    find_mid(R[x]);
}
void find_post(int x)
{
    if(x==0) return;
    find_post(L[x]);
    find_post(R[x]);
    post[++t]=x;
}
int roots[1005],rootn=0;
void build_tree(struct node a[])
{
    bool flag[1005]={0};
    int stack[1005],top=0;
    
    while(1)
    {
        for(int j=1;j<=n;j++)
        {
            if(flag[j]==0)
            {
                stack[top++]=j;
                flag[j]=1;
                break;
            }
        }
        if(top==0)break;
        roots[++rootn]=stack[top-1];
        if(rootn>1)R[roots[rootn-1]]=roots[rootn];
        while(top)
        {
            int i=stack[--top];
            if(a[i].firstchild)
            {
                L[i]=a[i].firstchild;
                flag[a[i].firstchild]=1;
                stack[top++]=a[i].firstchild;
            }
            if(a[i].nextsibling)
            {
                R[i]=a[i].nextsibling;
                flag[a[i].nextsibling]=1;
                stack[top++]=a[i].nextsibling;
            }
        }
    }
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int j;
        scanf("%d",&j);
        scanf("%d%d",&a[j].firstchild,&a[j].nextsibling);
    }
    build_tree(a);
    t=0;
    find_pre(roots[1]);
    t=0;
    find_mid(roots[1]);
    t=0;
    find_post(roots[1]);
    L[0]=R[0]=1;
    //test
    /*
    for(int i=0;i<=n;i++)
    {
        printf("%d %d %d %d %d\n",L[i],R[i],pre[i],mid[i],post[i]);
    }
    */
    //output
    for(int i=0;i<=n;i++)
    {
        if(L[i])printf("%d",L[i]);
        else {
            int j;
            for(j=1;j<=n;j++)
            {
                if(pre[j]==i)break;
            }
            printf("%d",pre[j-1]);
        }
        if(i==n) putchar('\n');
        else putchar(' ');
    }
    for(int i=0;i<=n;i++)
    {
        printf("%d",R[i]);
        if(i==n) putchar('\n');
        else putchar(' ');
    }
    for(int i=0;i<=n;i++)
    {
        if(L[i])printf("%d",L[i]);
        else {
            int j;
            for(j=1;j<=n;j++)
            {
                if(mid[j]==i)break;
            }
            printf("%d",mid[j-1]);
        }
        if(i==n) putchar('\n');
        else putchar(' ');
    }
    for(int i=0;i<=n;i++)
    {
        
        if(R[i])
        {
            printf("%d",R[i]);
        }
        else {
            int j;
            for(j=1;j<=n;j++)
            {
                if(mid[j]==i)break;
            }
            printf("%d",mid[j+1]);
        }
        if(i==n) putchar('\n');
        else putchar(' ');
    }
    for(int i=0;i<=n;i++)
    {
        printf("%d",L[i]);
        if(i==n) putchar('\n');
        else putchar(' ');
    }
    for(int i=0;i<=n;i++)
    {
        if(R[i])printf("%d",R[i]);
        else {
            int j;
            for(j=1;j<=n;j++)
            {
                if(post[j]==i)break;
            }
            printf("%d",post[j+1]);
        }
        if(i==n) putchar('\n');
        else putchar(' ');
    }

    return 0;
}