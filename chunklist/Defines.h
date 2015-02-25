#ifndef DEFINES_H
#define DEFINES_H


// the number of tests we will do
#ifndef ROUNDS
#define ROUNDS              999999
#endif

// the number of elements per list
#ifndef ELEMENTS_PER_LIST
#define ELEMENTS_PER_LIST   100
#endif

// the size of the chunk
#ifndef CHUNK_SIZE
#define CHUNK_SIZE   4
#endif


// the number of lists we will handle, only one should be enough
// but the idea is to fragmentate the memory so maybe we want
// to have more than one
#ifndef LIST_COUNT
#define LIST_COUNT          1
#endif


#endif // DEFINES_H
