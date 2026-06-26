#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} hmap;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    hmap* hashMap = (hmap*) malloc(numsSize * sizeof(hmap));

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];

        for (int j = 0; j < i; j++) {
            if (hashMap[j].key == complement) {
                int* res = (int*) malloc(2 * sizeof(int));
                res[0] = hashMap[j].value;
                res[1] = i;
                *returnSize = 2;
                free(hashMap);
                return res;
            }
        }
        hashMap[i].key = nums[i];
        hashMap[i].value = i;
    }

    *returnSize = 0;
    free(hashMap);
    return NULL;
}

void print_numbers(int* nums, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        if (i < size - 1) {
            printf("%d, ", nums[i]);
        } else {
            printf("%d", nums[i]);
        }
    }
    printf("]\n");
}

void print_results(int* nums, int numSize, int target, int* returnSize) {
    print_numbers(nums, numSize);
    int* res = twoSum(nums, numSize, target, returnSize);
    print_numbers(res, *returnSize);
}

int main(void) {
    int numsOne[4] = {2, 7, 11, 15};
    int targetOne = 9;
    int returnSizeOne;

    print_results(numsOne, sizeof(numsOne) / sizeof(numsOne[0]), targetOne, &returnSizeOne);
 
    int numsTwo[3] = {3, 2, 4};
    int targetTwo = 6;
    int returnSizeTwo;
    
    print_results(numsTwo, sizeof(numsTwo) / sizeof(numsTwo[0]), targetTwo, &returnSizeTwo);

    int numsThree[2] = {3, 3};
    int targetThree = 6;
    int returnSizeThree;
    
    print_results(numsThree, sizeof(numsThree) / sizeof(numsThree[0]), targetThree, &returnSizeThree);

    return 0;
}
