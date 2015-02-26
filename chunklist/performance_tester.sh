#!/bin/bash

compile()
{
    # compile the programs with the arguments
    #echo "compiling test with args $1"
    if `g++ -o ./build/chunklist main.cpp -std=c++11 -Wall $1`; then
        echo "compiled"
    else
        echo "Failed when compiling"
        exit
    fi
}


runTest()
{
    echo "----------------------------------------------------------------------"
    echo "Running test $1"
    ./build/chunklist
    echo ""
}

################################################################################
# New Allocator:

#
# No optimization
# tests
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=4 -DCHUNK_SIZE=1 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=8 -DCHUNK_SIZE=1 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=16 -DCHUNK_SIZE=1 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=32 -DCHUNK_SIZE=1 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=64 -DCHUNK_SIZE=1 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"

compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=4 -DCHUNK_SIZE=4 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=8 -DCHUNK_SIZE=4 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=16 -DCHUNK_SIZE=4 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=32 -DCHUNK_SIZE=4 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=64 -DCHUNK_SIZE=4 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"

compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=4 -DCHUNK_SIZE=16 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=8 -DCHUNK_SIZE=16 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=16 -DCHUNK_SIZE=16 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=32 -DCHUNK_SIZE=16 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=64 -DCHUNK_SIZE=16 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"

#
# O3 no vectorize
# tests
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=4 -DCHUNK_SIZE=1 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=8 -DCHUNK_SIZE=1 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=16 -DCHUNK_SIZE=1 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=32 -DCHUNK_SIZE=1 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=64 -DCHUNK_SIZE=1 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"

compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=4 -DCHUNK_SIZE=4 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=8 -DCHUNK_SIZE=4 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=16 -DCHUNK_SIZE=4 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=32 -DCHUNK_SIZE=4 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=64 -DCHUNK_SIZE=4 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"

compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=4 -DCHUNK_SIZE=16 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=8 -DCHUNK_SIZE=16 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=16 -DCHUNK_SIZE=16 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=32 -DCHUNK_SIZE=16 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=64 -DCHUNK_SIZE=16 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"

#
# O3 vectorize
# tests
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=4 -DCHUNK_SIZE=1 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=8 -DCHUNK_SIZE=1 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=16 -DCHUNK_SIZE=1 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=32 -DCHUNK_SIZE=1 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=64 -DCHUNK_SIZE=1 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"

compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=4 -DCHUNK_SIZE=4 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=8 -DCHUNK_SIZE=4 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=16 -DCHUNK_SIZE=4 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=32 -DCHUNK_SIZE=4 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=64 -DCHUNK_SIZE=4 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"

compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=4 -DCHUNK_SIZE=16 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=8 -DCHUNK_SIZE=16 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=16 -DCHUNK_SIZE=16 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=32 -DCHUNK_SIZE=16 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=64 -DCHUNK_SIZE=16 -DUSE_HEAP_ALLOC -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"



################################################################################
# Static allocated:


# No optimization
# tests
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=4 -DCHUNK_SIZE=1 -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=8 -DCHUNK_SIZE=1 -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=16 -DCHUNK_SIZE=1 -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=32 -DCHUNK_SIZE=1 -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=64 -DCHUNK_SIZE=1 -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"

compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=4 -DCHUNK_SIZE=4 -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=8 -DCHUNK_SIZE=4 -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=16 -DCHUNK_SIZE=4 -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=32 -DCHUNK_SIZE=4 -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=64 -DCHUNK_SIZE=4 -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"

compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=4 -DCHUNK_SIZE=16 -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=8 -DCHUNK_SIZE=16 -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=16 -DCHUNK_SIZE=16 -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=32 -DCHUNK_SIZE=16 -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=64 -DCHUNK_SIZE=16 -fwrapv -std=c++11 "
runTest "New Allocator - no optimization"

#
# O3 no vectorize
# tests
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=4 -DCHUNK_SIZE=1 -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=8 -DCHUNK_SIZE=1 -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=16 -DCHUNK_SIZE=1 -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=32 -DCHUNK_SIZE=1 -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=64 -DCHUNK_SIZE=1 -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"

compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=4 -DCHUNK_SIZE=4 -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=8 -DCHUNK_SIZE=4 -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=16 -DCHUNK_SIZE=4 -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=32 -DCHUNK_SIZE=4 -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=64 -DCHUNK_SIZE=4 -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"

compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=4 -DCHUNK_SIZE=16 -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=8 -DCHUNK_SIZE=16 -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=16 -DCHUNK_SIZE=16 -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=32 -DCHUNK_SIZE=16 -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=64 -DCHUNK_SIZE=16 -fwrapv -std=c++11 -O3 "
runTest "New Allocator - O3 no vectorize"

#
# O3 vectorize
# tests
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=4 -DCHUNK_SIZE=1 -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=8 -DCHUNK_SIZE=1 -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=16 -DCHUNK_SIZE=1 -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=32 -DCHUNK_SIZE=1 -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=64 -DCHUNK_SIZE=1 -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"

compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=4 -DCHUNK_SIZE=4 -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=8 -DCHUNK_SIZE=4 -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=16 -DCHUNK_SIZE=4 -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=32 -DCHUNK_SIZE=4 -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=64 -DCHUNK_SIZE=4 -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"

compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=4 -DCHUNK_SIZE=16 -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=8 -DCHUNK_SIZE=16 -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=16 -DCHUNK_SIZE=16 -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=32 -DCHUNK_SIZE=16 -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"
compile "-DROUNDS=9999999 -DELEMENTS_PER_LIST=64 -DCHUNK_SIZE=16 -fwrapv -std=c++11 -O3 -ftree-vectorize"
runTest "New Allocator - O3 vectorize"
