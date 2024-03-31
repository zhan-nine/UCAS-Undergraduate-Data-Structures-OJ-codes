#include <stdio.h>

int main() {
    long long ans=1;
    long long n;
    scanf("%lld",&n);
    while(n)
    {
        ans*=n;
        n>>=1;
    }
    printf("%lld\n",ans);
    return 0;
}