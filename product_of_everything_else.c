/*
*** Product of Everything Else ***

Create a productOfTheOthers() method that takes in an array of integers and replaces 
each number in the array with the product of all the numbers in the array except the number at the index itself.

For example, 
calling productOfTheOthers() on [1, 2, 3, 4, 5] should return [120, 60, 40, 30, 24]
calling it on [5, 5, 5] should return [25, 25, 25].

2021-11-19
Not calculating product for each position, using product of all array members as helper.
*/

#include<stdio.h>

void print_arr(int *arr, int n, char *m)
{
    printf("\n%s\n[ ", m);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("]\n");
}

void productOfTheOthers(int *arr, int n)
{
    int product = 1;

    for (int i = 0; i < n; ++i)
        product *= arr[i];

    for (int i = 0; i < n; ++i)
        arr[i] = product / arr[i];
}

int main(void)
{
    // int arr[] = {5, 5, 5};
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    print_arr(arr, n, "Before transformation:");
    productOfTheOthers(arr, n);
    print_arr(arr, n, "After transformation:");

}