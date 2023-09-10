#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
const int SIZE = 512;

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Usage: %s img\n",argv[0]);
		return 1;
	}
	FILE *raw = fopen(argv[1],"r");

	if(raw == NULL)
	{
		return 2;
	}

	BYTE buffer[SIZE];
	FILE *img = NULL;
	char *filename = malloc(sizeof(char) * 8);
	int count = 0;

	while((fread(buffer, sizeof(buffer), 1, raw) != 0))
	{
		if((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
		{
			if(img != NULL)
			{
				fclose(img);
			}

			sprintf(filename, "%03i.jpg", count);
			img = fopen(filename, "a");
			fwrite(buffer, sizeof(buffer), 1, img);
			count++;
		}
		else if(img != NULL)
			fwrite(buffer, sizeof(buffer), 1, img);
	}
	fclose(img);
	fclose(raw);
	free(filename);
	return 0;
}
