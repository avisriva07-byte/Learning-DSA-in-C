
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 3;
    int a[3][3];
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int num = 1;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++)
            a[top][j] = num++;
        top++;

        for (int i = top; i <= bottom; i++)
            a[i][right] = num++;
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                a[bottom][j] = num++;
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                a[i][left] = num++;
            left++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    return 0;
}

