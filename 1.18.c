#include <stdio.h>
int male_score[6],female_score[6];

int main()
{
    char name[1005],gender[1005],school[1005];
    int score;
    while(scanf("%s",name)!=EOF)
    {
        //cin>>gender>>school>>score;
        scanf("%s %s %d",gender,school,&score);
        if(gender[0]=='M') male_score[school[0]-'A']+=score;
        else female_score[school[0]-'A']+=score;
    }
    for(int i=0;i<5;i++)
    {
        if(male_score[i]) printf("%c %s %d\n",'A'+i,"M",male_score[i]);
        if(female_score[i]) printf("%c %s %d\n",'A'+i,"F",female_score[i]);
        if(male_score[i]+female_score[i]!=0) printf("%c %d\n",'A'+i,male_score[i]+female_score[i]);
    }
    return 0;
}