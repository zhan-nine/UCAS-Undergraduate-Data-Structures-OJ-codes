#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char sets[105][1005];
bool vis[105];
int top=0;
int main() {
    char buf[1005];
    int x;
    char st[1005];
    while(gets(buf))
    {
        memset(st,0,sizeof(st));
        sscanf(buf,"%d %s",&x,st);
        
        
        if(x==1){
            strcpy(sets[top],st);
            //printf("%s\n",sets[top]);
            vis[top]=1;
            top++;
        }
        else if(x==2){
            for(int i=0;i<top;i++)
            {
                if(strcmp(sets[i],st)==0){
                    vis[i]=0;
                    //printf("%d\n",i);
                    break;
                }
            }
        }
        else if(x==3){
            bool flag=0;
            for(int i=0;i<top;i++)
            {
                if(vis[i]&&strcmp(sets[i],st)==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag)puts("True");
            else puts("False");
        }
    }
    return 0;
}