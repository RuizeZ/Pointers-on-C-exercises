/*
ruizeZ
6/19/2020
write a function that reads a string and returns a copy of the string in dynamically allocated memory.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *readstr();
int main(void)
{
    char *returnstr;
    returnstr = readstr();
    printf("%s\n",returnstr);
    free(returnstr);
}
char *readstr()
{
    char inputstr[100];
    char *copystr;
    printf("Enter the string:");
    gets(inputstr);
    copystr = malloc(strlen(inputstr)+1);
    if (copystr != NULL)
    {
        strcpy(copystr, inputstr);
    }
    return copystr;
    
}