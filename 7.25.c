#include <stdio.h>
#include <stdbool.h>
int s[1005],fst[1005],lst[1005];
int n;
int temp=0;
bool find_loop(int x,int target)
{
    if(x==target)return true;
    if(fst[x]>lst[x])return false;
    for(int i=fst[x];i<lst[x];i++)
    {
        if(find_loop(s[i],target))return true;
    }
    return false;
}
int main() {
    char ch;
    
    scanf("%d",&n);
    getchar();
    while((ch=getchar())!='\n')
    {
        ungetc(ch,stdin);
        scanf("%d",&s[temp++]);
    }
    for(int i=0;i<=n;i++)
    {
        scanf("%d",&fst[i]);
    }
    for(int i=0;i<=n;i++)
    {
        scanf("%d",&lst[i]);
    }
    bool flag=false;
    for(int i=1;i<=n;i++)
    {
        if(fst[i]>lst[i])continue;
        for(int j=fst[i];j<lst[i];j++)
        {
            if(find_loop(s[j],i))
            {
                flag=true;
                break;
            }
        }
        if(flag)break;
    }
    if(flag)puts("yes");
    else puts("no");
    return 0;
}