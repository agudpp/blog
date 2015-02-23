#ifndef SAMPLEMODULE_H
#define SAMPLEMODULE_H

#include "Defines.h"


namespace SampleModule {

    // heap versoin
    int
    sampleCallHeap(void);

    // stack version
    int
    sampleCallStack(void);

    // stack 2 c99 feature
    int
    sampleCallStack2(int size);
}

#endif // SAMPLEMODULE_H
