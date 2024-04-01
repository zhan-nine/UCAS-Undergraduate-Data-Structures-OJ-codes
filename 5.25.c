#include <stdio.h>
int v1[1005],v2[1005],v3[1005];
int B1[105][105],B2[105][105],C[105][105];
int main() {
    int m,n,num1=0,num2=0,num3=0;
    scanf("%d %d",&m,&n);
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
        }
    }
    getchar();
    if((ch=getchar())!='\n')
    {
        ungetc(ch,stdin);
        do
        {
            scanf("%d",&v2[num2++]);
            //printf("%d\n",v1[num1-1]);
        }while((ch=getchar())!='\n');
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&B2[i][j]);
        }
    }
    int t1=0,t2=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(B1[i][j])
            {
                C[i][j]+=v1[t1++];
            }
            if(B2[i][j])
            {
                C[i][j]+=v2[t2++];
            }
            if(C[i][j])
            {
                v3[num3++]=C[i][j];
                C[i][j]=1;
            }
        }
    }
    for(int i=0;i<num3;i++)
    {
        printf("%d",v3[i]);
        if(i!=num3-1)putchar(' ');//末尾多空格会WA
    }
    putchar('\n');
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d",C[i][j]);
            if(j!=n-1)putchar(' ');//末尾多空格会WA

        }
        putchar('\n');
    }
    return 0;
}