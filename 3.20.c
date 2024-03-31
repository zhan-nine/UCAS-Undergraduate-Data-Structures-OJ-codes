#include <stdio.h>
#include <stdbool.h>
int a[255][255];
const int dx[]={0,0,-1,1};
const int dy[]={1,-1,0,0};
bool flag[255][255];
int n,m;
void changecolor(int x,int y,int color)
{
    flag[x][y]=1;
    a[x][y]=2;
    //printf("%d %d\n",x,y);
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=1 && nx<=n && ny>=1 && ny<=m && a[nx][ny]==color && !flag[nx][ny])
        {
            changecolor(nx,ny,color);
        }
    }
}
int main() {
    int x,y,dir;
    memset(flag,0,sizeof(flag));
    scanf("%d%d%d%d%d",&n,&m,&x,&y,&dir);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int color=a[x][y];
    changecolor(x,y,color);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            printf("%d",a[i][j]);
        }
        putchar('\n');
    }
    return 0;
}