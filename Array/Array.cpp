#include"Array.h" 

namespace DSA
{
    Array::Array():m_Size(0)
    {

    }
    Array::Array(const int& size)
    {
        assert(size<=MAX_SIZE);
        m_Size=size;
    }
    int Array::getSize() const
    {
        return m_Size;
    }
    bool Array::isEmpty() const
    {
        return m_Size==0;
    }
    int& Array::operator[](const int& index)
    {
        return m_Arr[index];
    }
    void Array::insert(const int& index,const int& value)
    {
        assert(index<m_Size);
        for(int i=m_Size-1;i>=index;i--)
        {
            m_Arr[i+1]=m_Arr[i];
        }
        m_Arr[index]=value;
        m_Size++;
    }
    void Array::remove(const int& index)
    {
        assert(index<m_Size);
        for(int i=index;i<m_Size-1;i++)
        {
            m_Arr[i]=m_Arr[i+1];
        }
        m_Size--;
    }
        
};