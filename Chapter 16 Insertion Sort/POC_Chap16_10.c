/*
ruizeZ
2020/7/14
implementation of a insertion sort
*/
#include <stdio.h>
#define LENGTH 16
void insertion_sort(void *base, size_t n_elements, size_t el_size,  int (*compare)( int *, int * ));
int compare(int * a, int * b);
int main(void)
{
    int array[LENGTH] = {2,3,7,4,5,1,3,2,8,4,2,6,4,7,1,4};
    insertion_sort(array, LENGTH, sizeof(int), compare);

    for (int i = 0; i < LENGTH; i++)
    {
        printf("%d\n", array[i]);
    }
    
}

void insertion_sort(void *base, size_t n_elements, size_t el_size,  int (*compare)( int *, int * ))
{
    for (int i = 1; i < n_elements; i++)
    {
        while (compare(base + (i - 1) * el_size, base + i * el_size))
        {
            
            i--;
            if (i == 0)
            {
                break;
            }

        }
    }
}

int compare(int *a, int *b)
{
    int temp;

    if (*a > *b)
    {
        temp = *a;
        *a = *b;
        *b = temp;
        return 1;
    }
    else
    {
        return 0;
    }
}