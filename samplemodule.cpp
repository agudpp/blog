#include "samplemodule.h"


#include <algorithm>
#include <vector>
#include <iostream>

#include "Debug.h"
#include "stack_vector.h"



namespace SampleModule {

int
sampleCallHeap(void)
{
    // what we will do is just sort the vector and iterate that after
    // sorting them we have the correct behavior

    int result = 0;
    std::vector<int> elements;
    elements.reserve(NUM_COUNT);
    for (int i = NUM_COUNT-1; i >= 0; --i) {
        elements.push_back(i);
    }
//    std::cout << "addressHeap: " << (size_t) &(elements[0]) << std::endl;

    //std::sort(elements.begin(), elements.end());

    for (int i = 0; i < NUM_COUNT; ++i) {
        result += elements[i];
    }
    return result;
}


int
sampleCallStack(void)
{
    // what we will do is just sort the vector and iterate that after
    // sorting them we have the correct behavior
    int result = 0;
    stack_vector<int, NUM_COUNT> elements;
    for (int i = NUM_COUNT-1; i >= 0; --i) {
        elements.push_back(i);
    }

//    std::cout << "stackAddr: " << (size_t) &(elements[0]) << std::endl;
    //std::sort(elements.begin(), elements.end());

    for (int i = 0; i < NUM_COUNT; ++i) {
        result += elements[i];
    }
    return result;
}

int
sampleCallStack2(int size)
{
    // what we will do is just sort the vector and iterate that after
    // sorting them we have the correct behavior
    int result = 0;
    int elements[size];
    int count = 0;
    for (int i = size-1; i >= 0; --i) {
        elements[count++] = i;
    }

    //std::cout << "stackAddr: " << (size_t) &(elements[0]) << std::endl;
    //std::sort(&elements[0], &elements[count]);

    for (int i = 0; i < size; ++i) {
        result += elements[i];
    }
    return result;
}

}
