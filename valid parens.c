// Phillip Stewart
// codeEval challenge - Paren validator...
// it's kinda hacky, uses an array to simulate a stack

#include <stdio.h>


int main(int argc, char* argv[])
{

	if (argc != 2)
		{
		printf("Usage ...");
		return 0;
		}
	FILE* fp = fopen(argv[1], "r");
	
	int i, pctr;
	int valid;
	char c;
	char parens[80];
	char buffer[80];
	while(fgets(buffer, 80, fp))
		{
		valid = 1;
		i = 0;
		pctr = 0;
		while('\n' != (c = buffer[i]))
			{
			if ('(' == c||'{' == c||'[' == c)
				{
				parens[pctr] = c;
				pctr++;
				}
			else if (')' == c)
				{
				if (pctr > 0 && parens[pctr-1] == '(')
					{
					pctr--;
					}
				else
					{
					valid = 0;
					break;
					}
				}
			else if ('}' == c)
				{
				if (pctr > 0 && parens[pctr-1] == '{')
					{
					pctr--;
					}
				else
					{
					valid = 0;
					break;
					}
				}
			else if (']' == c)
				{
				if (pctr > 0 && parens[pctr-1] == '[')
					{
					pctr--;
					}
				else
					{
					valid = 0;
					break;
					}
				}
			i++;
			}//end of while( c = buffer[i]
		if (1 == valid) printf("True\n");
		else printf("False\n");
		}//end of while(fgets
	
	fclose(fp);
	return 0;
}
