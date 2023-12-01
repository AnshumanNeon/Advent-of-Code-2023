#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int arr[] = { 0 };
int n = 0;

int firstDigit(int n)
{
  while (n >= 10)
	{
    n /= 10;
	}
     
  return n;
}

int give_first_and_last_only(int n)
{
	int last_digit = n % 10;
	int first_digit = firstDigit(n);

	return (first_digit * 10) + last_digit;
}

void get_number(char* line)
{
	char *p = line;

	while(*p)
	{
    if(isdigit(*p) || ( (*p == '-' || *p == '+') && isdigit(*(p + 1)) ))
		{
      int val = (int)strtol(p, &p, 10);

			if(val - 10 < 0) arr[n] = val * 11;
			else
			{
				if(val - 100 >= 0)
				{
					arr[n] = give_first_and_last_only(val);
				}
				else
				{
					arr[n] = val;
				}
			}
			n++;

			printf("%d\n", arr[n-1]);
    }
		else
		{
      p++;
    }
	}
}

int sum_of_array()
{
	int sum = 0;

	for(int i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}

	return sum;
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

	while (fgets(line, sizeof(line), file) != NULL)
	{
		get_number(line);
	}

	fclose(file);

	return 0;
}