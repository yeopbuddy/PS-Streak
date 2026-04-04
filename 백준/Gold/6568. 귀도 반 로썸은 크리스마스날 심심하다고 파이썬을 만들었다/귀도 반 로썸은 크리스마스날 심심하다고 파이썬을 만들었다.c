#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MEM_SIZE        (32U)
#define BITS_IN_BYTE    (8U)
#define PC_MASK         (0x1FU)
#define OPERAND_MASK    (0x1FU)
#define OPCODE_SHIFT    (5U)

#define OP_STA  (0x00U)
#define OP_LDA  (0x01U)
#define OP_BEQ  (0x02U)
#define OP_NOP  (0x03U)
#define OP_DEC  (0x04U)
#define OP_INC  (0x05U)
#define OP_JMP  (0x06U)
#define OP_HLT  (0x07U)

static int32_t readBinaryByte(uint8_t* pu8Out)
{
    char acLine[16];
    uint8_t u8Val;
    int32_t i;

    if (fgets(acLine, (int32_t)sizeof(acLine), stdin) == NULL)
    {
        return -1;
    }

    u8Val = 0U;
    for (i = 0; i < (int32_t)BITS_IN_BYTE; i++)
    {
        if (acLine[i] == '1')
        {
            u8Val = (uint8_t)((u8Val << 1U) | 1U);
        }
        else if (acLine[i] == '0')
        {
            u8Val = (uint8_t)(u8Val << 1U);
        }
        else
        {
            return -1;
        }
    }

    *pu8Out = u8Val;
    return 0;
}

static void printBinaryByte(uint8_t u8Val)
{
    int32_t i;
    for (i = (int32_t)(BITS_IN_BYTE - 1U); i >= 0; i--)
    {
        (void)printf("%c", ((u8Val >> (uint8_t)i) & 1U) ? '1' : '0');
    }
    (void)printf("\n");
}

static uint8_t runCpu(const uint8_t au8Mem[MEM_SIZE])
{
    uint8_t au8Ram[MEM_SIZE];
    uint8_t u8Acc;
    uint8_t u8Pc;
    uint8_t u8Instr;
    uint8_t u8Opcode;
    uint8_t u8Operand;
    int32_t bHalt;

    (void)memcpy(au8Ram, au8Mem, MEM_SIZE);

    u8Acc = 0U;
    u8Pc = 0U;
    bHalt = 0;

    while (bHalt == 0)
    {
        u8Instr = au8Ram[u8Pc & PC_MASK];

        u8Opcode = (uint8_t)(u8Instr >> OPCODE_SHIFT);
        u8Operand = (uint8_t)(u8Instr & OPERAND_MASK);

        u8Pc = (uint8_t)((u8Pc + 1U) & PC_MASK);

        switch (u8Opcode)
        {
        case OP_STA:
            au8Ram[u8Operand] = u8Acc;
            break;

        case OP_LDA:
            u8Acc = au8Ram[u8Operand];
            break;

        case OP_BEQ:
            if (u8Acc == 0U)
            {
                u8Pc = u8Operand;
            }
            break;

        case OP_NOP:
            break;

        case OP_DEC:
            u8Acc = (uint8_t)(u8Acc - 1U);
            break;

        case OP_INC:
            u8Acc = (uint8_t)(u8Acc + 1U);
            break;

        case OP_JMP:
            u8Pc = u8Operand;
            break;

        case OP_HLT:
            bHalt = 1;
            break;

        default:
            bHalt = 1;
            break;
        }
    }

    return u8Acc;
}

int32_t main(void)
{
    uint8_t au8Mem[MEM_SIZE];
    uint8_t u8Acc;
    int32_t i;
    int32_t i32Ret;

    for (;;)
    {
        i32Ret = 0;
        for (i = 0; i < (int32_t)MEM_SIZE; i++)
        {
            if (readBinaryByte(&au8Mem[i]) != 0)
            {
                i32Ret = -1;
                break;
            }
        }

        if (i32Ret != 0)
        {
            break;
        }

        u8Acc = runCpu(au8Mem);
        printBinaryByte(u8Acc);
    }

    return 0;
}