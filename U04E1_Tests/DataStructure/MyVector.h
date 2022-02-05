#ifndef _BABY_VECTOR_H
#define _BABY_VECTOR_H

#include "../Exceptions/MemoryAlreadyAllocatedException.h"

template <typename T>
class MyVector
{
public:
    MyVector();
    ~MyVector();

    void PushBack( T item )         noexcept;
    void PopAt( size_t index );
    const T& GetAt( size_t index )  const;
    size_t Size()                   const noexcept;

private:
    T*      m_array;
    size_t  m_arraySize;
    size_t  m_itemCount;

    void Resize()                   noexcept;
    void AllocateMemory( size_t size );
    void DeallocateMemory()         noexcept;
    bool IsFull()                   const noexcept;

    friend class MyVectorTester;
};

template <typename T>
MyVector<T>::MyVector()
{
    m_array = nullptr;
    m_arraySize = 0;
    m_itemCount = 0;
}

template <typename T>
MyVector<T>::~MyVector()
{
    DeallocateMemory();
}

template <typename T>
void MyVector<T>::AllocateMemory( size_t size )
{
    if ( m_array != nullptr )
    {
        throw MemoryAlreadyAllocatedException( "Memory already allocated! Cannot allocate more!" );
    }

    m_array = new T[size];
    m_arraySize = size;
    m_itemCount = 0;
}

template <typename T>
void MyVector<T>::DeallocateMemory() noexcept
{
    if ( m_array != nullptr )
    {
        delete [] m_array;
        m_array = nullptr;
        m_arraySize = 0;
        m_itemCount = 0;
    }
}

template <typename T>
void MyVector<T>::Resize() noexcept
{
    // Allocate space for bigger array
    size_t newSize = m_arraySize + 5;
    T* newArray = new T[newSize];

    // Copy over elements from old location
    for ( size_t i = 0; i < m_arraySize; i++ )
    {
        newArray[i] = m_array[i];
    }

    // Destroy old memory
    delete [] m_array;

    // Update pointer to point to new address
    m_array = newArray;
    m_arraySize = newSize;
}

template <typename T>
bool MyVector<T>::IsFull() const noexcept
{
    return ( m_itemCount == m_arraySize );
}

template <typename T>
size_t MyVector<T>::Size() const noexcept
{
    return m_itemCount;
}

template <typename T>
void MyVector<T>::PushBack( T item ) noexcept
{
    if ( m_array == nullptr )
    {
        AllocateMemory( 5 );
    }
    else if ( IsFull() )
    {
        Resize();
    }

    m_array[m_itemCount] = item;
    m_itemCount++;
}

template <typename T>
void MyVector<T>::PopAt( size_t index )
{
    if ( index < 0 || index >= m_itemCount )
    {
        throw out_of_range( "Index is out of range! (at MyVector<T>::Remove( size_t index ))" );
    }

    // Shift everything left
    for ( size_t i = index; i < m_itemCount - 1; i++ )
    {
        m_array[i] = m_array[i+1];
    }
}

template <typename T>
const T& MyVector<T>::GetAt( size_t index ) const
{
    if ( index < 0 || index >= m_itemCount )
    {
        throw out_of_range( "Index is out of range! (at MyVector<T>::Get( size_t index ))" );
    }

    return m_array[index];
}


#endif
