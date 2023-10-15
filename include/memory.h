#if !defined(MEMORY)
#define MEMORY

#include <stdlib.h>
#include <stdint.h>

typedef struct memory_t
{
    size_t size;
    uint8_t *buffer;
} memory_t;


memory_t *create_memory(size_t size);

#endif // MEMORY
