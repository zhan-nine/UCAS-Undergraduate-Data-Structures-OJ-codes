#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
//邻接表
bool List[1005][1005];
bool iscin[1005];
void Getchar()
{
    char ch;
    while((ch=getchar())=='-' || ch==',')
    {
        if(ch=='\n' || ch==EOF)break;
    }
    ungetc(ch,stdin);
}
int main() {
    int n,m;

    scanf("%d",&n);
    Getchar();
    scanf("%d",&m);
    Getchar();
    //printf("%d %d\n",n,m);
    for(int i=1;i<=m;i++)
    {
        int p,q;
        scanf("%d",&p);
        Getchar();
        scanf("%d",&q);
        Getchar();
        List[p][q]=1;
        iscin[p]=1;
        iscin[q]=1;
        //printf("%d %d\n",p,q);
    }

    int ans[1005],temp=0;
    for(int i=0;i<=1005;i++)if(iscin[i])ans[++temp]=i;
    for(int i=1;i<=n;i++)
    {
        printf("%d",ans[i]);
        bool flag2=0;
        for(int j=n;j>=1;j--)
        {
            if(List[ans[i]][ans[j]])
            {
                if(flag2)putchar(',');
                else putchar(' ');
                printf("%d",ans[j]);
                flag2=1;
            }
        }
        putchar('\n');
    }

    return 0;
}