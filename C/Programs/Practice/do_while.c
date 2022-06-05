#include <stdio.h>

int main()
{
	int num;
	int i = 0;

	printf("Enter a number: ");
	scanf("%d", &num);
	do
	{ // loop executes atleast once
		printf("%d\n", i);
		i++;

	} while (i < num);

	return 0;
}
