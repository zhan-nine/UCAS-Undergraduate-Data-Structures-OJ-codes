#include <stdio.h>
int g(int m,int n)
{
    if(m==0)return 0;
    return g(m-1,2*n)+n;
}
int main() {
    int m,n;
    char c;
    scanf("%d%c%d", &m,&c, &n);
    printf("%d\n",g(m,n));
    return 0;
}