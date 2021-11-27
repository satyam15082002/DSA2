#pragma once
#include<iostream>
void bubble_sort(int a[],int n);
void selection_sort(int a[],int n);
void insertion_sort(int a[],int n);



void bubble_sort(int a[],int n)
{
    int temp;
    int count=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            count++;
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        count++;
    }
    std::cout<<"Bubble sort count:"<<count<<std::endl;
}
void selection_sort(int a[],int n)
{
    int minidx,temp;
    int count=0;    
    for(int i=0;i<n-1;i++)
    {
        minidx=i;
        for(int j=i;j<n;j++)
        {
            if(a[j]<a[minidx])
                minidx=j;
            count++;
        }
        temp=a[minidx];
        a[minidx]=a[i];
        a[i]=temp;
        count++;
    }
    std::cout<<"Selction sort count:"<<count<<std::endl;

}
void insertion_sort(int a[],int n)
{
    int t,count=0;
    for(int i=1;i<n;i++)
    {
        t=a[i];
        int j=i-1;
        while(j>=0&&a[j]>t)
        {
            a[j+1]=a[j];
            j--;
            count++;
        }
        a[j+1]=t;
        count++;
    }
    std::cout<<"Insertion sort count:"<<count<<std::endl;

}