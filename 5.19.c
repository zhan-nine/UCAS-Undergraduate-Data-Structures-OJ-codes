#include <stdio.h>
//显然只能是O(n*m)的复杂度
#define INF 0x3f3f3f3f
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
int a[1005][1005];
int flag[1005][1005];
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int minn,maxn;
    for(int i=1;i<=n;i++)
    {
        minn=INF;
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            minn=min(minn,a[i][j]);
        }
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==minn)flag[i][j]++;
        }
    }
    for(int j=1;j<=m;j++)
    {
        maxn=-INF;
        for(int i=1;i<=n;i++)
        {
            maxn=max(maxn,a[i][j]);
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i][j]==maxn)flag[i][j]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(flag[i][j]==2)
            {
                printf("%d ",a[i][j]);
            }
        }
    }
    return 0;
}