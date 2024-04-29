#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s1[1005],s2[1005];
struct tree{
    char data;
    struct tree *lson,*rson;
};
struct tree *create(struct tree *T,char *s1,char *s2,int l1,int r1,int l2,int r2)
{
    if(l1>r1) return NULL;
    T->data=s1[l1];
    int i;
    for(i=l2;i<=r2;i++)
    {
        if(s2[i]==s1[l1]) break;
    }
    T->lson=(struct tree *)malloc(sizeof(struct tree));
    T->rson=(struct tree *)malloc(sizeof(struct tree));
    T->lson=create(T->lson,s1,s2,l1+1,l1+i-l2,l2,i-1);
    T->rson=create(T->rson,s1,s2,l1+i-l2+1,r1,i+1,r2);
    return T;
}
void print_tree(struct tree *T)
{
    if(T==NULL) return;
    if(T->lson!=NULL) print_tree(T->lson);
    if(T->rson!=NULL) print_tree(T->rson);
    printf("%c",T->data);

}
int main() {
    scanf("%s%s",s1,s2);
    int len=strlen(s1);
    struct tree *T=(struct tree *)malloc(sizeof(struct tree));
    T=create(T,s1,s2,0,len-1,0,len-1);
    print_tree(T);
    return 0;
}