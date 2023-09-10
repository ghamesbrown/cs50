#include<stdio.h>

int main(void)
{
	int n, ss, es, c = 0;

	do
	{
		printf("Starting size: ");
		scanf("%i", &ss);
	}while (ss < 1 || ss < 9);

	do
	{
		printf("Ending size: ");
		scanf("%i", &es);
	}while(es <= ss);
	n = ss;
	while(es > n)
	{
		n = n + ((n / 3) - (n / 4)); 
		c++;
	}
	printf("Years : %i\n", c);

	return 0;
}
