// Phillip Stewart
// some random codeEval challenge
// But, I used my own square-root function for some reason...
// so, if you ever need a square-rooter,
// here's a decent one i like to call squirt


#include <stdio.h>

float squirt(float n)
{
// the iters here can be set depending on the size of the size of input,
// but 25 is good enough for most uses
	int iters = 25;
	float guess = n/2.0;
	float k = guess*guess - n;
	while(iters > 0)
		{
		guess = guess - k/(2.0*guess);
		k = guess*guess - n;
		--iters;
		}
	return guess;
}


int main(int argc, char* argv[])
{
	if (argc != 2)
		{
		printf("Usage ...");
		return 0;
		}
	FILE* fp = fopen(argv[1], "r");
	char buffer[80];
		
	int a,b,c,a1,b1;
	while(fgets(buffer, 80, fp))
	{
		sscanf(buffer, "(%d, %d) (%d, %d)", &a,&b,&a1,&b1);
		a -= a1;
		b -= b1;
		c = (int)squirt((float)(a*a + b*b));
		printf("%d\n", c);
	}

	
	fclose(fp);
	return 0;
}
