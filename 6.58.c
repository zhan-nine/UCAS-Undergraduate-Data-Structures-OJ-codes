#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int L1[1005],R1[1005],L2[1005],R2[1005],L3[1005],R3[1005];
bool flag=0;
struct tree{
    int data;
    struct tree *lson,*rson;
};
void mid_order(struct tree *T)
{
    if(T->lson!=NULL) mid_order(T->lson);
    if(flag)putchar(' ');
    printf("%d",T->data);
    flag=1;
    if(T->rson!=NULL) mid_order(T->rson);

}
struct tree *make_tree(struct tree *T,int *L,int *R,int x)
{
    if(x==0) return NULL;
    T->data=x;
    T->lson=(struct tree *)malloc(sizeof(struct tree));
    T->rson=(struct tree *)malloc(sizeof(struct tree));
    T->lson=make_tree(T->lson,L,R,L[x]);
    T->rson=make_tree(T->rson,L,R,R[x]);
    return T;
}
struct tree *insert(struct tree *T1,struct tree *T2,int x)
{
    if(T1==NULL) return T1;
    if(T1->data==x)
    {
        struct tree *temp;
        temp=T1->lson;
        T2->rson=temp;
        T1->lson=T2;
        return T1;
    }
    if(T1->lson!=NULL) T1->lson=insert(T1->lson,T2,x);
    if(T1->rson!=NULL) T1->rson=insert(T1->rson,T2,x);
    return T1;
}
int main() {
    int temp=0,temp2=0;
    while(scanf("%d",L1+temp))
    {
        if(getchar()=='\n') break;
        temp++;
    }
    for(int i=0;i<=temp;i++)
    {
        scanf("%d",R1+i);
    }
    int p;
    scanf("%d",&p);
    struct tree *T=(struct tree *)malloc(sizeof(struct tree));
    T=make_tree(T,L1,R1,L1[0]);
    //mid_order(T);
    while(scanf("%d",L2+temp2))
    {
        if(getchar()=='\n') break;
        temp2++;
    }
    for(int i=0;i<=temp2;i++)
    {
        scanf("%d",R2+i);
    }
    for(int i=1;i<=temp2;i++)
    {
        L3[L2[0]-1+i]=L2[i];
        R3[R2[0]-1+i]=R2[i];
    }
    // for(int i=L2[0];i<=L2[0]+temp2;i++)
    // {
    //     printf("%d %d\n",L3[i],R3[i]);
    // }
    struct tree *T2=(struct tree *)malloc(sizeof(struct tree));
    T2=make_tree(T2,L3,R3,L2[0]);
    // mid_order(T);
    // puts("");
    // mid_order(T2);
    // puts("");
    T=insert(T,T2,p);
    mid_order(T);
    return 0;
}