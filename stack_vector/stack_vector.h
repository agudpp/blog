/*
 * File stack_vector.h, stack_vector
 * Created on 19/02/2015.
 *
 * Author: Agustin Perez Paladini
 *
*/

#ifndef STACK_VECTOR_H
#define STACK_VECTOR_H


#include <cstring> // memcpy
#include <type_traits>

#include "Debug.h"


///
/// This class is intended to be used only for built in types that doesn't
/// requiere construction / destruction of the elements.
/// Obviously could be extended to support this, but not now :)
///
template <typename T, unsigned int MAX_SIZE = 64>
class stack_vector
{
    // to avoid some issues when using this class we will make some checks here
    // to ensure the user don't try to use this with objects that will create
    // inconsistencies
    static_assert((std::is_pointer<T>::value || std::is_trivial<T>::value),
                  "We can only use objects that has trivial default constructor "
                  "or are pointers or basic types");



public:
    stack_vector() : m_size(0) {};
    ~stack_vector() {};

    // @brief Get the front element of the vector.
    // @returns the first element
    // @requires size > 0
    //
    inline T&
    front(void);
    inline const T&
    front(void) const;

    // @brief Get the back element (last) of the vector.
    // @return the last element of the vector
    // @requires size > 0
    //
    inline T&
    back(void);
    inline const T&
    back(void) const;

    // @brief Remove all the elements of the vector
    //
    inline void
    clear(void);

    // @brief Return the number of elements that this vector contain
    //
    inline unsigned int
    size(void) const;
    inline unsigned int
    max_size(void) const;

    // @brief Check if the vector is empty / full
    //
    inline bool
    empty(void) const;
    inline bool
    full(void) const;

    // @brief Resize the number of elements of the vector
    // @param size  The new size of the vector (size < MAX_SIZE).
    //
    inline void
    resize(unsigned int size);

    // @brief Get an element of the vector.
    // @param i     The index of the element we want (i < size)
    //
    inline T&
    operator[](unsigned int i);
    inline const T&
    operator[](unsigned int i) const;

    // @brief Remove the last element of the vector
    // @requires size > 0
    //
    inline void
    pop_back(void);

    // @brief Insert a new element in the back of this vector
    // @param element   The element we want to add in the last position of the
    //                  vector
    //
    inline void
    push_back(const T& element);

    // @brief Insert a element in a specific position BUT TAKE INTO ACCOUNT
    //        that this insertion will not maintain the order of the elements..
    //        Basically we will do: vec.push_back(vec[i]); vec[i] = element;
    // @param i         The position where we want to add the element (i < size).
    // @param element   The element we want to add at the i-th position.
    //
    inline void
    disorder_insert(unsigned int i, const T& element);

    // @brief Remove an element from an specific position BUT TAKE INTO ACCOUNT
    //        that the order will be modified. We will remove the i-th element
    //        but putting in that position the last one:
    //        vec[i] = vec.back(); vec.pop_back();
    // @param i         The position of the element we want to remove (i < size)
    //
    inline void
    disorder_remove(unsigned int i);

    // @brief Erase an element from the array maintaining the order
    // @param i         The i-th element we wanto to remove (i < size).
    //
    inline void
    erase(unsigned int i);

    // @brief Returns the pointers for the begin position and the end position
    //
    inline T*
    begin(void);
    inline const T*
    begin(void) const;
    inline T*
    end(void);
    inline const T*
    end(void) const;


    ////////////////////////////////////////////////////////////////////////////
    // Operators
    //
    inline stack_vector&
    operator=(const stack_vector<T, MAX_SIZE>& other);
    inline bool
    operator==(const stack_vector<T, MAX_SIZE>& other) const;


private:
    T m_data[MAX_SIZE];
    unsigned int m_size;
};




////////////////////////////////////////////////////////////////////////////////
// Inline stuff
//

////////////////////////////////////////////////////////////////////////////////
template <typename T, unsigned int MAX_SIZE>
inline T&
stack_vector<T,MAX_SIZE>::front(void)
{
    ASSERT(m_size > 0);
    return m_data[0];
}
template <typename T, unsigned int MAX_SIZE>
inline const T&
stack_vector<T,MAX_SIZE>::front(void) const
{
    ASSERT(m_size > 0);
    return m_data[0];
}

////////////////////////////////////////////////////////////////////////////////
template <typename T, unsigned int MAX_SIZE>
inline T&
stack_vector<T,MAX_SIZE>::back(void)
{
    ASSERT(m_size > 0);
    return m_data[m_size - 1];
}
template <typename T, unsigned int MAX_SIZE>
inline const T&
stack_vector<T,MAX_SIZE>::back(void) const
{
    ASSERT(m_size > 0);
    return m_data[m_size - 1];
}

////////////////////////////////////////////////////////////////////////////////
template <typename T, unsigned int MAX_SIZE>
inline void
stack_vector<T,MAX_SIZE>::clear(void)
{
    // note that we are not calling any destructor here.
    m_size = 0;
}

