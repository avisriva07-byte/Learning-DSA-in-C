
#include <stdio.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
    int maxReach = 0;

    for (int i = 0; i < numsSize; i++) {
        if (i > maxReach) {
            return false;
        }

        if (i + nums[i] > maxReach) {
            maxReach = i + nums[i];
        }
    }

    return true;
}

int main(void) {
    int nums[] = {2, 3, 1, 1, 4};
    int size = sizeof(nums) / sizeof(nums[0]);

    printf("%s\n", canJump(nums, size) ? "true" : "false");

    return 0;
}
