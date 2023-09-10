#include<stdio.h>
#include<math.h>

int main(void){
	float change;

	do{
		printf("Change owed:$ ");
		scanf("%f", &change);
	}while(change < 0);
	
	change = round(change * 100);
	int coin = 0;
	
	while(change >= 25){
		change -= 25;
		coin++;
	}
	while(change >= 10){
		change -= 10;
		coin++;
	}
	while(change >= 5){
		change -= 5;
		coin++;
	}
	while(change >= 1){
		change -= 1;
		coin++;
	}
	printf("%i is required\n", coin);

	return 0;
}

	
