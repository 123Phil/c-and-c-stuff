// Phillip Stewart
// codeEval challenge
// https://www.codeeval.com/open_challenges/72/
// Given a matrix, n*n, it finds the path from top-left to bottom right
// with the lowest sum of numbers traversed

// I wrote this one after writing my boggle solver and doing a similar problem
// on project euler -
// I really like the crawling over a matrix problems, but
// my solutions are usually hacky and unreadable...
// Congrats if you can follow my logic here!

#include <stdio.h>
#include <stdlib.h>

#define DOWN 1
#define RIGHT 0

int adder(int** matrix, int* indys, int steps)
{
	int total = matrix[0][0];
	int i;
	int x = 0, y = 0;
	for (i = 0; i < steps; i++)
		{
		if (DOWN == indys[i]) y += 1;
		else x += 1;
		total += matrix[x][y];
		}
	return total;
}

int nextStep(int* indys, int steps)//this is beautiful
{
	int can_inc = 0;
	int i = steps - 1;
	int slide_back = 0;
	
	while (i >= 0)
		{
		if (RIGHT == indys[i])
			can_inc = 1;
		else if (DOWN == indys[i])
			{
			if (1 == can_inc)
				{
				indys[i] = RIGHT;
				i++;
				indys[i] = DOWN;
				while (slide_back > 0)
					{
					i++;
					indys[i] = DOWN;
					if (i != steps-slide_back)
						indys[steps-slide_back] = RIGHT;
					slide_back -= 1;
					}
				return 1;
				}
			else slide_back += 1;
			}
		i -= 1;
		}
	return 0;
}


int minPathSum(int** matrix, int n)
{
	int minTotal;
	int i;
	int steps = (n-1)*2;
	int* indys = (int*)malloc(sizeof(int)*steps);
	int x,y;
	
	for (i = 0; i < steps; i++)
		{
		if (i < steps/2) indys[i] = DOWN;
		else indys[i] = RIGHT;
		}
	
	minTotal = adder(matrix, indys, steps);

	do
	{
// IF YOU WANT TO SEE ALL OF THE PATHS:
//		int ctr;
//		for (ctr = 0; ctr < steps; ctr++) printf("%d ",indys[ctr]);
//		printf("\n");
		if (adder(matrix, indys, steps) < minTotal)
			minTotal = adder(matrix, indys, steps);
	} while (nextStep(indys, steps));

	free(indys);
	return minTotal;
}


void testPrint(int** m, int n)
{
	int i,j;
	for (i = 0; i < n; i++)
		{
		for (j = 0; j < n; j++)
			{
			printf("%d ", m[i][j]);
			}
		printf("\n");
		}
}



int main(int argc, char* argv[])
{

	if (argc != 2)
		{
		printf("Usage ~$ %s filename.txt\n", argv[0]);
		return 0;
		}
	FILE* fp = fopen(argv[1], "r");
	
	char buffer[80];
	char *strptr;
	int bites;
	int i,j;
	int n;
	int** matrix;
	
	while(fgets(buffer, 80, fp))
		{
		if (1 != sscanf(buffer, "%d", &n))
			{
			printf("Problems with sscanf, yo\n");
			return 0;
			}
			
		matrix = (int**)malloc(sizeof(int*)*n);
		for (i = 0; i < n; i++)
			{
			matrix[i] = (int*)malloc(sizeof(int)*n);
			fgets(buffer, 80, fp);
			strptr = buffer;
			for (j = 0; j < n; j++)
				{
				sscanf(strptr, "%d%*c%n", &matrix[i][j], &bites);
				strptr += bites;
				}
			}

// TO MAKE SURE MATRICES ARE LOADING CORRECTLY:			
//		testPrint(matrix, n);
		
		int answer = minPathSum(matrix, n);
		printf("%d\n", answer);
		
		for (i = 0; i < n; i++) free(matrix[i]);
		free(matrix);
		}
	
	fclose(fp);
	return 0;
}
