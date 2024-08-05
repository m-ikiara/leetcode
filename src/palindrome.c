#include <stdio.h>
#include <stdbool.h>

int
reverse_integer(int number)
{
	int result = 0;

	while (number != 0) {
		int i = number % 10;
		result = result * 10 + i;
		number /= 10;
	}

	return result;
}

bool
isPalindrome(int x)
{
	return reverse_integer(x) == x;
}

int
main(void)
{
	int nums[5] = { 1, 121, 13341, 14641, 123567899 };

	for (int i = 0; i < 5; ++i) {
		printf("%d\n", isPalindrome(nums[i]));
	}

	return 0;
}
