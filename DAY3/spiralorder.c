
#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize,
                 int* matrixColSize, int* returnSize) {
    int m = matrixSize;
    int n = matrixColSize[0];

    int *result = malloc(m * n * sizeof(int));
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = 0;

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++)
            result[(*returnSize)++] = matrix[top][j];
        top++;

        for (int i = top; i <= bottom; i++)
            result[(*returnSize)++] = matrix[i][right];
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                result[(*returnSize)++] = matrix[bottom][j];
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result[(*returnSize)++] = matrix[i][left];
            left++;
        }
    }

    return result;
}

int main(void) {
    int row1[] = {1, 2, 3};
    int row2[] = {4, 5, 6};
    int row3[] = {7, 8, 9};

    int *matrix[] = {row1, row2, row3};
    int colSize[] = {3, 3, 3};
    int returnSize = 0;

    int *result = spiralOrder(matrix, 3, colSize, &returnSize);

    if (result == NULL)
        return 1;

    printf("Spiral order: ");
    for (int i = 0; i < returnSize; i++)
        printf("%d ", result[i]);

    printf("\n");
    free(result);

    return 0;
}
