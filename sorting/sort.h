#pragma once
#include<iostream>
void bubble_sort(int a[],int n);
void selection_sort(int a[],int n);
void insertion_sort(int a[],int n);
//Heap Sort functions
void heap_sort(int a[],int n);
void heapify(int a[],int n,int i);
//count sort
void countSort(int a[],int n);


void bubble_sort(int a[],int n)
{
    int temp;
    int count=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
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
void heapify(int a[],int n,int i)
{
	int largest=i,temp;
	int l=2*i+1,r=2*i+2;
	if(l<n&&a[l]>a[i])
		largest=l;
	if(r<n&&a[r]>a[largest])
		largest=r;
	if(largest!=i)
	{
		temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		heapify(a,n,largest);
	}
}
void heap_sort(int a[],int n)
{
	int i,temp;
	for(i=n/2-1;i>=0;i--)
		heapify(a,n,i);
	for(i=n-1;i>0;i--)
	{
		temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		heapify(a,i,0);
	}
}
void countSort(int a[],int n)
{
    const int range=100;
    int *output=new int[n];
    int count[range+1]={0};
    for(int i=0;i<n;i++)
        ++count[a[i]];
    for(int i=1;i<=range;++i)
        count[i]+=count[i-1];
    for(int i=0;i<n;i++)
    {
        output[count[a[i]]-1]=a[i];
        --count[a[i]];
    }
    for(int i=0;i<n;i++)
        a[i]=output[i];
    delete[] output;
}