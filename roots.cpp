double root(const int n, const double input)
{
	if (n < 1) return -1;
	if (n == 1) return input;
	
	const int numIters = 100;
	double answer = (input > 0) ? input/2 : input;
	int ctr;
	double xpow;
	int nctr;
	
	for (ctr = 0; ctr < numIters; ctr++)
		{
		xpow = answer;
		for (nctr = 2; nctr < n; nctr++) xpow *= answer;
		answer = (1.0 / n) * ((n-1)*answer + input/(xpow));
		}
	
	return answer;
}
