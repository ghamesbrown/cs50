#include<stdio.h>
#include<math.h>

long sigfig(long cardNo);

int main(void){
	long cardNo;

	do{
		printf("Number: ");
		scanf("%ld", &cardNo);
	}while(sigfig(cardNo) < 13 || sigfig(cardNo) > 16);
	
	long count1 = 100, count2 = 10, c1 = 10, c2 = 1, sig, sig1, sum1 = 0, 
	     sum2 = 0, length = sigfig(cardNo)/2 + 1, digi = sigfig(cardNo);

	for(int i = 0; i < length; i++)
	{
		sig = ((cardNo % count1) / count2) * 2;
		sig1 = ((cardNo % c1) / c2);
		count1 *= 100;
		count2 *= 100;
		c1 *= 100;
		c2 *= 100;
		if(sig > 9){
			sig = (sig % 10) + (sig % 100) / 10;
		}
		sum1 += sig;
		sum2 += sig1;
	}

	long checksum = sum1 + sum2;	

	if (checksum % 10 == 0){

		if(digi == 15){
			cardNo = cardNo / pow(10, digi - 2);

		       	if((cardNo >= 34) || (cardNo <= 37)){
			       printf("America Express\n");
			       }
		}

		else if (digi == 16){
			cardNo = cardNo / pow(10, digi - 2);
			printf("%ld\n", cardNo);
			if((cardNo >= 51) || (cardNo <= 55)){
			printf("Master card\n");
			}
		}

		else if ((digi >= 13) || (digi <= 16)){
			cardNo = cardNo / pow(10, digi - 1); 
			if(cardNo == 4)
			{
				printf("Visa card\n");
			}
		}

	/*American Express - 15 digits | 34 or 37
	 * master card - 16 digits | 51 - 55	
	 * visa 13 - 16 digits | 4
	 */
	}

	else{
		printf("Invalid card number!\n");
	}
}

long sigfig(long cardNo){
	int sigfig = 0;

	while(cardNo > 0){
	cardNo = cardNo / 10;
	sigfig++;	
	}
	return sigfig; 	
}

