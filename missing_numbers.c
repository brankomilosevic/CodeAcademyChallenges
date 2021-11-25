/*

*** Missing Numbers ***

You have a bag containing tiles with numbers [1, 2, 3, …, n] written on them. 
Each number appears exactly once, so there are n tiles and n numbers. 
Now, without looking, k number tiles are randomly picked out of the bag and discarded. 
Create a missingNos() function that takes in a list and k, and returns the missing numbers in ascending order (from smallest to greatest).

For example, calling missingNos() with ([1, 2, 4, 5, 6, 7, 8, 10], 2) should return [3, 9].

2021-11-18
I have trie with few border cases I have came up to. Works fine, though...
*/

#include<stdio.h>
#include<stdlib.h>

int cmpfunc (const void *a, const void *b) 
{
    return ( *(int*)a - *(int*)b );
}

void print_arr(int *arr, int n, char *m)
{
    printf("\n%s\n[ ", m);
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("]\n");
}

int* missingNos(int *arr, int n, int k)
{
    if (k == 0) return NULL;
    int *result;
    int m_pos = 0;
    
    result = malloc(k * sizeof(*result));
    if (result == NULL)
        exit(1);

    for (int i = 0; i < k; ++i)
        result[i] = 0;
    
    print_arr(arr, n, "Initial:");
    qsort(arr, n, sizeof(arr[0]), cmpfunc);
    print_arr(arr, n, "Sorted");
    
    for (int j = 1; j < arr[0]; ++j)
    {
        result[m_pos] = j;
        ++m_pos;
    }

    for (int i = 0; i < n-1; ++i)
    {
        if (arr[i+1] - arr[i] > 1)
        {
            for (int j = arr[i] + 1; j < arr[i+1]; ++j)
            {
                result[m_pos] = j;
                ++m_pos;
            }
        }
    }

    int rest = k-m_pos;
    for (int j = 1; j <= rest; ++j)
    {
        result[m_pos] = arr[n-1] + j;
        ++m_pos;
    }
    printf("\nm_pos: %d <> k: %d\n", m_pos, k);
    return result;
}

int main(void)
{
    int arr[] = { 3, 6, 5, 10, 4, 7, 8, 12};
    int *result = NULL;
    int n;
    int k;

    n = sizeof(arr) / sizeof(arr[0]);
    k = 8;

    result = missingNos(arr, n, k);
    
    print_arr(result, k, "Missing numbers: ");
    
    free(result);
    return 0;
}
