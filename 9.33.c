#include <stdio.h>
int a[1005],top=0;
void mysort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
int main() {
    do{
        scanf("%d",&a[top]);
        top++;
    }while(getchar()!='\n');
    int x;
    scanf("%d",&x);
    mysort(a,top);
    int i;
    for(i=0;i<top;i++)
    {
        if(a[i]>=x)break;
    }
    for(int j=top-1;j>=i;j--)
    {
        printf("%d",a[j]);
        if(j!=i)putchar(' ');
        else putchar('\n');
    }
    return 0;
}