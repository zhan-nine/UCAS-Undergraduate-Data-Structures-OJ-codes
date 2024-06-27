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
    int x,y;
    scanf("%d%d",&x,&y);
    mysort(a,top);
    int i,j;
    for(i=0;i<top;i++)
    {
        if(a[i]>x)break;
    }
    for(j=i;j<top;j++)
    {
        if(a[j]>=y)
        {
            j--;
            break;
        }
    }
    for(int k=i;k<=j;k++)
    {
        printf("%d",a[k]);
        if(k!=j)putchar(' ');
        else putchar('\n');
    }
    return 0;
}