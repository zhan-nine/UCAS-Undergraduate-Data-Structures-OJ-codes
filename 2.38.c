#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct point{
    struct point *prior, *next;
    int data;
    int freq;
    int first_time;
};
struct point a[1000005];
int n;
struct point *head;
void init()
{
    struct point *now;
    for(int i=0;i<n;i++)
    {
        //cout<<a[i].data<<endl;
        struct point *p = (struct point *)malloc(sizeof(struct point));
        p->data = a[i].data;
        p->freq = a[i].freq;
        p->first_time = a[i].first_time;
        p->prior = NULL;
        p->next = NULL;
        if(head == NULL)
        {
            head = p;
            now=head;
        }
        else
        {   
            now->next = p;
            p->prior = now;
            now=now->next;
        }
    }
}
void locate(struct point *head, int x, int time)
{
    struct point *now = head;
    while(now->data != x && now->next != NULL)
    {
        //cout<<now->data<<" ";
        now = now->next;
    }
    if(now->data==x)
    {
        now->freq++;
        if(now->first_time==0) now->first_time = time;
    }
    //putchar('\n');
    //printf("%d\n", now->freq);
}
bool cmp(struct point a, struct point b)
{
    if(a.freq == b.freq)
    {
        if(a.first_time == b.first_time)
        {
            return a.data <= b.data;
        }
        return a.first_time < b.first_time;
    }
    return a.freq > b.freq;
}
int main() {
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &a[i].data);
        a[i].freq = 0;
        a[i].first_time = 0;
    }
    init();
    //cout<<"init"<<endl;
    int x,t=1;
    while(scanf("%d", &x))
    {
        if(x==-1)
        {
            break;
        }   
        locate(head,x,t++);
        //cout<<x<<endl;
        x=-1;
    }

    for(int i=0;i<n;i++)
    {
        a[i] = *head;
        struct point *p=head;
        head = head->next;
        free(p);
    }
    head=NULL;
    //sort(a,a+n,cmp);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(!cmp(a[i],a[j]))
            {
                struct point temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    init();
    for(struct point *p=head;p!=NULL;p=p->next)
    {
        //printf("%d %d %d\n", p->data, p->freq,p->first_time);
        printf("%d ", p->data);
    }
    putchar('\n');
    return 0;
}