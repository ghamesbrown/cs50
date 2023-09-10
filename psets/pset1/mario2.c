#include<stdio.h>

int main (void)
{
	int height;

	do {
		printf("Height: ");
		scanf("%i", & height);
	}while(height < 1 || height > 8);

	for(int rows = 0; rows < height; rows++){
		for(int spaces = height - 1; spaces > rows; --spaces){
			printf(" ");
		}
		for(int hash = 0; hash <= rows; ++hash){
			printf("#");
		}
		printf("  ");
		for(int next = 0; next <= rows; ++next){
			printf("#");
		}
		printf("\n");

	}
	return 0;
}
