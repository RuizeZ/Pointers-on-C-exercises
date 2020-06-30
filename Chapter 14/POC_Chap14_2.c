/*
ruizeZ
6/30/2020
Write a function that returns a value indicating the type of computer on which it is running.
*/
#include <stdio.h>
#include "cpu_types.h"

int cpu_types()
{
    #if defined(VAX)
        return CPU_VAX;

    #elif defined(M68000)
        return CPU_68000;

    #elif defined(K68020)
        return CPU_68020;

    #elif defined(I80386)
        return CPU_80386;

    #elif defined(X6809)
        return CPU_6809;

    #elif defined(X6502)
        return CPU_6502;

    #elif defined(U3B2)
        return CPU_3B2;

    #else
        return CPU_UNKNOWN;
    #endif
}

int main(void)
{
    printf("%d\n", cpu_types());
}