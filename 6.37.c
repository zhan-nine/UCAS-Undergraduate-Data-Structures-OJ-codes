#include <stdio.h>
int L[1005],R[1005];
int main() {
    char ch;
    while(scanf("%c",&ch)!=EOF){
        scanf("%d%d",L+ch-'A'+1,R+ch-'A'+1);
    }
    int stack[1005],top=0;
    stack[top++]=1;
    int i=1;
    while(top)
    {
        i=stack[--top];
        while(i>0)
        {
            if(i>0)printf("%c ",i+'A'-1);
            if(R[i]) stack[top++]=R[i];
            i=L[i];
        }
    }
    return 0;
}