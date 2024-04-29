#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 1000

char S[MAXSIZE];
int top=0;
void Push(char S[MAXSIZE],char x){
    S[top++] = x;
}
char Pop(char S[MAXSIZE]){
    if(top <=0){
        printf("0");
        exit(0);
    }
    return S[--top];
}
// 引入算符优先级矩阵
#define OPSETSIZE 6
char OPSET[OPSETSIZE]={'+','-','*','/','(',')'};
char Prior[OPSETSIZE][OPSETSIZE] = { 
'>','>','<','<','<','>',
'>','>','<','<','<','>',
'>','>','>','>','<','>',
'>','>','>','>','<','>',
'<','<','<','<','<',' ',
'>','>','>','>',' ','>'};
char conp(char a,char b){
    int pa,pb=0;
    for(int i=0;i<OPSETSIZE;i++){
        if(OPSET[i]==a){
            pa=i;
            break;
        }
    }
    for(int i=0;i<OPSETSIZE;i++){
        if(OPSET[i]==b){
            pb=i;
            break;
        }
    }
    return Prior[pa][pb];
}
int switchcase(char a){
    switch(a){
    case '<':return 0;break;
    case '>':return 1;break;
    default:return 1;break;
    }
}

int main(){
    char a[MAXSIZE];
    scanf("%s",a);
    int t=0;
    char output;
    while(a[t]!='\0'){
        if(a[t]!='+'&&a[t]!='-'&&a[t]!='*'&&a[t]!='/'&&a[t]!='('&&a[t]!=')'){
            printf("%c",a[t]);
            t++;
        }
        else if(top==0)Push(S,a[t++]);
        else{
            while(top>0){
                int judge=switchcase(conp(S[top-1],a[t]));
                if(judge){
                    if(S[top-1]=='(' || S[top-1]==')')Pop(S);
                    else printf("%c",Pop(S));
                }
                else{
                    Push(S,a[t]);
                    t++;
                    break;
                }
            } 
        } 
    }
    while(top>0){
        if(S[top-1]=='(' || S[top-1]==')')Pop(S);
        else printf("%c",Pop(S));
    }
    putchar('\n');
    return 0;
}