////////////////////////////////////////////////////////////////////////////////
template <typename T, unsigned int MAX_SIZE>
inline unsigned int
stack_vector<T,MAX_SIZE>::size(void) const
{
    return m_size;
}
template <typename T, unsigned int MAX_SIZE>
inline unsigned int
stack_vector<T,MAX_SIZE>::max_size(void) const
{
    return MAX_SIZE;
}

////////////////////////////////////////////////////////////////////////////////
template <typename T, unsigned int MAX_SIZE>
inline bool
stack_vector<T,MAX_SIZE>::empty(void) const
{
    return m_size == 0;
}
template <typename T, unsigned int MAX_SIZE>
inline bool
stack_vector<T,MAX_SIZE>::full(void) const
{
    return m_size == MAX_SIZE;
}

////////////////////////////////////////////////////////////////////////////////
template <typename T, unsigned int MAX_SIZE>
inline void
stack_vector<T,MAX_SIZE>::resize(unsigned int size)
{
    ASSERT(size <= MAX_SIZE);
    // no constructors called!
    m_size = size;
}

////////////////////////////////////////////////////////////////////////////////
template <typename T, unsigned int MAX_SIZE>
inline T&
stack_vector<T,MAX_SIZE>::operator[](unsigned int i)
{
    ASSERT(i < m_size);
    return m_data[i];
}
template <typename T, unsigned int MAX_SIZE>
inline const T&
stack_vector<T,MAX_SIZE>::operator[](unsigned int i) const
{
    ASSERT(i < m_size);
    return m_data[i];
}

////////////////////////////////////////////////////////////////////////////////
template <typename T, unsigned int MAX_SIZE>
inline void
stack_vector<T,MAX_SIZE>::pop_back(void)
{
    ASSERT(m_size > 0);
    --m_size;
}

////////////////////////////////////////////////////////////////////////////////
template <typename T, unsigned int MAX_SIZE>
inline void
stack_vector<T,MAX_SIZE>::push_back(const T& element)
{
    ASSERT(m_size < MAX_SIZE);
    m_data[m_size++] = element;
}

////////////////////////////////////////////////////////////////////////////////
template <typename T, unsigned int MAX_SIZE>
inline void
stack_vector<T,MAX_SIZE>::disorder_insert(unsigned int i, const T& element)
{
    ASSERT(i < m_size);
    ASSERT(m_size < MAX_SIZE);
    push_back(m_data[i]);
    m_data[i] = element;
    ++m_size;
}

////////////////////////////////////////////////////////////////////////////////
template <typename T, unsigned int MAX_SIZE>
inline void
stack_vector<T,MAX_SIZE>::disorder_remove(unsigned int i)
{
    ASSERT(i < m_size);
    m_data[i] = back();
    pop_back();
}

////////////////////////////////////////////////////////////////////////////////
template <typename T, unsigned int MAX_SIZE>
inline void
stack_vector<T,MAX_SIZE>::erase(unsigned int i)
{
    ASSERT(i < m_size);
    //std::memcpy(m_data + i, m_data + i + 1, sizeof(T) * (m_size - i));
    T* beg = begin() + i, *last = end() - 1;
    while (beg != last) {
        *beg = *(beg+1);
        ++beg;
    }
    --m_size;
}

////////////////////////////////////////////////////////////////////////////////
template <typename T, unsigned int MAX_SIZE>
inline T*
stack_vector<T,MAX_SIZE>::begin(void)
{
    return &(m_data[0]);
}
template <typename T, unsigned int MAX_SIZE>
inline const T*
stack_vector<T,MAX_SIZE>::begin(void) const
{
    return &(m_data[0]);
}

template <typename T, unsigned int MAX_SIZE>
inline T*
stack_vector<T,MAX_SIZE>::end(void)
{
    return &m_data[m_size]; // end + 1
}
template <typename T, unsigned int MAX_SIZE>
inline const T*
stack_vector<T,MAX_SIZE>::end(void) const
{
    return &m_data[m_size]; // end + 1
}


////////////////////////////////////////////////////////////////////////////////
template <typename T, unsigned int MAX_SIZE>
inline stack_vector<T,MAX_SIZE>&
stack_vector<T,MAX_SIZE>::operator=(const stack_vector<T, MAX_SIZE>& other)
{
    clear();
    // memcpy is much more faster.
    for (const T* b = other.begin(), *end = other.end(); b != end; ++b) {
        push_back(*b);
    }
}

template <typename T, unsigned int MAX_SIZE>
inline bool
stack_vector<T,MAX_SIZE>::operator==(const stack_vector<T, MAX_SIZE>& other) const
{
    if (size() != other.size()) {
        return false;
    }
    T* b1 = begin(), *b2 = other.begin(), *last = end();
    while (b1 != last) {
        if (*b1 != *b2) {
            return false;
        }
        ++b1; ++b2;
    }
    return true;
}


#endif // STACK_VECTOR_H
