#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "../include/memory.h"
#include "../include/instructions.h"
#include "../include/cpu.h"

cpu_t *create_cpu(memory_t *memory)
{
    cpu_t *cpu = (cpu_t *)malloc(sizeof(cpu_t));
    if (cpu == NULL)
    {
        exit(EXIT_FAILURE);
    }
    cpu->memory = memory;
    return cpu;
}

uint8_t fetch8(cpu_t *cpu)
{
    uint16_t addr = cpu->registers[IP];
    uint8_t instruction = cpu->memory->buffer[addr];
    cpu->registers[IP] += 1;
    return instruction;
}

uint16_t fetch16(cpu_t *cpu)
{
    uint16_t addr = cpu->registers[IP];
    uint16_t highByte = cpu->memory->buffer[addr];
    uint16_t lowByte = cpu->memory->buffer[addr + 1];
    uint16_t instruction = (highByte << 8) | lowByte;
    cpu->registers[IP] += 2;
    return instruction;
}

void set_register(cpu_t *cpu, uint16_t reg, uint16_t lit)
{
    cpu->registers[reg] = lit;
}

void execute(cpu_t *cpu, uint8_t instruction)
{
    switch (instruction)
    {

    case MOVE_LIT_REG:
        uint16_t lit = fetch16(cpu);
        uint8_t reg = fetch8(cpu);

        set_register(cpu, reg, lit);
        return;

    case ADD_REG_REG:
        // reg1 & reg2 are indexes in the registers buffer
        uint8_t reg1 = fetch8(cpu);
        uint8_t reg2 = fetch8(cpu);

        uint16_t v1 = cpu->registers[reg1];
        uint16_t v2 = cpu->registers[reg2];

        set_register(cpu, ACC, v1 + v2);
        return;

    default:
        exit(EXIT_FAILURE);
    }
}

void step(cpu_t *cpu)
{
    uint8_t instruction = fetch8(cpu);
    execute(cpu, instruction);
}

void debug(cpu_t *cpu)
{
    printf("--- REGISTERS ---\n");
    printf("IP  =  0x%04hx\n", cpu->registers[IP]);
    printf("ACC =  0x%04hx\n", cpu->registers[ACC]);
    printf("\033[33m");
    printf("R1  =  0x%04hx\n", cpu->registers[R1]);
    printf("R2  =  0x%04hx\n", cpu->registers[R2]);
    printf("R3  =  0x%04hx\n", cpu->registers[R3]);
    printf("R4  =  0x%04hx\n", cpu->registers[R4]);
    printf("R5  =  0x%04hx\n", cpu->registers[R5]);
    printf("R6  =  0x%04hx\n", cpu->registers[R6]);
    printf("R7  =  0x%04hx\n", cpu->registers[R7]);
    printf("R8  =  0x%04hx\n", cpu->registers[R8]);
    printf("\033[0m");
    printf("SP  =  0x%04hx\n", cpu->registers[SP]);
    printf("FP  =  0x%04hx\n", cpu->registers[FP]);
    printf("-----------------\n");
}