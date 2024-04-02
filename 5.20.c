#include <stdio.h>
int a[105][105];
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int flag=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(a[i][j]==0)continue;
            if(flag)putchar('+');
            else flag=1;
            if(a[i][j]!=1)printf("%d",a[i][j]);
            if(i>0)printf("xE%d",i);
            if(j>0)printf("yE%d",j);

        }
    }
    if(!flag)putchar('0');
    putchar('\n');
    return 0;
}