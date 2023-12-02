#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int convert_to_single_digit(int x)
{
	if(x >= 10)
	{
		x = x - (x % 10);
		x = x / 10;

		return convert_to_single_digit(x);
	}
	return x;
}

int get_number(char* line)
{	
	int last_digit = -1, first_digit = -1;
	int i = 0;

	char* err = NULL;

	while(line[i] != '\0')
	{
		if(isdigit(line[i]))
		{
			if(first_digit < 0) first_digit = strtol(&line[i], NULL, 10);

			last_digit = strtol(&line[i], &err, 10);
		}

		i++;
	}

	first_digit = convert_to_single_digit(first_digit);
	last_digit = convert_to_single_digit(last_digit);

	int res = (first_digit * 10) + last_digit;

	printf("%d\n", res);

	return res;
}

int main()
{
	FILE* file;

	file = fopen("input.txt", "r");
	if(file == NULL)
	{
		return -1;
	}

	char line[256];
	int sum = 0;
	while (fgets(line, sizeof(line), file) != NULL)
	{
		sum += get_number(line);
	}

	printf("\tSum: %d\n", sum);
	fclose(file);

	return 0;
}