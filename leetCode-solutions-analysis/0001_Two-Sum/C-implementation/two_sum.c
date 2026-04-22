#include <stdlib.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* index = malloc(2 * sizeof(int));
    if(index == NULL){
        perror("Failed to allocated!");
        return NULL;
    }

    for(int* p1 = nums; p1 < nums + numsSize - 1; p1++){
        for(int* p2 = p1 + 1; p2 < nums + numsSize; p2++){
            if(*p1 + *p2 == target){
                *index = p1 - nums;
                *(index + 1) = p2 - nums;
                *returnSize = 2;
                return index;
            }

        }
    }
    return NULL;
}