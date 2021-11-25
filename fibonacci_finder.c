/*
*** Fibonacci Finder ***

Create a fibFinder() method that finds the nth number in the Fibonacci sequence. 
As a reminder, the Fibonacci sequence is a mathematical sequence that begins with 0 and 1, 
with each following term being the sum of the two previous terms.

For example, the first two terms of the sequence are represented by fibFinder(0) and fibFinder(1), which return 0 and 1, respectively. 
fibFinder(6) should return 8.

Example:
0  1  2  3  4  5  6  7  8  9
0  1  1  2  3  5  8 13 21 34

2021-11-18
I have used itterative Fibonacci finder method
*/

#include<stdio.h>

int fibFinder(int n)
{
    if (n < 2) return n;
    
    int res = n;
    int min_1 = 1, min_2 = 0;

    for (int i = 2; i <= n; ++i)
    {
        res = min_1 + min_2;
        min_2 = min_1;
        min_1 = res;
    }

    return res;
}

int main(void)
{
    int k = 6;
    int arr[k];

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 6;
    arr[3] = 9;
    // rest of arr is garbage...

    for (int i = 0; i < k; ++i)
        printf("Fib( %d ): %d\n", arr[i], fibFinder(arr[i]));
    return 0;
}