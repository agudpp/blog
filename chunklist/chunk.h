#ifndef CHUNK_H
#define CHUNK_H

#include <type_traits>
#include <cstdint>

#include "Debug.h"


///
/// The class Chunk will be used to store a prefixed number of elements that
/// for now we will limit to be trivial constructible
///
template<typename T, unsigned int SIZE = 8>
class Chunk {
    // to avoid some issues when using this class we will make some checks here
    // to ensure the user don't try to use this with objects that will create
    // inconsistencies
    static_assert((std::is_pointer<T>::value || std::is_trivial<T>::value),
                  "We can only use objects that has trivial default constructor "
                  "or are pointers or basic types");

    // support a small number for now
    static_assert(SIZE < 256, "We maybe don't want chunks so big?");
public:

    // default constructor & destructor, note we will not destroy the elements
    // here
    inline Chunk();
    inline ~Chunk();

    // add an element
    inline void
    push_back(T element);

    // remove last element
    inline void
    pop_back(void);

    // get X element
    inline const T&
    operator[](int index) const;
    inline T&
    operator[](int index);

    // check if is full
    inline bool
    isFull(void) const;

    // is empty
    inline bool
    isEmpty(void) const;

    // check size
    inline unsigned int
    size(void) const;

    // clear
    inline void
    clear(void);


private:
    alignas (T) T m_data[SIZE];
    short m_size; // could be a short
};








////////////////////////////////////////////////////////////////////////////////
/// Inline stuff
///

template<typename T, unsigned int SIZE>
inline Chunk<T,SIZE>::Chunk() :
    m_size(0)
{}

template<typename T, unsigned int SIZE>
inline Chunk<T,SIZE>::~Chunk()
{}

////////////////////////////////////////////////////////////////////////////////
template<typename T, unsigned int SIZE>
inline void
Chunk<T,SIZE>::push_back(T element)
{
    ASSERT(!isFull());
    m_data[m_size++] = element;
}


////////////////////////////////////////////////////////////////////////////////
template<typename T, unsigned int SIZE>
inline void
Chunk<T,SIZE>::pop_back(void)
{
    m_size = isEmpty() ? 0 : m_size-1;
}


////////////////////////////////////////////////////////////////////////////////
template<typename T, unsigned int SIZE>
inline const T&
Chunk<T,SIZE>::operator[](int index) const
{
    ASSERT(index < m_size && index >= 0);
    return m_data[index];
}
template<typename T, unsigned int SIZE>
inline T&
Chunk<T,SIZE>::operator[](int index)
{
    ASSERT(index < m_size && index >= 0);
    return m_data[index];
}


////////////////////////////////////////////////////////////////////////////////
template<typename T, unsigned int SIZE>
inline bool
Chunk<T,SIZE>::isFull(void) const
{
    return m_size == SIZE;
}

////////////////////////////////////////////////////////////////////////////////
template<typename T, unsigned int SIZE>
inline bool
Chunk<T,SIZE>::isEmpty(void) const
{
    return m_size == 0;
}

////////////////////////////////////////////////////////////////////////////////
template<typename T, unsigned int SIZE>
inline unsigned int
Chunk<T,SIZE>::size(void) const
{
    return m_size;
}

////////////////////////////////////////////////////////////////////////////////
template<typename T, unsigned int SIZE>
inline void
Chunk<T,SIZE>::clear(void)
{
    m_size = 0; // note we are not calling any destructor since we are assuming
                // trivial types that don't require this
}



#endif // CHUNK_H
