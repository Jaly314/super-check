#include <stdio.h>
#include <stdlib.h>

#include "check.h”


#define DO_NOTHING ;            /* 无操作 */

int add_func(int a, int b)
{
	return a + b;
}

int test_func(int a, int b, int *arr)
{
	CHECK(a > 0, TRUE, return -1);
	CHECK(b > 0, TRUE, goto exit);
	CHECK(arr != NULL, TRUE, return -1);
	
	CHECK(1 + 1, 2, goto exit); 

	*arr = add_func(a, b);
	CHECK(1 + 1, 3, printf("are you kidding me ?\n"); DO_NOTHING);

	return 0;

exit: 
	return -1;
}

int main(void)
{
	int sum = 0;
	
	test_func(6, 8, &sum);

	CHECK(sum, 6 + 8, return -1);

	return 0;
}