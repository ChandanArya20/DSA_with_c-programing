#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
    int data;
    struct node *next;

}*first=NULL, *second=NULL, *third=NULL;

void create(int A[],int n);
void create2(struct node *start);
void display(struct node *p);
void display(struct node *p);
void Rdisplay(struct node *p);
int length(struct node *p);
int Rlength(struct node *p);
int sum(struct node *p);
int Rsum(struct node *p);
int max(struct node *p);
int min(struct node *p);
int search(struct node *p, int key);
void insertAtBeg(int data);
void insertAtEmpty(int data);
void insertAtEnd(struct node *start,int data);
void insertAtLoc(struct node*start,int pos,int data);
void insertAtSorted(struct node *start,int data);
void delete(struct node *start,int pos);
void removeDuplicate(struct node *start);
void reverse(struct node *start);
struct node *concate(struct node *fst, struct node *second);
void merge(struct node *p, struct node *q);
int detectCycle(struct node *start);
void removeCycle(struct node *start);
int midNode(struct node *start);



void create(int A[],int n)
{
    int i;
    struct node *t,*last;
    first=(struct node *)malloc(sizeof(struct node)); 
    first->data=A[0];
    first->next=NULL;
    last=first;
    
    for(i=1;i<n;i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void create2(struct node *start)
{
    int i,n,data;
    printf("Enter the numbers of elements: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the data to be inserted: ");
        scanf("%d",&data);
        insertAtEnd(start,data);
    }
}
void display(struct node *h)
{
    do
    {
        printf("%d ",h->data);
        h=h->next;
    }while(h!=NULL);
    
}
void Rdisplay(struct node *p)
{
    while(p!=NULL)
    {
        Rdisplay(p->next);
        printf("%d ",p->data);
    }
    
}
int length(struct node *p)
{
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}
int Rlength(struct node *p)
{
    if(p!=NULL)
        return Rlength(p->next)+1;
    else
        return 0;
}
int sum(struct node *p)
{
    int sum=0;
    while(p!=NULL)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}
int Rsum(struct node *p)
{
    if(p==NULL)
        return 0;
    else
        return Rsum(p->next)+p->data; 
}
int max(struct node *p)
{
    int max=INT_MIN;
    while(p!=NULL)
    {
        if(p->data>max)
            max=p->data;
        p=p->next;
    }
    return max;
}
int min(struct node *p)
{
    int min=INT_MAX;
    while(p!=NULL)
    {
        if(p->data<min)
            min=p->data;
        p=p->next;
    }
    return min;
}
int search(struct node *p, int key)
{
    int pos=0;
    while(p!=NULL)
    {
        pos++;
        if(p->data==key)
            return pos;
        p=p->next;
            
    }
    return -1;
}
void insertAtBeg(int data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=first;
    first=temp;
}
void insertAtEmpty(int data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    first=temp;
}
void insertAtEnd(struct node *start,int data)
{
    struct node *temp, *p;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL; 
    if(first==NULL)
        first=temp;
    else
    {
        p=start;
        while(p->next!=NULL)
            p=p->next;
        p->next=temp;  
    }
}
void insertAtLoc(struct node *start,int pos,int data)
{
    struct node *temp,*p;
    if(pos<1 || pos>length(first)+1)
        return;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(pos==1)
    {
        if(start=NULL)
        {
            first=temp;
        }
        else
        {
            temp->next=first;
            first=temp;
        }
    }
    else
    {
        p=start;
        for(int i=1; i<pos-1; i++)
            p=p->next;
        temp->next=p->next;
        p->next=temp;
    } 
}
void insertAtSorted(struct node *start,int data)
{
    struct node *temp, *p, *q=NULL;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(start==NULL)
    {
        first=temp;
    }
    else
    {
        p=start;
        while(p!=NULL && data > p->data)
        {
            q=p;
            p=p->next;
        }
        if(p==start)                    //for begining
        {
            temp->next=start;
            first=temp;
        }
        else
        {
            temp->next=p;
            q->next=temp;
        }
    }
}
void delete(struct node *start,int pos)
{
    struct node *p=start, *temp=NULL;
    int i;                                  //for storing deleted data
    if(pos<1 || pos > length(first))
        return;
    if(pos==1)
    {
        first=first->next;
        free(start);
    }
    else
    {
        p=start;
        for(i=1;i<pos-1;i++)
            p=p->next;
        temp=p->next;
        p->next=temp->next;
        free(temp);
    }
}

void removeDuplicate(struct node *start)      //only for sorted linked List
{ 
    struct node *currPtr=start; 
    struct node *nextPtr=start->next;
    while(nextPtr!=NULL)
    {
        if(currPtr->data == nextPtr->data)
        {
            currPtr->next=nextPtr->next;
            free(nextPtr);
            nextPtr=currPtr->next;           
        }
        else
        {
            currPtr=nextPtr;
            nextPtr=nextPtr->next;
        }
    }
}
void reverse(struct node *start)
{
    struct node *p=start;  
    struct node *prevPtr=NULL, *nextPtr=start;
    while(p!=NULL)
    {
        nextPtr=p->next;
        p->next=prevPtr;
        prevPtr=p;
        p=nextPtr;
    }
    first=prevPtr;
}
struct node *concate(struct node *fst, struct node *sec)
{
    struct node *p;
    if(fst==NULL)
        fst=sec;
    p=fst;
    while(p->next!=NULL)
        p=p->next;
    p->next=sec;
    return fst;
}
void merge(struct node *p, struct node *q)
{
    struct node *last;
    if(p->data<q->data)
    {
        third=last=p;
        p=p->next;
        last->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        last->next=NULL;
    }
    while(p!=NULL && q!=NULL)
    {
        if(p->data<q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
        
    }
    if(p!=NULL)
        last->next=p;
    if(q!=NULL)
        last->next=q;
}
int detectCycle(struct node *start)
{
    struct node *slow, *fast;
    slow=fast=start;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return 1;
    }
    return 0;
}
void removeCycle(struct node *start)
{
    struct node *slow, *fast;
    slow=fast=start; 
    do
    {
        slow=slow->next;
        fast=fast->next->next;
    }while(slow!=fast);
    fast=start;
    while(slow->next!=fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}
int midNode(struct node *start)
{
    struct node *p,*q;
    p=q=start;
    while(q!=NULL)
    {
        q=q->next;
        if(q!=NULL)
            q=q->next;
        if(q!=NULL)
            p=p->next;
    }
    return p->data;
}
