#if !defined(CPU)
#define CPU

#include <stdlib.h>
#include <stdint.h>

#include "../include/memory.h"

#define N_REG 12
#define SIZE_REG 2 // we are using a 16bit system

#define IP 0
#define ACC 1
#define R1 2
#define R2 3
#define R3 4
#define R4 5
#define R5 6
#define R6 7
#define R7 8
#define R8 9
#define SP 10
#define FP 11

typedef struct cpu_t
{
    memory_t *memory;
    uint16_t registers[N_REG];
} cpu_t;

cpu_t *create_cpu(memory_t *memory);

uint8_t fetch8(cpu_t *cpu);

uint16_t fetch16(cpu_t *cpu);

void set_register(cpu_t *cpu, uint16_t reg, uint16_t lit);

void execute(cpu_t *cpu, uint8_t instruction);

void step(cpu_t *cpu);

void debug(cpu_t *cpu);

#endif // CPU
