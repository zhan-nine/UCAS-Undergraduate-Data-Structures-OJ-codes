#include <stdio.h>
int k,m;
int fib[100005];
int main() {
    scanf("%d %d", &k, &m);
    fib[k-1]=1;
    for(int i=k;i<=m;i++) {
        for(int j=1;j<=k;j++) {
            fib[i]+=fib[i-j];

        }
    }
    printf("%d\n",fib[m]);
    return 0;
}