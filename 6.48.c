#include <stdio.h>
#include <ctype.h>
char s[105];
int L[500],R[500],F[500];
int val[500];
int t;
void build_tree(char *s,int x,int flag)
{
    if(s[t]=='\0') return;
    if(s[t]!='^'&&flag==1)
    {
        L[x]=(int)s[t];
        F[L[x]]=x;
        t++;
        build_tree(s,L[x],1);
        t++;
        build_tree(s,L[x],2);
    }
    else if(s[t]!='^'&&flag==2)
    {
        R[x]=(int)s[t];
        F[R[x]]=x;
        t++;
        build_tree(s,R[x],1);
        t++;
        build_tree(s,R[x],2);
    }
    else
    {
        if(flag==1)L[x]=0;
        else if(flag==2)R[x]=0;
    }
    
}
void print_preorder(int x)
{
    if(x==0) return;
    printf("%c ",x);
    print_preorder(L[x]);
    print_preorder(R[x]);
}
void find_val(int x,int sum)
{
    if(x==0)
    {
        return;
    }
    val[x]=sum;
    find_val(L[x],sum+1);
    find_val(R[x],sum+1);
}
int flag=0;
int lca(int x,int y)
{
    if(x==L[0] || y==L[0]) return L[0];
    if(val[x]<=1 || val[y]<=1) return L[0];
    //if(x==F[x] || y==F[y]) return x;
    if(x==y) 
    {
        if(flag==1)return x;
        else return F[x];
    }
    if(val[x]>val[y]) return lca(F[x],y);
    else if(val[x]<val[y]) return lca(x,F[y]);
    flag=1;
    return lca(F[x],F[y]);
}
int main() {
    char x,y;
    scanf("%s",s);
    getchar();
    scanf("%c %c",&x,&y);
    
    t=1;
    build_tree(s,s[0],1);
    t++;
    build_tree(s,s[0],2);
    L[0]=R[0]=s[0];
    F[L[0]]=L[0];
    /*
    print_preorder(s[0]);
    puts("");
    */
    //printf("%c\n",L[0]);//root
    find_val(L[0],1);
    /*
    for(int i=48;i<=58;i++)
    {
        printf("%d ",val[i]);
    }
    puts("");
    */
    printf("%c",lca(x,y));
    return 0;
}