#include <stdlib.h>
#include <stdint.h>

#include "../include/memory.h"

memory_t *create_memory(size_t size)
{
    memory_t *memory = (memory_t *)malloc(sizeof(memory_t));
    if (memory == NULL)
    {
        exit(EXIT_FAILURE);
    }
    memory->size = size;
    memory->buffer = (uint8_t *)malloc(size);
    if (memory->buffer == NULL)
    {
        exit(EXIT_FAILURE);
    }
    return memory;
}
