#include <stdio.h>
#include <stdlib.h>
char A[105],B[105];
int t1=0,t2=0;
int compare(int A[],int B[])
{
    int t=0;
    while(t<t1 && t<t2 && A[t]==B[t])
    {
        t++;
    }
    if(t==t1 && t==t2)
    {
        return 0;
    }
    if((t==t1 && t<t2) || (t<t1 && t<t2 && A[t]<B[t]))
    {
        return 1;
    }
    return 2;
}

int main() {
    char c;
    while(scanf("%c%c", &A[t1++],&c)){
        if(c!=',')break;
    }
    while(scanf("%c%c", &B[t2++],&c)){
        if(c!=',')break;
    }
    // while(A!=NULL)
    // {
    //     printf("%c ",A->data);
    //     A=A->next;
    // }
    // printf("\n");
    // while(B!=NULL)
    // {
    //     printf("%c ",B->data);
    //     B=B->next;
    // }
    // printf("\n");
    printf("%d",compare(A,B));
    
    
    return 0;
}