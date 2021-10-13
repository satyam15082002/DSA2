#include<iostream>
#include"Array.h"
using namespace std;
int main()
{
    DSA::Array a(5);
    for(int i=0;i<5;i++)
        a[i]=i+1;
    cout<<endl;
    cout<<a;
    a.insert(0,5);
    cout<<a;
    return 0;
}