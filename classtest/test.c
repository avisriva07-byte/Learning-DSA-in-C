#include <stdio.h>

int main(void)
{
    int r, c;
    scanf("%d%d", &r, &c);

    int matrix[r][c];

   
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Original matrix:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

   
    printf("After 90 degree turn:\n");
    for (int j = 0; j < c; j++)
    {
        for (int i = r - 1; i >= 0; i--)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}