#include <stdio.h>
struct point{
    int *prior, *next;
    int data;
    int freq;
};
int n;
struct point *head;
void init()
{
    int x;
    struct point *now;
    for(int i=0;i<n;i++)
    {
        scanf("%d", &x);
        struct point *p = (struct point *)malloc(sizeof(struct point));
        p->data = x;
        p->freq = 0;
        p->prior = NULL;
        p->next = NULL;
        if(head == NULL)
        {
            head = p;
        }
        else
        {   
            if(now==NULL)now=head;
            while(now->next != NULL)
            {
                now = now->next;
            }
            now->next = p;
            p->prior = now;
        }
    }
}
void locate(struct point *head, int x)
{
    struct point *now = head;
    while(now->data != x)
    {
        now = now->next;
    }
    now->freq++;
    //printf("%d\n", now->freq);
}
int main() {
    scanf("%d", &n);
    init();
    int x;
    while(scanf("%d", &x))
    {
        locate(head,x);
    }
    struct point a[n+10];
    for(int i=0;i<n;i++)
    {
        a[i] = *head;
        head = head->next;
    }
    
    return 0;
}