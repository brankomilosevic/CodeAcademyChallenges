/*
*** Max Product Finder ***

Create a maxProductFinderK() method that takes in a list of numbers and an integer k, 
and returns the largest product that can be attained from any k integers in the list. 

You may presume that the length of the list of integers is greater than or equal to k.

For example, 
calling maxProductFinderK() on ([-8, 6, -7, 3, 2, 1, -9], 2) should return 72
calling maxProductFinderK() on ([-8, 6, -7, 3, 2, 1, -9], 3) should return 432.

2021-11-18:
Finished in couple of hours :)
I do not have test samples to try out, ecxcept few on my own.
Most probably, It could be optimized by calculating the resuls by using sorted array, without building separte arrays for positive and negative
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
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("]\n");
}

int maxProductFinderK(int *arr, int n, int k)
{
    int result = 1;
    int pos[n];
    int neg[n];
    int num_neg = 0;
    int num_pos = 0;
    int zero = 0;

    if (n == 0) return 0;
    if (n == 1) return arr[0];
    
    if (k == n)
    {
        for (int i = 0; i < n; i++)
            result *= arr[i];
        return result;
    }

    print_arr(arr, n, "Initial:");
    qsort(arr, n, sizeof(arr[0]), cmpfunc);
    print_arr(arr, n, "Sorted");
   
    for (int i = 0; i < n; ++i)
    {
        if (arr[n-i-1] > 0)
        {
            pos[num_pos] = arr[n-i-1];
            ++num_pos;
        }
    
        if (arr[i] < 0)
        {
            neg[num_neg] = arr[num_neg];
            ++num_neg;
        }
        if (arr[i] == 0)
            zero = 1;
    }

    print_arr(pos, num_pos, "Positive:");
    print_arr(neg, num_neg, "Negative:");

    // only 1 negative, it should not be considered
    if (num_neg < 2)
    {
        for (int i = 0; i < k; i++)
            result *= pos[i];
        return result;
    }

    // only negative
    if (num_pos == 0)
    {
        // odd number of negatives, shoudl consider only smallest (absolute values)
        if (k % 2)
        {
            if (zero)
                return 0;

            for (int i = 0; i < k; i++)
                result *= neg[n-k+i];
            return result;
        }
        // even number, should build up by using biggest values (absolute)
        else
        {
            for (int i = 0; i < k; i++)
                result *= neg[i];
            return result;
        }
    }

    // mix positive and negativie, should consider max of pair of negative and positive
    int pos_p = 0, neg_p = 0;
    for (int j = 0; j < k; ++j)
    {
        if (pos[pos_p] * pos[pos_p+1] > neg[neg_p] * neg[neg_p+1])
        {
            result *= pos[pos_p] * pos[pos_p+1];
            pos_p += 2;
        } 
        else
        {
            result *= neg[neg_p] * neg[neg_p+1];
            neg_p += 2;
        }
        if (neg_p + pos_p >= k - 1) break;
    }

    if (k % 2)
        result *= pos[pos_p];

    return result;
}


int main(void)
{
    // int arr[] = {-8, 6, -7, 3, 0, 2, 1, -9};
    // int arr[] = {-8, -6, -7, -3, -2, -1, -9};
    // int arr[] = {8, 6, 7, 3, 0, 2, 1, 9};
    int arr[] = {-8, 6, -7, 3, 2, 1, -9};
    
    int max_prod, k;
    int n;
    
    n = sizeof(arr) / sizeof(arr[0]);
    k = 2;
    max_prod = maxProductFinderK(arr, n, k);

    printf("Max product of %d numbers in the array of %d numbers is: %d\n", k, n, max_prod);
}