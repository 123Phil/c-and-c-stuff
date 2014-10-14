// Phillip Stewart
// finds instances of a specific value in a file
// prints offset locations of bytes with that value

// ./a.out <file to check> <value(0-255)>


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if (argc != 3)
		{
		printf("Usage: %s <file> <number 0-255>\n", argv[0]);
		exit(0);
		}
	
	int length;
	for (length = 0; argv[2][length] != 0; length++) ;
	
	int num = 0;
	int i;
	for (i = 0; i < length; i++)
		{
		if (argv[2][i] < '0' || argv[2][i] > '9')
			{
			printf("Error reading number\n");
			exit(0);
			}
		num *= 10;
		num += argv[2][i] - '0';
		}
		
	if (num > 255)
		{
		printf("Number must be between 0 and 255\n");
		exit(0);
		}
	
	FILE* fp = fopen(argv[1], "r");
	if (fp == NULL)
		{
		printf("Error opening file\n");
		exit(0);
		}
	
	unsigned char ch;
	int ctr = 0;
	for (i = 0; (ch = fgetc(fp)) != EOF; i++)
		{
		if (ch == num)
			{
			printf("%d ", i);
			ctr++;
			if (ctr % 20 == 0)
				{
				printf("\n");
				}
			}
		}
	printf("\n");
	
	fclose(fp);

	return 0;
}
