#include <stdio.h>
int n,arrsize;
int main() {
    scanf("%d%d",&n,&arrsize);
    if(n>arrsize || n>=11)
    {
        puts("-1");
        return 0;
    }
    long long arr[arrsize];
    arr[0]=1;
    for(int i=1;i<n;i++)
    {
        arr[i]=arr[i-1]*2*i;
    }
    for(int i=0;i<n;i++)printf("%lld ",arr[i]);
    return 0;
}