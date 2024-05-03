//没写完
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int n;
bool map[1005][1005];
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int x;
            scanf("%d",&x);
            if(x)map[i][j]=1;
        }
    }
    char s[105];
    int ans[1005],temp,tempmin=0;
    for(temp=0;temp<n;temp++)ans[temp]=temp;
    getchar();
    while(scanf("%s",s))
    {
        
        if(strcmp(s,"IV")==0)
        {
            int x;
            scanf("%d",&x);
            ans[temp++]=x;
        }
        else if(strcmp(s,"IA")==0)
        {
            int x,y,i,j;
            scanf("%d%d",&x,&y);
            for(i=tempmin;i<temp;i++)if(ans[i]==x)break;
            for(j=tempmin;j<temp;j++)if(ans[j]==y)break;
            map[j][i]=map[i][j]=1;
        }
        else if(strcmp(s,"DV")==0)
        {
            int i,x;
            scanf("%d",&x);
            for(i=tempmin;i<temp;i++)
            {
                if(ans[i]==x)break;
            }
            tempmin++;
            for(int j=tempmin;j<=i;j++)
            {
                ans[j]=ans[j-1];
            }
        }
        else if(strcmp(s,"DA")==0)
        {
            int x,y,i,j;
            scanf("%d%d",&x,&y);
            for(i=tempmin;i<temp;i++)if(ans[i]==x)break;
            for(j=tempmin;j<temp;j++)if(ans[j]==y)break;
            map[i][j]=map[j][i]=0;
        }
        
        
        getchar();
    }
    for(int i=tempmin;i<temp;i++)
    {
        bool flag=0;
        for(int j=tempmin;j<temp;j++)
        {
            if(flag)putchar(' ');
            printf("%d",map[ans[i]][ans[j]]);
        }
        putchar('\n');
    }
    return 0;
}