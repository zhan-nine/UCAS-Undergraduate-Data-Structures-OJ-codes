#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
char s[1005];
struct tree{
    char data;
    struct tree *lson,*rson;
}*T;
int temp=0;
struct tree *make_tree(struct tree *T,char *s){
    if(s[temp]=='#' || s[temp]=='\0' || s[temp]=='\n')
    {
        temp++;
        return NULL;
    }
    T->data=s[temp++];
    T->lson=(struct tree *)malloc(sizeof(struct tree));
    T->rson=(struct tree *)malloc(sizeof(struct tree));
    T->lson=make_tree(T->lson,s);
    T->rson=make_tree(T->rson,s);
    return T;
}
void print_tree(struct tree *T){
    if(T==NULL) return;
    bool flag=0;
    if((T->data=='*' || T->data=='/') && (T->lson!=NULL && (T->lson->data=='+' || T->lson->data=='-') && !isalpha(T->lson->data)))
    {
        flag=1;
    }
    if(flag)putchar('(');
    if(T->lson!=NULL)print_tree(T->lson);
    if(flag)putchar(')');
    printf("%c",T->data);
    flag=0;
    if(((T->data=='*' || T->data=='/') && !isalpha(T->rson->data))|| ((T->data=='+' || T->data=='-') && (T->rson!=NULL && (T->rson->data=='+' || T->rson->data=='-'))))
    {
        flag=1;
    }
    if(flag)putchar('(');
    if(T->rson!=NULL)print_tree(T->rson);
    if(flag) putchar(')');
}
int main() {
    scanf("%s",s);
    T=(struct tree *)malloc(sizeof(struct tree));
    T=make_tree(T,s);
    print_tree(T);
    return 0;
}