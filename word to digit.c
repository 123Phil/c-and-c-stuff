// Phillip Stewart
// some codeEval challenge...

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* nextNum(char* buf, int* i)
{
	char str[80];
	strncpy(str, buf, 79);
	int end = 0;
		
	int ctr;
	for (ctr = 0; ctr<80; ctr++)
		{
		if (str[ctr] == ';')
			{
			str[ctr] = 0;
			break;
			}
		else if (str[ctr] == '\n' || str[ctr] == ' ')
			{
			str[ctr] = 0;
			end = 1;
			break;
			}
		}
	
	if (0 == strcmp(str,"zero"))      *i = 0;
	else if (0 == strcmp(str,"one"))  *i = 1;
	else if (0 == strcmp(str,"two"))  *i = 2;
	else if (0 == strcmp(str,"three"))*i = 3;
	else if (0 == strcmp(str,"four")) *i = 4;
	else if (0 == strcmp(str,"five")) *i = 5;
	else if (0 == strcmp(str,"six"))  *i = 6;
	else if (0 == strcmp(str,"seven"))*i = 7;
	else if (0 == strcmp(str,"eight"))*i = 8;
	else if (0 == strcmp(str,"nine")) *i = 9;
	
	if (end) return NULL;
	else return buf + strlen(str) + 1;
}

int main(int argc, char **argv)
{
	FILE* fp = fopen(argv[1], "r");
	
	char* buffer = (char*)malloc(120);
	char* b2;
	int i;
	
	while(fgets(buffer, 120, fp))
		{
		b2 = buffer;
		while(b2 = nextNum(b2, &i))
			printf("%d",i);
		printf("%d\n",i);
		}
	return 0;
}
