#include<iostream>
#include"sort.h"
using namespace std;

int main()
{
    int A[]={2,5,1,4,12,19,13,3,14};
    insertion_sort(A,sizeof(A)/sizeof(int));
    selection_sort(A,sizeof(A)/sizeof(int));
    bubble_sort(A,sizeof(A)/sizeof(int));

    
    for(int& i:A)
        cout<<i<<"\t";
    return 0;
}