#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(int argc, char * argv[])
{
	if(argc == 2)
	{	
		int key = atoi(argv[1]);
		if(key > 0) {
		char *plaintext = malloc(sizeof(char));
		char *ciphertext = malloc(sizeof(plaintext));
		printf("Plaintext: ");
		scanf("%s", plaintext);

		int len = strlen(plaintext);

		for(int i = 0; i < len; i++)
		{
			
			if(isalpha(plaintext[i]) && islower(plaintext[i]))
			{
				if(plaintext[i] + key > 'z')
				{
					key = (key % 26);
					ciphertext[i] = 'a' +  key;
				}
				else
				{
					ciphertext[i] = plaintext[i] + key;
				}
			}
			else if(isalpha(plaintext[i]) && isupper(plaintext[i]))
			{
				if(plaintext[i] + key > 'Z')
				{
					key = (key % 26);
					ciphertext[i] = 'A' + key; 
				}
				else
				{
					ciphertext[i] = plaintext[i] + key;
				}
			}
			else
			{
				ciphertext[i] = plaintext[i];
			}		
		}
		printf("Ciphertext: %s\n", ciphertext);

		}
		else
		{
			printf("usage: %s key\n", argv[0]);
			return 1;
		}
		return 0;
	}

	else
	{
		printf("usage: %s key\n", argv[0]);
		return 1;
	}
}
