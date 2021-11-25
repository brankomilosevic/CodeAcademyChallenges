/*
*** FizzBuzz ***

Write a fizzbuzz() method that takes in a number, n, and returns an ArrayList of the numbers from 1 to n. 
For multiples of three, use "Fizz" instead of the number, and for the multiples of five, use "Buzz". 
For numbers that are multiples of both three and five, use "FizzBuzz" (capitalization matters).

For example, fizzbuzz(16) should return [1, 2, "Fizz", 4, "Buzz", "Fizz", 7, 8, "Fizz", "Buzz", 11, "Fizz", 13, 14, "FizzBuzz", 16].

2021-11-18
I will modify it as this one
fizzbuzz(16) should return [1, 2, 'F', 4, 'B', 'F', 7, 8, 'F', 'B', 11, 'F, 13, 14, 'O', 16]
Therefore, it is limited to values bellow 'A'=65 in term of printing.
Othervise, it should be working fine.
*/
#include<stdio.h>

void print_arr(int *arr, int n, char *m)
{
    printf("\n%s\n[ ", m);
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] >= 'A' && arr[i] <= 'Z') 
            printf("%c ", arr[i]);
        else
            printf("%d ", arr[i]);

    }
    printf("]\n");
}

void fizzbuzz(int *arr, int n)
{
    int val, rem_3, rem_5;

    for (int i = 0; i < n; ++i)
    {
        val = i + 1;
        rem_3 = val % 3;
        rem_5 = val % 5;

        if (rem_3 == 0 && rem_5 == 0)
        {
            arr[i] = 'O';
        }
        else if (rem_3 == 0) 
        {
            arr[i] = 'F';
        }
        else if (rem_5 == 0)
        {
            arr[i] = 'B';
        }
        else
        {
            arr[i] = val;
        }
    }
}

int main(void)
{
    int n = 16;
    int arr[n];
    
    fizzbuzz(arr, n);

    print_arr(arr, n, "Array returned: ");
    return 0;
}