#include <iostream>
#include <cassert>
#include <vector>

#include "Debug.h"
#include "TimeHelper.h"
#include "samplemodule.h"
#include "Defines.h"

static std::vector<int*> gmem;


// normal test without memory allocation problems
static void
normalTest(void)
{
    double t1 = 0., t2 = 0.f;
    int dummy1 = 0, dummy2 = 0, dummy3 = 0;

    // measure the heap
    t1 = TimeHelper::currentTime();
    for (int i = 0; i < TEST_COUNT; ++i) {
        dummy1 += SampleModule::sampleCallHeap();
    }
    t2 = TimeHelper::currentTime();
    const double timeHeap = t2 - t1;

    // measure the stack
    t1 = TimeHelper::currentTime();
    for (int i = 0; i < TEST_COUNT; ++i) {
        dummy2 += SampleModule::sampleCallStack();
    }
    t2 = TimeHelper::currentTime();
    const double timeStack = t2 - t1;

    // measure the stack2
    t1 = TimeHelper::currentTime();
    for (int i = 0; i < TEST_COUNT; ++i) {
        dummy3 += SampleModule::sampleCallStack2(NUM_COUNT);
    }
    t2 = TimeHelper::currentTime();
    const double timeStack2 = t2 - t1;

    assert(dummy1 == dummy2);
    assert(dummy2 == dummy3);

    std::cout << "Test: normalTest" << std::endl
              << "Number of runs: " << TEST_COUNT
              << "\t\tSize: " << NUM_COUNT << std::endl << std::endl;
    std::cout << "Time takes heap: " << timeHeap  << std::endl
              << "Time takes stack: " << timeStack << std::endl
              << "Time takes stack2: " << timeStack2 << std::endl
              << "dummy1: " << dummy1 << ", dummy2: " << dummy2 << ", dummy3:"
              << dummy3 << std::endl;
}


// allocating memory all the time to no use the same heap mem addr
static void
randomMemAllocation(void)
{
    int* array = new int[NUM_COUNT];
    gmem.push_back(array);

}

static void
memAllocTest(void)
{
    double t1 = 0., t2 = 0.f;
    double accumTime = 0.f;
    int dummy1 = 0, dummy2 = 0;

    // measure the heap
    for (int i = 0; i < TEST_COUNT; ++i) {
        randomMemAllocation();
        t1 = TimeHelper::currentTime();
        dummy1 += SampleModule::sampleCallHeap();
        t2 = TimeHelper::currentTime();
        accumTime += t2-t1;

        if (gmem.size() > 5000) {
            for (int* array : gmem) delete[] array;
            gmem.clear();
        }
    }
    const double timeHeap = accumTime;

    // measure the stack
    accumTime = 0.f;
    for (int i = 0; i < TEST_COUNT; ++i) {
        randomMemAllocation();
        t1 = TimeHelper::currentTime();
        dummy2 += SampleModule::sampleCallStack();
        t2 = TimeHelper::currentTime();
        accumTime += t2-t1;

        if (gmem.size() > 5000) {
            for (int* array : gmem) delete[] array;
            gmem.clear();
        }
    }
    const double timeStack = accumTime;

    assert(dummy1 == dummy2);

    std::cout << "Test: memAllocTest" << std::endl
              << "Number of runs: " << TEST_COUNT
              << "\t\tSize: " << NUM_COUNT << std::endl << std::endl;
    std::cout << "Time takes heap: " << timeHeap  << std::endl
              << "Time takes stack: " << timeStack << std::endl
              << "dummy1: " << dummy1 << ", dummy2: " << dummy2 << std::endl;
}

int main()
{
    //normalTest();
    memAllocTest();

    for (int* array : gmem) delete[] array;

    return 0;
}

