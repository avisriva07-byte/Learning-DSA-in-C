
#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    int *ptr = arr;
    int i;

    
    for (i = 0; i < n; i++) {
        scanf("%d", ptr + i);
    }

   
    for (i = 0; i < n; i++) {
        printf("%d ", *(ptr + i));
    }

    return 0;
}
