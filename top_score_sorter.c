/*
*** Top Score Sorter ***

Write a scoreSorter() method that will take a list of unsorted scores along with the highest possible score. 
It should return a sorted list of all of the scores, in descending order from high to low. 
You are expected to create and implement your own sorting algorithm for this challenge.

For example, calling scoreSorter() on ([1, 2, 3, 9999, 13], 10000) should return [9999, 13, 3, 2, 1].
*/

#include<stdio.h>

void print_arr(int *arr, int n, char *m)
{
    printf("\n%s\n[ ", m);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("]\n");
}

void merge(int *arr, int low, int mid, int high)
{
    int L_dim = mid - low + 1;
    int R_dim = high - mid; 
    int L[L_dim];   // first subarray is [low ... mid]
    int R[R_dim];   // econd subarray is [mid+1 ... high]

    for (int i=0; i<L_dim; ++i) L[i] = arr[low+i];
    for (int i=0; i<R_dim; ++i) R[i] = arr[mid+i+1];

    int i=0, j=0, k=low;

    while (i < L_dim && j < R_dim)
    {
        if (L[i] >= R[j])   // change to <= for ascending order
        {
            arr[k] = L[i];
            ++i;
        }
        else
        {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < L_dim)
    {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < R_dim)
    {
        arr[k] = R[j];
        ++j;
        ++k;
    }

}

void mergeSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);  
        merge(arr, low, mid, high);
    }
}

void scoreSorter(int *arr, int n, int Max)
{
// I do know why would I need Max. Anyway...
    if (Max == 0) return;
    mergeSort(arr, 0, n-1);
}

int main(void)
{
    int arr[] = {1, 2, 3, 9999, 13};

    scoreSorter(arr, sizeof(arr)/sizeof(arr[0]), 1000);
    print_arr(arr, sizeof(arr)/sizeof(arr[0]), "After sorting:");

    return 0;
}