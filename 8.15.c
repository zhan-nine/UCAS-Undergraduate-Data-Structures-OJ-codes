#include <stdio.h>
int high,low,tag;
int block[1005],size[1005],top=0;
int main() {
    scanf("%d%d%d",&high,&low,&tag);
    while(scanf("%d",&block[top])!=EOF)top++;
    int flag=0;
    for(int i=0;i<top;i++)
    {
        int j;
        if(block[i]==0)
        {
            flag=1;
            for(j=i+1;j<top;j++)
            {
                if(block[j]!=0)break;
            }
            printf("0 %d %d\n",high+i*tag,(j-i)*tag);
            i=j;
        }
    }
    if(flag==0)puts("0 0 0");
    return 0;
}