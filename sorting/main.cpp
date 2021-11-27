#include<iostream>
#include"sort.h"
#include"./../searching/search.h"
using namespace std;
int main()
{
    int A[]={2,5,1,4,12,19,13,3,14};
    bubble_sort(A,sizeof(A)/sizeof(int));
    selection_sort(A,sizeof(A)/sizeof(int));
    insertion_sort(A,sizeof(A)/sizeof(int));

    for(int& i:A)
        cout<<i<<"\t";
    return 0;
}