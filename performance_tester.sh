#!/bin/bash

compile()
{
    # compile the programs with the arguments
    echo "compiling test with args $1"
    if `g++ -o ./build/stack_vector samplemodule.cpp main.cpp -std=c++11 -Wall $1`; then
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
    ./build/stack_vector
    echo "done!"
    echo "----------------------------------------------------------------------"
    echo ""
}


# tests
compile "-DTEST_COUNT=99999 -DNUM_COUNT=50"
runTest "No Optimization - Size = 50"

compile "-DTEST_COUNT=99999 -DNUM_COUNT=100"
runTest "No Optimization - Size = 100"

compile "-DTEST_COUNT=99999 -DNUM_COUNT=200"
runTest "No Optimization - Size = 200"

compile "-DTEST_COUNT=99999 -DNUM_COUNT=500"
runTest "No Optimization - Size = 500"

compile "-DTEST_COUNT=99999 -DNUM_COUNT=1000"
runTest "No Optimization - Size = 1000"

compile "-DTEST_COUNT=99999 -DNUM_COUNT=5000"
runTest "No Optimization - Size = 5000"


# optimization O2

compile "-DTEST_COUNT=99999 -DNUM_COUNT=50 -O2"
runTest "Optimization O2 - Size = 50"

compile "-DTEST_COUNT=99999 -DNUM_COUNT=100 -O2"
runTest "Optimization O2 - Size = 100"

compile "-DTEST_COUNT=99999 -DNUM_COUNT=500 -O2"
runTest "Optimization O2 - Size = 500"

compile "-DTEST_COUNT=99999 -DNUM_COUNT=1000 -O2"
runTest "Optimization O2 - Size = 1000"

compile "-DTEST_COUNT=99999 -DNUM_COUNT=5000 -O2"
runTest "Optimization O2 - Size = 5000"


# optimization O3

compile "-DTEST_COUNT=99999 -DNUM_COUNT=50 -O3"
runTest "Optimization O3 - Size = 50"

compile "-DTEST_COUNT=99999 -DNUM_COUNT=100 -O3"
runTest "Optimization O3 - Size = 100"

compile "-DTEST_COUNT=99999 -DNUM_COUNT=500 -O3"
runTest "Optimization O3 - Size = 500"

compile "-DTEST_COUNT=99999 -DNUM_COUNT=1000 -O3"
runTest "Optimization O3 - Size = 1000"

compile "-DTEST_COUNT=99999 -DNUM_COUNT=5000 -O3"
runTest "Optimization O3 - Size = 5000"



