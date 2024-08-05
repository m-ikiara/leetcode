#include <stdio.h>
#include <stdlib.h>

int number_length(int number);
void print_array(int **array, size_t array_length);

int
number_length(int number)
{
    int length = 0;

    while (number != 0) {
        number /= 10;
        length++;
    }

    return length;
}
/*
int *
intToArray(int number)
{
    if (!number) return NULL;

    int length = number_length(number),
        **num_array = malloc(sizeof(int *) * length),
        count = 0;

    **num_array = malloc(sizeof(int *) * length);
	while (number != 0) {
		*num_array[count] = number % 10;
		number /= 10;
		count++;
	}

	return *num_array;
}

void
print_array(int **array, size_t array_length)
{
	printf("[INFO] The length of the array is: %zu\n", array_length);

	printf("[");
	for (size_t i = 0; i < array_length - 1; ++i) {
		printf("%d", *array[i]);
		if (i < array_length - 2) printf(",");
	}
	printf("]\n");
}
*/
int
main(void)
{
    int nums[5] = { 1, 121, 13341, 14641, 1234567899 };

    printf("--------------------------------------------------------------\n");
    for (int j = 0; j < 5; j++) {
        printf("[INFO] Length of %d: %d\n",
                nums[j],
                number_length(nums[j])
                );
    }

    return 0;
}
