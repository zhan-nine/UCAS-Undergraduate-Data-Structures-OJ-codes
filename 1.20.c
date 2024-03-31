#include <stdio.h>
long long x,n,a[10005],ans,temp=1;
int main() {
    scanf("%lld%lld", &x, &n);
    for(int i=0;i<=n;i++) {
        scanf("%lld", &a[i]);
        ans+=a[i]*temp;
        temp*=x;
    }
    printf("%lld\n",ans);
    return 0;
}