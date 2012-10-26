#include <iostream>
using namespace std;

bool isPrime(int i);
int* arrayOfPrimes(int numElems);
int  numPrimesFromXtoY(int X, int Y);
void primesPerT(const int n);
bool isPrime2(const int i, int * prevPrimes);


int* arrayOfPrimes(int numElems)
{
	int* p1 = new int[numElems];
	int i, j = 0;
	p1[0] = 2;
	
	for (i=2; j<numElems; i++) if (isPrime2(i, p1)) p1[j++] = i;
	
	return p1;
}


bool isPrime(const int i)//rewrite sending in array, and set j = array[n],
{
	if (i <= 1) return false;
	int j;
	for(j = 2; j*j <= i; j++)
		{
		if(0 == i%j) return false;
		}
	return true;
}

bool isPrime2(const int i, int* prevPrimes)
{
	int ctr, primer = 0;
	
	for (ctr = prevPrimes[primer]; ctr*ctr < i; ctr = prevPrimes[++primer])
		{
		if (0 == i%ctr) return false;
		}
	return true;
}



int  numPrimesFromXtoY(const int X, const int Y)
{
	int i;
	int total = 0;
	
	for (i=X; i<=Y; i++) if (isPrime(i)) total++;
	return total; 
}

void primesPerT(const int n)
{
	int a, b, ctr;
	for (ctr = 0; ctr < n; ctr++)
		{
		a = ctr * 1000;
		b = (ctr+1) * 1000;
		cout << numPrimesFromXtoY(a, b) << " ";
		}
	cout << endl;
}


int NumFactors(int num)
{//haven't tried this guy yet
	int ctr;
	int numFactors = 1;
	
	for (ctr = 2; ctr*ctr < num; ctr++)
	{
		if (0 == num % ctr)
		{
			num /= ctr;
			numFactors++;
			ctr = 1;
		}
	}
	return numFactors;
}





