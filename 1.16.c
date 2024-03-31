#include <stdio.h>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
int main() {
    int x,y,z;
    scanf("%d %d %d", &x, &y, &z);
    int min_num = min(min(x,y),z),max_num=max(max(x,y),z);
    printf("%d %d %d\n",max_num,x+y+z-max_num-min_num,min_num);
    return 0;
}