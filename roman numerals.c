// Phillip Stewart
// codeEval challenge
// Converts numbers into their roman numeral equivalent

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void convert(char* str, int i)
{
	int rindex = 0;
	while (i > 0)
		{
		if (i >= 1000)
			{
			i -= 1000;
			str[rindex] = 'M';
			rindex++;
			}
		else if (i >= 900)
			{
			i -= 900;
			str[rindex] = 'C';
			rindex++;
			str[rindex] = 'M';
			rindex++;
			}
		else if (i >= 500)
			{
			i -= 500;
			str[rindex] = 'D';
			rindex++;
			}
		else if (i >= 400)
			{
			i -= 400;
			str[rindex] = 'C';
			rindex++;
			str[rindex] = 'D';
			rindex++;
			}
		else if (i >= 100)
			{
			i -= 100;
			str[rindex] = 'C';
			rindex++;
			}
		else if (i >= 90)
			{
			i -= 90;
			str[rindex] = 'X';
			rindex++;
			str[rindex] = 'C';
			rindex++;
			}
		else if (i >= 50)
			{
			i -= 50;
			str[rindex] = 'L';
			rindex++;
			}
		else if (i >= 40)
			{
			i -= 40;
			str[rindex] = 'X';
			rindex++;
			str[rindex] = 'L';
			rindex++;
			}
		else if (i >= 10)
			{
			i -= 10;
			str[rindex] = 'X';
			rindex++;
			}
		else if (i >= 9)
			{
			i -= 9;
			str[rindex] = 'I';
			rindex++;
			str[rindex] = 'X';
			rindex++;
			}
		else if (i >= 5)
			{
			i -= 5;
			str[rindex] = 'V';
			rindex++;
			}
		else if (i >= 4)
			{
			i -= 4;
			str[rindex] = 'I';
			rindex++;
			str[rindex] = 'V';
			rindex++;
			}
		else if (i >= 1)
			{
			i -= 1;
			str[rindex] = 'I';
			rindex++;
			}
		}
	str[rindex] = 0;
	return;
}

int main(int argc, char **argv)
{
	FILE* fp = fopen(argv[1], "r");
	
	char buffer[80];
	char* romans = (char*)malloc(80);
	int i;
	
	while(fgets(buffer, 80, fp))
		{
		sscanf(buffer, "%d", &i);
		convert(romans, i);
		printf("%s\n",romans);
		}
	return 0;
}
