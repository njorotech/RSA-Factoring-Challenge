#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void factorization(unsigned long long n);
int main(int ac, char **av)
{
	FILE *ptr;
	unsigned long long n;

	if (ac != 2)
	{
		printf("Usage: %s <file>\n", av[0]);
		return (1);
	}

	ptr = fopen(av[1], "r");

	if (ptr == NULL)
	{
		printf("File opening failed");
		return (1);
	}

	while (fscanf(ptr, "%llu\n", &n) != EOF)
	{
		factorization(n);
	}

	fclose(ptr);
	return (0);
}

void factorization(unsigned long long n)
{
	unsigned long long q, p, i;

	for (i =2; i <= n / 2; i++)
	{
		if (n % i == 0)
		{
			q = i;
			p = n / i;
			printf("%llu=%llu*%llu\n", n, p, q);
			break;
		}
	}
}
