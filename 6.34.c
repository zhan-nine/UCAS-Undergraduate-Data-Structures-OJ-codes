#include <stdio.h>
int L[1005],R[1005],T[1005];
int n=0;
int find_son(int x,int y)
{
    if(x==0)return 0;
    if(y==L[x] || y==R[x]) return 1;
    return find_son(L[x],y) || find_son(R[x],y)?1:0;
}
int main() {
    int x,y;
    char ch;
    while(scanf("%d",T+n)){
        n++;
        if((ch=getchar())=='\n') break;
        else ungetc(ch,stdin);
    }
    for(int i=0;i<n;i++){
        scanf("%d",L+i);
        //printf("%d %d\n",L[i],R[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",R+i);
        //printf("%d %d\n",L[i],R[i]);
    }
    scanf("%d%d",&x,&y);
    printf("%d\n",find_son(y,x));
    return 0;
}