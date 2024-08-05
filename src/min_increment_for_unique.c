/****************************************************************************
 * @description:
 * You are given an integer array nums. In one move, you can pick an index i
 * where 0 <= i < nums.length and increment nums[i] by 1. Return the minimum
 * number of moves to make every value in nums unique. The test cases are
 * generated so that the answer fits in a 32-bit integer.
 *
 * @example Input: nums = [1, 2, 2] Output: 1
 * @example Input: nums  = [3, 2, 1, 2, 1, 7] Output: 6
 *
 * @constraints:
 *     1. 1 <= nums.length <= 105
 *     2. 0 <= nums[i] <= 105
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int
minIncrementForUnique(int *nums, int numsSize)
{
    int increment_count = 0, *is_unique = {0};
    
    is_unique[0] = nums[0];

    for (int i = 0; i < numsSize; ++i)
        if (nums[i] != is_unique[increment_count])
            is_unique[++increment_count] = nums[i];

    return increment_count;
} 

int
main(void)
{
    int nums[3] = {1, 2, 2}, numsSize = 3;

    for (int i = 0; i < numsSize; ++i) {
        printf("[INFO] Element %d: %d\n", i, nums[i]);
    }

    int result = minIncrementForUnique(nums, numsSize);
    printf("[INFO] The minimum number of moves: %d\n", result);

    return 0;
}

/****************************************************************************
 * @name Minimum Increments needed for each Element to be Unique
 * @author Brian M'Ikiara
 * @version 0.1.0
 ***************************************************************************/