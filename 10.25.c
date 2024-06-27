#include <stdio.h>
#include <stdlib.h>
int a[1005],n;
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
void mysort(int aa[],int num){
    qsort(aa,n,sizeof(int),cmp);
}
void Print(int aa[],int num){
    for(int i=0;i<num;i++){
        printf("%d",aa[i]);
        if(i!=n-1)putchar(' ');
        else putchar('\n');
    }
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mysort(a,n);
    Print(a,n);
    return 0;
}