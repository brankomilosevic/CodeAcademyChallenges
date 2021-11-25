/*
*** Flatten an Array ***

Write a flattenArray() method that takes in a 2-dimensional array, 
flattens it into a 1-dimensional array, and returns it. 
You can assume that you will only be given one or two-dimensional arrays

For example, calling flattenArray() on [[1, 2], [3, 4, 5]) should return [1, 2, 3, 4, 5].

2021-11-18
I will modify it a little bit. Insted of list of arrays of different size, I will use array of structs. Struct contains array and dimension.
*/

#include<stdio.h>
#include<stdlib.h>

struct arr_s
{
    int *val;
    int dim;
};

void print_arr(int *arr, int n, char *m)
{
    printf("\n%s\n[ ", m);
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("]\n");
}

void flattenArray(struct arr_s *arr, int n, int *flat)
{
    int index = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < arr[i].dim; ++j)
        {
            flat[index] = arr[i].val[j];
            ++index;
        }
    }
}

int main(void)
{
    int n = 2, m = 0;
    struct arr_s arr[n];
    int *flat;

    arr[0].val = malloc(2 * sizeof(int)); arr[0].dim = 2; arr[0].val[0] = 1; arr[0].val[1] = 2;
    arr[1].val = malloc(3 * sizeof(int)); arr[1].dim = 3; arr[1].val[0] = 3; arr[1].val[1] = 4; arr[1].val[2] = 5;

    for (int i = 0; i < n; ++i)
        m += arr[i].dim;

    flat = malloc(m * sizeof(int));
    
    flattenArray(arr, n, flat);

    print_arr(flat, m, "Flatten array:");

    return 0;
}