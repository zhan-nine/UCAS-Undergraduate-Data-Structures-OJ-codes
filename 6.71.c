#include <stdio.h>
char chset[1005];
int L[1005],S[1005];
void dfs(int x,int depth)
{
    if(x==-1)return;
    for(int i=0;i<depth;i++) putchar('-');
    putchar(chset[x]);
    putchar('\n');
    dfs(L[x],depth+1);
    dfs(S[x],depth);
}
int main() {
    char ch;
    int p,q,n=0;
    while(scanf("%c%d%d",&ch,&p,&q)!=EOF)
    {
        n++;
        L[n]=p;
        S[n]=q;
        chset[n]=ch;
        getchar();
    }
    // for(int i=1;i<=n;i++)
    // {
    //     printf("%d %d %d %c\n",i,L[i],S[i],chset[i]);
    // }
    dfs(1,0);
    return 0;
}