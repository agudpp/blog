#ifndef ALLOCATORS_H
#define ALLOCATORS_H

#include <stack>


// define a "nasty" allocator
template<typename T>
struct HeapAllocator {
    static T* allocate(void) {return new T;}
    static void deallocate(T* t) {delete t;}
};

template<typename T, unsigned int SIZE>
struct StaticAllocator {
    static T mem[SIZE];
    static std::stack<T*> data;

    static void
    init(void)
    {
        for (unsigned int i = 0; i < SIZE; ++i) {
            data.push(&(mem[i]));
        }
    }

    static T* allocate(void)
    {
        T* r = data.top();
        data.pop();
        return r;
    }
    static void deallocate(T* t) {data.push(t);}

};


//template<typename T, unsigned int SIZE>
//inline static typename T StaticAllocator<T,SIZE>::mem[SIZE];
//template<typename T, unsigned int SIZE>
//inline std::stack<T*> StaticAllocator<T,SIZE>::data;


#endif // ALLOCATORS_H
