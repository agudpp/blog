#ifndef CHUNK_LIST_H
#define CHUNK_LIST_H

#include "Debug.h"
#include "chunk.h"
#include "nasty_list.h"


// TODO: implement here the ChunkList class using the List class to hold the
//       chunks but we need to change the iterators (how they will work).
//
template<typename T, typename NodeAlloc, unsigned int CHUNK_SIZE = 8>
class ChunkList {
    // helper typedefs
    typedef Chunk<T, CHUNK_SIZE>    ChunkNode;
    typedef nasty_list<ChunkNode, NodeAlloc> ListType;

public:
    // iterator
    //
    template<typename T2>
    class Iterator {
    public:
        // ugly interface but for the test will be useful
        Iterator(Node<ChunkNode>* n) : m_node(n), m_current(0) {}

        T2& operator*()
        {
            ASSERT(m_node != 0);
            return m_node->data[m_current];
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
            // check if we have to jump from the node or not
            ChunkNode& cn = m_node->data;
            ++m_current;
            if (m_current == cn.size()) {
                // need to jump to the next
                m_node = m_node->next;
                m_current = 0;
            }
        }

    private:
        Node<ChunkNode>* m_node;
        int m_current;
    };
    friend class Iterator<T>;

public:
    // add an element only, not remove since we don't need it now
    void
    addElement(T d)
    {
        // this is slow but don't care about this now, is not
        // the idea of the test
        ChunkNode* lchunk = m_list.getLast();
        if (lchunk == 0) {
            // allocate new chunk
            m_list.addElement(ChunkNode());
            lchunk = m_list.getLast();
        }

        // now we need to check if we have to add a new chunk if it is full
        if (lchunk->isFull()) {
            // UGLYYYYYYYYYYYYY
            m_list.addElement(ChunkNode());
            lchunk = m_list.getLast();
        }

        // now we know we have space, add the element to the chunk
        lchunk->push_back(d);
    }

    // return the iterators
    Iterator<T>
    begin(void)
    {
        return Iterator<T>(m_list.getFirstNode());
    }
    Iterator<T>
    end(void)
    {
        return Iterator<T>(0);
    }

    template<typename OP>
    void applyToAll(OP& op)
    {

//        auto beg = m_list.begin();
//        auto end = m_list.end();
//        while (beg != end) {
//            ChunkNode& cn = *beg;
//            for (int i = 0; i < cn.size(); ++i) {
//                op(cn[i]);
//            }
//            ++beg;
//        }

        Node<ChunkNode>* first = m_list.getFirstNode();
        while (first != 0) {
            const ChunkNode& d = first->data;
            for (unsigned int i = 0; i < d.size(); ++i) {
                op(d[i]);
            }
            first = first->next;
        }
    }

private:
    ListType m_list;
};



#endif // CHUNK_LIST_H
