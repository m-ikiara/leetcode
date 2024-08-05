#include <stdio.h>
#include <stdlib.h>

int *
twoSum(int *nums, int numsSize, int target, int *returnSize)
{
	if (!nums) return NULL;
	if (numsSize < 0) return NULL;
	int *result = (int *) malloc(sizeof(int) * 2);

	for (int i = 0; i < numsSize - 1; i++) {
		for (int j = i + 1; j < numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				*returnSize = 2;
				result[0] = i, result[1] = j;
				return result;
			}
		}
	}
	*returnSize = 0;

	return NULL;
}

int
main(void)
{
	int nums[5] = { 1, 5, 3, 4, 2 },
	   	numsSize = 5, target = 10, returnSize = 0;

	int *result = twoSum(nums, numsSize, target, &returnSize);

	if (result) {
		printf("[");
		for (int i = 0; i < 2; i++) {
			printf("%d", result[i]);
			if (i == 0) printf(",");
		}
		printf("]\n");
	} else {
		printf("[]\n");
	}

	return 0;
}

/***************************************************************************
 * @description
 * Given an array of integers nums and an integer target, return indices of the
 * two numbers such that they add up to target. You may assume that each input
 * would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 *
 * @examples
 *     1. Input: nums = [2,7,11,15], target = 9
 *        Output: [0,1]
 *     2. Input: nums = [3,2,4], target = 6
 *        Output: [1,2]
 * @returns An array of the integer indices that add up to target
 ***************************************************************************/
