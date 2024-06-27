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
    getchar();
    while(scanf("%s",s)!=EOF)
    {
        
        if(strcmp(s,"IV")==0)
        {
            int i,j,x;
            scanf("%d",&x);
            n++;
            bool map2[1005][1005];
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(i<x&&j<x)map2[i][j]=map[i][j];
                    else if(i==x || j==x)map2[i][j]=0;
                    else if(i<x&&j>x)map2[i][j]=map[i][j-1];
                    else if(i>x&&j<x)map2[i][j]=map[i-1][j];
                    else if(i>x&&j>x)map2[i][j]=map[i-1][j-1];
                
                }
            }
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    map[i][j]=map2[i][j];
                }
            }
        }
        else if(strcmp(s,"IA")==0)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            map[x][y]=map[y][x]=1;
        }
        else if(strcmp(s,"DV")==0)
        {
            int i,j,x;
            scanf("%d",&x);
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(i<x&&j<x)map[i][j]=map[i][j];
                    else if(i>=x&&j<x)map[i][j]=map[i+1][j];
                    else if(i<x&&j>=x)map[i][j]=map[i][j+1];
                    else if(i>=x&&j>=x)map[i][j]=map[i+1][j+1];
                }
            }
            n--;
        }
        else if(strcmp(s,"DA")==0)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            map[x][y]=map[y][x]=0;
        }
        
        
        getchar();
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j>=1 && j<=n-1)putchar(' ');
            printf("%d",map[i][j]);
        }
        putchar('\n');
    }
    return 0;
}