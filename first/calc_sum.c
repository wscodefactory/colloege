#include <stdio.h>

int calc_sum(int list[],int rows, int cols)
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {   for (int j = 0 ; j < cols; j++)
            {
            sum += list[i*cols*j];
            }
    }
    return sum;
}