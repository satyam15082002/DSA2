//Static Array
#pragma once
#include<iostream>
#include<cassert>
namespace DSA
{
    const int MAX_SIZE=200;
    class Array
    {
        public:
            //Constructor And Destructor
            Array();
            Array(const int& size);
            ~Array()=default;
            //Property Getter
            int getSize() const;
            bool isEmpty() const;
            //Operations
            void insert(const int& index,const int& value);
            void remove(const int& index);
            //Operators
            int& operator[](const int& index);
            friend std::ostream& operator<<(std::ostream& out,Array& arr)
            {
                out<<"[";
                for(int i=0;i<arr.getSize();i++)
                {
                    out<<arr[i];
                    if(i!=arr.getSize()-1)
                        out<<",";                        
                }
                out<<"]";
                return out;
            }
            //Iterators
            int* begin() { return m_Arr; }
            int* end(){ return m_Arr+m_Size;} 
        private:
            int m_Size;
            int m_Arr[MAX_SIZE];
    };
    

};