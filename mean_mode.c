/*
*** Mean and Mode ***

Create a statsFinder() method that takes in a list of numbers and returns a list 
containing the mean and mode, in that order. 
As a reminder, the mean is the average of the values and the mode is the most occurring value. 
If there are multiple modes, return the mode that occurs first. 
Make sure that you write your functions and find these answers from scratch – don’t use imported tools!

For example, calling statsFinder() on the array [500, 400, 400, 375, 300, 350, 325, 300] should return [368.75, 400].

2021-11-19
Someday, I will build simple hash map in C based and this will go much faster.
*/

#include<stdio.h>
#include<stdlib.h>

struct mean_mode
{
    double mean;
    int mode;
};

void print_arr(int *arr, int n, char *m)
{
    printf("\n%s\n[ ", m);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("]\n");
}
int cmp(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}
struct mean_mode statsFinder(int *arr, int n)
{
    struct mean_mode res;
    res.mean = 0.0;

    for (int i = 0; i < n; ++i)
        res.mean += arr[i];
    res.mean /= n;

    // print_arr(arr, n, "Before sorting: ");
    // qsort(arr, n, sizeof(arr[0]), cmp);
    // print_arr(arr, n, "After sorting: ");
    
    // int mode_index = 0, mode_tmp = 1, mode_max = 1;

    // for (int i=1; i<n; ++i)
    // {
    //     if (arr[i] == arr[i-1])
    //     {
    //         ++mode_tmp;
    //         if (mode_tmp > mode_max)
    //         {
    //             mode_max = mode_tmp;
    //             mode_index = i;
    //         }
    //     }
    //     else
    //     {
    //         mode_tmp = 0;
    //     }
    // }

    int tmp[n];
    for (int i = 0; i < n; ++i) 
        tmp[i] = 0;

    for (int i = 0; i < n; ++i)
    {
        int val = arr[i];
        tmp[i] = 1;
        for (int j = i+1; j < n; ++j)
        {
            if (arr[j] == val)
            {
                ++tmp[i];
            }
        }
    }

    print_arr(arr, n, "Initial:");
    print_arr(tmp, n, "Frequencies:");

    int max = tmp[0], max_index = 0;

    for (int i = 1; i < n; ++i)
        if (tmp[i] > max)
        {
            max = tmp[i];
            max_index = i;
        }

    res.mode = arr[max_index];
    return res;
}

int main(void)
{
    int arr[] = {500, 400, 400, 375, 300, 350, 325, 300};

    struct mean_mode res;

    res = statsFinder(arr, sizeof(arr)/sizeof(arr[0]));

    printf("Mean: %.4lf\nMode: %d\n", res.mean, res.mode);

    return 0;
}