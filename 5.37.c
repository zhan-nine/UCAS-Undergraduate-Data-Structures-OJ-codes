#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
enum ElemTag{ ATOM, LIST } ;
typedef struct GLNode {
    enum ElemTag tag;
    union {
        int atom;
        struct GLNode *hp;
    };
    struct GLNode *tp;
} * GList;
GList CreateGList(GList L) {
    char ch,ch2;
    ch=getchar();
    while(ch==',') {
        ch=getchar();
    }
    
    if (ch=='(') {
        L=(GList)malloc(sizeof(struct GLNode));
        L->tag=LIST;
        L->hp=CreateGList(L->hp);
        L->tp=CreateGList(L->tp);
    } else if (ch==')') {
        L=NULL;
    } else if (isalpha(ch)){
        L=(GList)malloc(sizeof(struct GLNode));
        L->tag=ATOM;
        L->atom=ch;
        ch2=getchar();
        if(ch2==',') {
            L->tp=CreateGList(L->tp);
        }
        else {
            L->tp=NULL;
            ungetc(ch2,stdin);
        }
    }
    return L;
}
GList DeleteGList(GList L, char ch) {
    if (L!=NULL) {
        if (L->tag == ATOM) {
            if (L->atom == ch) {
                if(L->tp!=NULL) {
                    GList p=L->tp;
                    free(L);
                    return DeleteGList(p,ch);
                }
                else return NULL;
            } else {
                if(L->tp!=NULL) {
                    L->tp=DeleteGList(L->tp,ch);
                }
                return L;
            }
        } else {
            L->hp=DeleteGList(L->hp,ch);
            L->tp=DeleteGList(L->tp,ch);
            if (L->hp==NULL && L->tp==NULL) {
                return NULL;
            } else {
                return L;
            }
        }
    }
    return NULL;
}
void PrintGList(GList L) {
    if (L!=NULL) {
        if (L->tag == ATOM) {
            printf("%c", L->atom);
            if (L->tp!=NULL) {
                printf(",");
                PrintGList(L->tp);
            }
        } else {
            printf("(");
            if(L->hp!=NULL)PrintGList(L->hp);
            if (L->tp!=NULL)
            {
                printf(",");
                PrintGList(L->tp);
            }
            printf(")");
        }
    }
    else
    {
        puts("-1");
    }
}
int main() {
    GList List;
    List=CreateGList(List);
    //rintGList(List);
    char ch;
    while((ch=getchar())==' ' || ch==')');
    //printf("\n%c\n",ch);
    List=DeleteGList(List,ch);
    PrintGList(List);
    putchar('\n');
    return 0;
}