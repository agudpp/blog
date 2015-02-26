#ifndef NASTY_LIST_H
#define NASTY_LIST_H

#include "Debug.h"


/// define a simple list implementation only for this test
///
template<typename T>
struct Node {
    T data;
    Node* next;

    Node() : next(0) {}
};


template<typename T, typename AllocT>
class nasty_list {
public:

    // iterator, should go outside :(
    //
    template<typename T2>
    class Iterator {
    public:
        // ugly interface but for the test will be useful
        Iterator(Node<T2>* n) : m_node(n) {}

        T2& operator*()
        {
            ASSERT(m_node != 0);
            return m_node->data;
        }
        const T2& operator*() const
        {
            ASSERT(m_node != 0);
            return m_node->data;
        }

        bool operator==(const Iterator<T2>& o) const
        {
            return m_node == o.m_node;
        }
        bool operator!=(const Iterator<T2>& o) const
        {
            return m_node != o.m_node;
        }
        void operator++(void)
        {
            ASSERT(m_node != 0);
            m_node = m_node->next;
        }

    private:
        Node<T2>* m_node;
    };
    friend class Iterator<T>;

public:
    nasty_list(void) : m_first(0) {}
    ~nasty_list(void)
    {
        // deallocate all the elements
        Node<T>* it = m_first;
        while(it != 0) {
            m_first = it->next;
            AllocT::deallocate(it);
            it = m_first;
        }
    }

    // add an element only, not remove since we don't need it now
    void
    addElement(T d)
    {
        Node<T>* elem = AllocT::allocate();
        elem->data = d;
        if (m_first == 0) {
            m_first = elem;
            return;
        }
        // get the last
        Node<T>* last = m_first;
        while (last->next != 0) {
            last = last->next;
        }
        last->next = elem;
    }

    // return the iterators
    Iterator<T>
    begin(void)
    {
        return Iterator<T>(m_first);
    }
    Iterator<T>
    end(void)
    {
        return Iterator<T>(0);
    }

    T*
    getLast(void)
    {
        if (m_first == 0) {
            return 0;
        }
        // get the last
        Node<T>* last = m_first;
        while (last->next != 0) {
            last = last->next;
        }
        return &last->data;
    }

    Node<T>*
    getFirstNode(void)
    {
        return m_first;
    }

private:
    Node<T>* m_first;
};



#endif // NASTY_LIST_H
