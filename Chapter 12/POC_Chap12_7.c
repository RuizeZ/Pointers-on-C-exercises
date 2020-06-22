/*
ruizeZ
6/22/2020
Write  a  function  to  insert  a  new  word  into  the  concordance  list  described  in the picture. 
The function should take a pointer to the list pointer and a string as  its arguments. 
The string is assumed to contain a single word. If the word does not  already exist in the list, 
it should be copied into dynamically allocated memory and  then inserted. 
The function should return true if the string was inserted; and false if the string already existed in the list, 
did not begin with a letter, or if anything else  went wrong. The function should maintain the primary list in order by the letter of the node 
and the secondary lists in order by the words. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct letterNODE
    {
        struct letterNODE *linkhorizontal;
        struct wordNODE *linkvertical;
        char Nodeletter[1];
    }letterNode;
typedef struct wordNODE
{
    char word[100];
    struct wordNODE *link;
}wordNode;

int insertion(letterNode **root, char *insertstr);

int main(void)
{
    char *letter = "abcdefghijklmnopqrstuvwxyz";
    char insertstr[100];
    letterNode *letterroot;
    letterNode **letterrootp = &letterroot;
    letterNode *current;
    letterNode *new;
    int check = 1;
    for (int i = 0; i < strlen(letter); i++)
    {
        new = (letterNode *)malloc(sizeof(letterNode));
        new->Nodeletter[0] = letter[i];
        *letterrootp = new;
        current = *letterrootp;
        letterrootp = &current->linkhorizontal;
    }
    //letterrootp points to the address of letterroot
    while (check)
    {
        letterrootp = &letterroot;
        printf("Enter the word:");
        gets(insertstr);
        check = insertion(letterrootp, insertstr);
    }

}
int insertion(letterNode **root, char *insertstr)
{
    register letterNode *current;
    register wordNode *new;
    //wordNodeRootp points to wordNodeRoot's address
    wordNode **wordNodeRootp;
    register wordNode *wordNodeCurrent;

    while ((current = *root) != NULL)
    {
        if (current->Nodeletter[0] == insertstr[0])
        {
            printf("%s\n",current->Nodeletter);
            //wordNodeRoot = current->linkvertical
            wordNodeRootp = &(current->linkvertical);

            while ((wordNodeCurrent = *wordNodeRootp) != NULL && (strcmp(wordNodeCurrent->word, insertstr)) < 0)
            {

                printf("%s\n",wordNodeCurrent->word);
                wordNodeRootp = &wordNodeCurrent->link;
            }
            if ((wordNodeCurrent = *wordNodeRootp) != NULL && strcmp(wordNodeCurrent->word, insertstr) == 0)
            {
                return 0;
            }
            new = (wordNode *)malloc(sizeof(wordNode));
            strcpy(new->word, insertstr);
            new->link = wordNodeCurrent;
            *wordNodeRootp = new;
            
            printf("%s\n",(*wordNodeRootp)->word);
            return 1;
        }
        root = &current->linkhorizontal;
    }
    
}