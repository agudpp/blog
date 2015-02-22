#include "samplemodule.h"


#include <algorithm>
#include <vector>
#include <iostream>

#include "Debug.h"
#include "stack_vector.h"
#include "stack_vector2.h"



namespace SampleModule {

int
sampleCallHeap(void)
{
    int result = 0;
    std::vector<int> elements;
    elements.reserve(NUM_COUNT);

    for (int i = NUM_COUNT-1; i >= 0; --i) {
        elements.push_back(i);
    }

    for (int i = 0; i < NUM_COUNT; ++i) {
        result += elements[i];
    }
    return result;
}

int
sampleCallStack(void)
{
    int result = 0;
    stack_vector<int, NUM_COUNT> elements;
    for (int i = NUM_COUNT-1; i >= 0; --i) {
        elements.push_back(i);
    }

    for (int i = 0; i < NUM_COUNT; ++i) {
        result += elements[i];
    }
    return result;
}

int
sampleCallStack2(int size)
{
    int result = 0;
    int mem[size];
    stack_vector2<int> elements(mem);
    for (int i = size-1; i >= 0; --i) {
        elements.push_back(i);
    }

    for (int i = 0; i < size; ++i) {
        result += elements[i];
    }
    return result;
}

}
