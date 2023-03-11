#include"header.h"
int main()
{
    int A[]={3,5,7,10,25,32,76,52,90};
    create(A,9);
    system("cls");


    // struct node *t1, *t2;
    // t1=first->next->next;
    // t2=first->next->next->next->next->next->next->next;
    // t2->next=t1;
    // int B[]={12,22,31,40,60,78};
    // create2(B,6);

   
    // printf("%d\n",length(first));
    // printf("%d\n",Rlength(first));
    // printf("%d\n",Rsum(first));
    // printf("%d\n",max(first));
    // printf("%d\n",min(first));
    // printf("%d\n",search(first,100));
    // insertAtBeg(76);
    // insertAtEmpty(90);
    // insertAtEnd(first,78);
    // insertAtLoc(first,1,20);
    // insertAtSorted(first,8);
    // delete(first,1);
    // printf("%d\n",checkSorting(first));
    // removeDuplicate(first);
    // reverse(first);
    // first=concate(first,second);
    // merge(first,second);
    // printf("%d\n",detectCycle(first));
    // removeCycle(first);
    // printf("%d\n",detectCycle(first));
    // create2(first);
    printf("%d\n",midNode(first));

    


    display(first);
    printf("\nLength=%d\n",length(first)); 
    // // display(second);
    // printf("\nLength=%d",length(second));

    return 0;
}