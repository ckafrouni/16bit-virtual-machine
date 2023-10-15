#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "../include/cpu.h"
#include "../include/memory.h"
#include "../include/instructions.h"

int main(int argc, char const *argv[])
{
    memory_t *memory = create_memory(256);
    cpu_t *cpu = create_cpu(memory);

    size_t i = 0;

    memory->buffer[i++] = MOVE_LIT_REG;
    memory->buffer[i++] = 0x12;
    memory->buffer[i++] = 0x34;
    memory->buffer[i++] = R1;

    memory->buffer[i++] = MOVE_LIT_REG;
    memory->buffer[i++] = 0xAB;
    memory->buffer[i++] = 0xCD;
    memory->buffer[i++] = R2;

    memory->buffer[i++] = ADD_REG_REG;
    memory->buffer[i++] = R1;
    memory->buffer[i++] = R2;

    debug(cpu);

    step(cpu);
    debug(cpu);

    step(cpu);
    debug(cpu);

    step(cpu);
    debug(cpu);

    return 0;
}
