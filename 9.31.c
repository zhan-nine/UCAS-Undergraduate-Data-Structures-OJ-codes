#include <stdio.h>
struct TreeNode{
    int data;
    int left,right;
}tree[10005];
int dfs(int root)
{
    //printf("%d %d\n",tree[root].data,root);
    int sum=tree[root].data;
    if(tree[root].data==0)return 1;
    if(tree[root].left!=-1){
        if(tree[tree[root].left].data<=sum&&!dfs(tree[root].left))return 0;
        else if(tree[tree[root].left].data>sum)return 0;
    }
    if(tree[root].right!=-1){
        if(tree[tree[root].right].data>=sum&&!dfs(tree[root].right))return 0;
        else if(tree[tree[root].right].data<sum)return 0;
    }
    return 1;
}
int main() {
    int x,y,z,top=0;
    while(scanf("%d%d%d",&x,&y,&z)!=EOF)
    {
        tree[top].data=x;
        tree[top].left=y;
        tree[top].right=z;
        top++;
    }
    if(dfs(0))puts("1");
    else puts("0");
    return 0;
}