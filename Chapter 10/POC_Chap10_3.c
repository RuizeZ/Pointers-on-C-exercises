/*
ruizeZ
6/17/2020
write a declaration that will allow a program to interpret an instruction in any of these formats
*/
#include <stdio.h>
int main(void)
{
    int decode = 0xF000;
    struct Miscellaneous
    {
        unsigned opcode : 16;
    };

    struct Branch
    {
        unsigned offset : 8 ;
        unsigned opcode : 8;
    };

    struct Single_Operand
    {
        unsigned dst_reg : 3;
        unsigned dst_mode : 3;
        unsigned opcode : 10;
    };

    struct Register_Source
    {
        unsigned dst_reg : 3;
        unsigned dst_mode : 3;
        unsigned src_reg : 3;
        unsigned opcode : 7;
    };

    struct Doubla_Operand
    {
        unsigned dst_reg : 3;
        unsigned dst_mode : 3;
        unsigned src_reg : 3;
        unsigned src_mode : 3;
        unsigned opcode : 4;
    };
    
    typedef struct 
    {
        unsigned short addr : 16;
        union 
        {
            struct Miscellaneous misc;
            struct Branch branch;
            struct Single_Operand sgl_op;
            struct Register_Source reg_src;
            struct Doubla_Operand dbl_op;
        };
    }machoine_inst;
    machoine_inst x = {decode, decode};
    printf("addr: %d\n", x.addr);
    printf("misc.opcode: %d\n", x.misc.opcode);
    printf("branch.opcode: %d\n", x.branch.opcode);
    printf("branch.offset: %d\n", x.branch.offset);
    printf("sgl_op.dst_mode: %d\n", x.sgl_op.dst_mode);
    printf("reg_src.src_reg: %d\n", x.reg_src.src_reg);
    printf("dbl_op.opcode: %d\n", x.dbl_op.opcode);

}