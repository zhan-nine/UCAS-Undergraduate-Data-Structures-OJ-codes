#include <stdio.h>
int L[1005],R[1005],F[1005];
int depth=0;
void find_father(int x)
{
    F[L[x]]=x;
    F[R[x]]=x;
    if(L[x]!=0) find_father(L[x]);
    if(R[x]!=0) find_father(R[x]);
}
int main() {
    char ch;
    int maxn=0;
    while(scanf("%c",&ch)!=EOF){
        scanf("%d%d",L+ch-'A'+1,R+ch-'A'+1);
        maxn=maxn>(ch-'A'+1)?maxn:(ch-'A'+1);
    }
    find_father(1);
    int flag=1;
    for(int i=2;i<=maxn;i++)
    {
        if(F[i]!=i/2)
        {
            flag=0;
            break;
        }
    }
    if(flag==1) printf("Yes\n");
    else printf("No\n");
    return 0;
}