#include <iostream>
#include <list>
#include <cassert>

#include "nasty_list.h"
#include "chunk_list.h"
#include "TimeHelper.h"
#include "Defines.h"
#include "Allocators.h"


#define DATA_SIZE_ALLOCATOR (ELEMENTS_PER_LIST*LIST_COUNT)


typedef Chunk<int,CHUNK_SIZE> ChunkType;
typedef StaticAllocator<Node<int>, DATA_SIZE_ALLOCATOR> StaticNodeAllocator;
typedef HeapAllocator<Node<int>> HeapNodeIntAllocator;
typedef HeapAllocator<Node<ChunkType>> HeapNodeChunkAllocator;

////////////////////////////////////////////////////////////////////////////////
/// normal allocator ("malloc")
///
static void
normalAllocator(void)
{
    StaticNodeAllocator::init();

    //typedef nasty_list<int,HeapNodeIntAllocator> ListT;
    typedef nasty_list<int, StaticNodeAllocator> ListT;
    typedef ChunkList<int, HeapNodeChunkAllocator, CHUNK_SIZE> ChunkListT;

    ListT normalLists[LIST_COUNT];
    ChunkListT chunkLists[LIST_COUNT];
    std::list<int> stdlist[LIST_COUNT];

    for (int j = 0; j < LIST_COUNT; ++j) {
        for (int i = 0; i < ELEMENTS_PER_LIST; i++) {
            normalLists[j].addElement(i);
            chunkLists[j].addElement(i);
            stdlist[j].push_back(i);
        }
    }

    // test the time to get the elements
    int d1 = 0, d2 = 0, d3 = 0, d4 = 0;
    double t1 = 0., t2 = 0.;

    t1 = TimeHelper::currentTime();
    for (unsigned int i = 0; i < ROUNDS; ++i) {
        for (unsigned int j = 0; j < LIST_COUNT; ++j) {
            auto beg = normalLists[j].begin();
            auto end = normalLists[j].end();
            for (; beg != end; ++beg) {
                d1 += *beg;
            }
        }
    }
    t2 = TimeHelper::currentTime();
    const double normalListTime = t2 - t1;


    t1 = TimeHelper::currentTime();
    for (unsigned int i = 0; i < ROUNDS; ++i) {
        for (unsigned int j = 0; j < LIST_COUNT; ++j) {
            auto beg = chunkLists[j].begin();
            auto end = chunkLists[j].end();
            for (; beg != end; ++beg) {
                d2 += *beg;
            }
        }
    }
    t2 = TimeHelper::currentTime();
    const double chunklListTime = t2 - t1;

    // applying operation
    struct OpSum {
        int sum;
        OpSum() : sum(0) {}

        void operator()(int i) {sum+=i;}
    } opSum;
    t1 = TimeHelper::currentTime();
    for (unsigned int i = 0; i < ROUNDS; ++i) {
        for (unsigned int j = 0; j < LIST_COUNT; ++j) {
            chunkLists[j].applyToAll(opSum);
        }
    }
    t2 = TimeHelper::currentTime();
    d4 = opSum.sum;
    const double chunklListFunctorTime = t2 - t1;


    t1 = TimeHelper::currentTime();
    for (unsigned int i = 0; i < ROUNDS; ++i) {
        for (unsigned int j = 0; j < LIST_COUNT; ++j) {
            auto beg = stdlist[j].begin();
            auto end = stdlist[j].end();
            for (; beg != end; ++beg) {
                d3 += *beg;
            }
        }
    }
    t2 = TimeHelper::currentTime();
    const double stdListTime = t2 - t1;

    std::cout << "d1: " << d1 << ", d2: " << d2 << ", d3: " << d3 << std::endl;

    assert(d1 == d2);
    assert(d1 == d3);
    assert(d1 == d4);

    std::cout << "normalListTime: " << normalListTime << std::endl
              << "chunklListTime: " << chunklListTime << std::endl
              << "chunklListFunctorTime: " << chunklListFunctorTime << std::endl
              << "stdListTime: " << stdListTime << std::endl;

    const double perfGainChunkList = stdListTime / chunklListTime;
    const double perfGainChunklListFunctorTime = stdListTime / chunklListFunctorTime;

    std::cout << "perfGainChunkList: " << perfGainChunkList << std::endl
              << "perfGainChunklListFunctorTime: " << perfGainChunklListFunctorTime << std::endl;

}

int
main(void)
{
    normalAllocator();


//    typedef List<int, HeapAllocator<Node<int>>> ListT;
//    typedef ChunkList<int, HeapAllocator<Node<Chunk<int,8>>>, 8> ChunkListT;

//    ListT normalLists[LIST_COUNT];
//    ChunkListT chunkLists[LIST_COUNT];

//    for (int j = 0; j < LIST_COUNT; ++j) {
//        for (int i = 0; i < ELEMENTS_PER_LIST; i++) {
//            normalLists[j].addElement(i);
//            chunkLists[j].addElement(i);
//        }
//    }

//    // try the iterating elements
//    auto it = list.begin();
//    auto end = list.end();
//    for (; it != end; ++it) {
//        std::cout << *it << std::endl;
//    }


//     chunkList;
//    for (int i = 0; i < 100; i++) {
//        chunkList.addElement(i);
//    }
//    auto it = chunkList.begin();
//    auto end = chunkList.end();
//    for (; it != end; ++it) {
//        std::cout << *it << std::endl;
//    }


    std::cout << "Hello World!" << std::endl;
    return 0;
}

