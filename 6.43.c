#include <stdio.h>
int L[1005],R[1005];
int n=0;
void swap(int *x,int *y)
{
    int t=*x;
    *x=*y;
    *y=t;

}
int main() {
    char ch;
    while(scanf("%d",L+n)){
        n++;
        if((ch=getchar())=='\n') break;
        else ungetc(ch,stdin);
    }
    for(int i=0;i<n;i++){
        scanf("%d",R+i);
        //printf("%d %d\n",L[i],R[i]);
    }
    for(int i=0;i<n;i++)
    {
        swap(&L[i],&R[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d",L[i]);
        if(i==n-1) putchar('\n');
        else putchar(' ');
    }
    for(int i=0;i<n;i++)
    {
        printf("%d",R[i]);
        if(i==n-1) putchar('\n');
        else putchar(' ');
    }
    return 0;
}