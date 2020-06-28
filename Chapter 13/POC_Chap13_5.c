/*
ruizeZ
6/28/2020
 Writing the code to process command line arguments. The first two parameters are those received by the main function, which are passed  unchanged to do_args. The third is a string that identifies what command 
 line  arguments  are  expected.  The  last  two  parameters  are  pointers  to  functions  provided by the user.  do_args processes command line arguments like this:    Skip past the program name argument  
 While the next argument begins with a dash  For each character in the argument after the dash  Process the character  Return a pointer to the next argument pointer.    
 To Ȉprocess the character,Ȉ you must first see whether the character is in the control  string. If it is not there, call the function to which illegal_arg points, passing the  character as an argument. 
 If it is there but is not followed by a plus, call the  function to which do_arg points, passing the character and a NULL pointer as  arguments.  If the character is in control and is followed by a plus, 
 then there should be a  value associated with the character. If there are any more characters in the current  argument, they are the desired value. Otherwise, the next argument is the value.  In either case, 
 you should call the function to which do_arg points, passing as  arguments the character and a pointer to the value. If there wasnȇt a value (no  additional characters and no next argument), then yon should 
 call the illegal_arg  function instead. Note: Be sure that the characters in the value are not processed as  arguments later!  When all the arguments that begin with a dash have been processed, you  should return 
 a pointer to the pointer to the next command line argument (that is, a  value such as &argv[4] or argv + 4). If all of the command line arguments began  with dashes, you will return a pointer to the NULL that 
 terminates the command  line argument list. 
*/
#include <stdio.h>
#include <string.h>
char **do_args( int argc, char **argv, char *control,  void (*do_arg)( int ch, char * value ),  void (*illegal_arg)( int ch ) );
void realdo_arg( int ch, char * value );
void realillegal_arg( int ch );
int main(int argc, char **argv)
{
    int ch = -1;
    char value[100];
    char control[100];
    void (*do_arg)(int, char*) = &realdo_arg;
    void (*illegal_arg)(int) = &realillegal_arg;
    printf("Enter control string:");
    gets(control);
    printf("return %s\n", *(do_args( argc, argv, control, do_arg, illegal_arg)));
}

char **do_args(int argc, char **argv, char *control, void (*do_arg)(int ch, char *value), void (*illegal_arg)(int ch))
{
    char charactor[1];
    char value[10];
    char *originalvalue = "\0";
    int incontrol;
    char tempcontrol[10];
    strcpy(tempcontrol, control);
    while (*++argv != NULL && **argv == '-')
    {
        while ((charactor[0] = *++*argv) != '\0')
        {
            incontrol = 0;
            while (*control != '\0')
            {
                if (*control == charactor[0])
                {
                    incontrol = 1;
                    if (*(control+1) != '+')
                    {
                        control++;
                        do_arg(charactor[0], 0);
                    }
                    else if (*(control+1) == '+')
                    {
                        control++;
                        //check if it is the end of the arguemnt
                        if (*((*argv)+1) == '\0')
                        {
                            //check is there another argument after current argument
                            if (*(argv+1) != 0)
                            {
                                do_arg(charactor[0], *(argv+1));
                                strcpy(value, originalvalue);
                                argv += 1;
                                goto quit; 
                            }
                            else
                            {
                                illegal_arg(charactor[0]);
                            } 
                        }
                        else
                        {
                            if ((*++*argv) != '\0')
                            {
                                strcpy(value, *argv);
                            }
                            do_arg(charactor[0], value);
                            while ((*++*argv) != '\0')
                            {
                                ;
                            }
                            strcpy(value, originalvalue);
                        }               
                    }
                    break;
                }
                control++;
            }
            if (incontrol == 0)
            {
                illegal_arg(charactor[0]);
                return argv;
            }
            if ((**argv) == '\0')
            {
                break;
            }
        }
        quit: ;
    }
    return argv;
}

void realdo_arg( int ch, char * value )
{
    printf("in do_arg\n");
    printf("ch = %d\n", ch);
    printf("value = %s\n", value);
}

void realillegal_arg( int ch )
{
    printf("in illegal_arg\n");
    printf("ch = %d\n",ch);
}   