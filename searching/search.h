#pragma once

int linear_search(int a[],int size,int target);
int binary_search(int a[],int size,int target);

//return index if element found else return -1
int linear_search(int a[],int size,int target)
{
    for(int i=0;i<size;i++)
        if(a[i]==target)
            return i;
    
    return -1;
}
//return index if element found else return -1
int binary_search(int a[],int size,int target)
{
    int low=0,high=size-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==target)
            return mid;
        else if(target>a[mid])
            low=mid+1;
        else
            high=mid-1;
    } 
    return -1;  
}