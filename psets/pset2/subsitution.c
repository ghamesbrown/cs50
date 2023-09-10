#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//function to check whether the command line argument has a non-alphabetic character
int alphaValid(char *argv[])
{
	int check = 0;

	for(int i = 0; i < 26; i++)
	{
		if(isdigit(argv[1][i]) || !isalpha(argv[1][i]))
		{
			check = 1;
			break;	
		}
		else
		{
			check = 0;
		}
	}
	return check;
}

//function to check whether there are duplicated alphabetic characters
int dup(char *argv[])
{
	int n = 0, len = strlen(argv[1]), b = 0;
	
	for(int a = 0; a < len; a++)
	{
		if(isupper(argv[1][a]))
		{
			argv[1][a] = tolower(argv[1][a]);
		}
		else
		{
			argv[1][a] = argv[1][a];
		}
	}

	while(n < len - 1 && b == 0)
	{
		for(int i = n; i <= len; i++)
		{
			if(argv[1][n] == argv[1][i+1])
			{
				b+=1;
				break;
			}
			else
			{
				b+=0;
			}
		}
		n += 1;
	}
	return b;
}

int main(int argc, char *argv[])
{
	if(argc == 2 && strlen(argv[1]) == 26 && alphaValid(argv) < 1)
	{
		if(dup(argv) == 0) 
		{
			//argument 1 should be case-insensitive
			char *plaintext = malloc(sizeof(char)), *ciphertext = malloc(sizeof(plaintext));
			
			printf("Plaintext: ");
			scanf("%s", plaintext);

			int len = strlen(plaintext);

			for(int i = 0; i < len; i++)
			{
				if(!isalpha(plaintext[i]) || isdigit(plaintext[i]))
				{
					ciphertext[i] = plaintext[i];
				}
				else if(isupper(plaintext[i]))
				{
					ciphertext[i] = toupper(argv[1][plaintext[i] - 65]);
				}
				else
				{
					ciphertext[i] = argv[1][plaintext[i] - 97];
				}
			}
			printf("ciphertext: %s\n", ciphertext);
			free(plaintext);
			free(ciphertext);	
			return 0;
	}
		else
		{
			puts("Duplicate alphabetic character passed in command line");
			return 1;
		}
	}
	else
	{
		printf("Usuage: %s key of 26 alphabetic characters.\n", argv[0]);
		return 1;
	}
	return 0;
}
