/*
*** Reverse Words ***

Write a wordReverser() method that will take a given string and reverse the order of the words. 
You may assume that the string is a sentence that contains only letters and spaces, with all words separated by one space.

For example
wordReverser("Codecademy rules") should return "rules Codecademy" 
wordReverser("May the Fourth be with you") should return "you with be Fourth the May".

2021-11-18
Not very elegant and it is risky, but it is working for test samples.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* wordReverser(char *str)
{
    char *token;
    int l = strlen(str);
    char *res = malloc(l+1);
    int position;

    for (int i = 0; i < l; ++i) res[i] = '.';   // not necessary, only to mark it during debugging...
    res[l] = 0;
    
    token = strtok(str, " ");
    position = l - strlen(token);
    strcpy(res + position, token);

    while (token != NULL)
    {
        token = strtok(NULL, " ");
        if (token!= NULL)
        {
            position -= strlen(token) + 1;
            strcpy(res + position, token);
            res[position + strlen(token)] = 32; // ASCI=32 is 'space'
        }
    }

    return res;
}

int main(void)
{
    // char str[] = "Hello there";
    char str[] = "May the Fourth be with you";
    char *res;

    printf("::: %s :::\n", str);
    res = wordReverser(str);
    printf("::: %s :::\n", res);

    return 0;
}