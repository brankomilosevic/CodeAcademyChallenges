/*
*** Capturing Rainwater ***

Create a capturingRainwater() method that takes in an array of heights, and returns the amount of rainwater that could be contained in that array.
Create a maxDepth() method that takes the same array and returns the height of deepest basin.

For example, the array [4, 2, 1, 3, 0, 1, 2] can be represented in the following histogram:

4 *
3 * ~ ~ *
2 * * ~ * ~ ~ *
1 * * * * ~ * *
0 - - - - - - -
 (4 2 1 3 0 1 2)

Calling capturingRainwater() on the array [4, 2, 1, 3, 0, 1, 2] should return 6.
Calling maxDepth() on the array [4, 2, 1, 3, 0, 1, 2] should return 2. (actually, there are two basins with the depth of 2)

2021-11-19
capturingRainwater: Here is the version utilising auxilary matrix
maxDepth: very unnecessary complex solution using matrix

2021-11-22
build capacity array for each location, looking at the left side and search for a maximum, looking at the right side...
max peek that can hold the water is lower between two of these
*/

#include<stdio.h>

void print_matrix(int cols, int rows, int arr[rows][cols])
{
    printf("\n");
    for(int i = 0; i < cols; ++i) printf("--"); 
    printf("\n");

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
            printf(" %d", arr[i][j]);
        printf("\n");
    }

    for(int i = 0; i < cols; ++i) printf("--"); 
    printf("\n");
}

void build_0_1_matrix(int cols, int rows, int arr[cols], int matrix[rows][cols])
{
    for (int i = 0; i < cols; ++i)
    {
        for (int j = rows-1; j >= rows-arr[i]; --j)
            matrix[j][i] = 1;

        for (int j = rows-arr[i]-1; j >= 0; --j)
            matrix[j][i] = 0;
    }
}

int arrayHeight(int *arr, int n)
{
    int height = 0;
    
    for (int i = 0; i < n; ++i)
        if (arr[i] > height)
            height = arr[i];

    return height;
}

int maxDepth(int *arr, int n)
{
    int beg = -1, end = n + 1;
    int row = 0, i = 0, j=0, res = 0;

    int height = arrayHeight(arr, n);
    int matrix[height][n];
    build_0_1_matrix(n, height, arr, matrix);
    print_matrix(n, height, matrix);

    for (row = 0; row < height; ++row)
    {
        for (i = 0; i < n-1; ++i)
        {
            if (matrix[row][i] == 1 && matrix[row][i+1] == 0)   beg = i;
            if (matrix[row][i] == 0 && matrix[row][i+1] == 1)   
            {
                end = i;
                if (beg >= 0 && end<n) 
                {
                    for(int k = beg+1; k <= end; k++)
                        matrix[row][k] = 2;
                }
            }
        }
    }

    for (j = 0; j < n; ++j)
    {
        int row_max = 0;
        for (i = 0; i < height; ++i)
        {
            if (matrix[i][j] == 2) row_max++;
        }
        if (row_max > res) res = row_max;
    }
    print_matrix(n, height, matrix);

    return res;
}

/*
// this one uses matrix 0 1 (free space r rock)
int capturingRainwater(int *arr, int n)
{
    int res = 0;
    int height = arrayHeight(arr, n);

    int matrix[height][n];

    build_0_1_matrix(n, height, arr, matrix);

    print_matrix(n, height, matrix);

    int beg = 0, end = 0;
    int row = 2, cap = 0;

    beg = -1;
    end = n+1;

    for (row = 0; row<height; ++row)
    {
        cap = 0;
        for (int i=0; i<n-1; ++i)
        {
            if (matrix[row][i] == 1 && matrix[row][i+1] == 0)   beg = i;
            if (matrix[row][i] == 0 && matrix[row][i+1] == 1)   
            {
                end = i;
                if (beg>=0 && end<n) cap += end-beg;
            }
        }
        // printf("\n-> cap[%d]: %d", row, cap);
        res += cap;
    }

    return res;
}
*/

// this one uses arrays of peeks on left and right side of one loacation
int capturingRainwater(int *arr, int n)
{
    int res = 0;
    int left[n];    //max peek left of the i
    int right[n];   //max peek right of the i
    int cap[n];     //capacity on position 1

    printf("\nTerrain:\t"); for (int i = 0; i < n; ++i) printf("%d ", arr[i]);

    left[0] = 0;
    for (int i = 1; i < n; ++i)
        left[i] = (left[i-1] > arr[i-1]) ? left[i-1] : arr[i-1];
    printf("\nMax LEFT:\t"); 
    for (int i = 0; i < n; ++i) printf("%d ", left[i]);

    right[n-1] = 0;
    for (int i = n-2; i >= 0; --i)
        right[i] = (right[i+1] > arr[i+1]) ? right[i+1] : arr[i+1];
    printf("\nMax RIGHT:\t"); 
    for (int i = 0; i < n; ++i) printf("%d ", right[i]);

    for (int i = 0; i < n; ++i)
    {
        cap[i] = 0;
        cap[i] = (left[i] < right[i] ? left[i] : right[i]) - arr[i];
        if (cap[i] < 0) cap[i] = 0;
        // res += cap[i];  // total water
        if (res < cap[i]) res = cap[i]; // max depth
    }
    printf("\nCapacity:\t"); 
    for (int i = 0; i < n; ++i) printf("%d ", cap[i]);

    return res;
}



int main(void)
{
    int arr[] = {4, 2, 1, 3, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\nCapacity: %d\n", capturingRainwater(arr, n));
    // printf("\nMax depth is: %d\n", maxDepth(arr, n));

    return 0;
}