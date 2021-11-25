/*
*** Prime Number Finder ***

Create a primeFinder() method that takes in a number, n, and returns all the prime numbers from 1 to n (inclusive). As a reminder, a prime number is a number that is only divisible by 1 and itself.

For example, primeFinder(13) should return [2, 3, 5, 7, 11, 13].

2021-11-18
Started with brute force, then moved to sqrt(n) based solution
*/

#include<stdio.h>

/** brute force
int is_prime(int n)
{
    if (n < 3) return 1;
    for (int i=2; i<n; ++i)
        if (n%i == 0) return 0;

    return 1;
}
*/

int is_prime(int n) 
{
    if (n == 1) return 0;

    int i = 2;

    // This will loop from 2 to sqrt(n)
    while (i*i <= n) 
    {
        // If <i> divides <n>, then <n> has a factor between 2 and sqrt(n)
        if (n % i == 0) return 0;
        ++i;
    }
    
    return 1;
}

void primeFinder(int *arr, int n, int *count)
{
    int index = 0;

    for (int num=2; num<=n; ++num)
    {
        if (is_prime(num))
        {
            arr[index] = num;
            ++index;
        }
    }
    *count = index;
}

void print_arr(int *arr, int n, char *m)
{
    printf("\n%s\n[ ", m);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("]\n");
}

int main(void)
{
    int n = 13;
    int arr[n];
    int count = 0;

    primeFinder(arr, n, &count);

    print_arr(arr, count, "Prime numbers: ");
    return 0;
}