// Phillip Stewart
// another one of those boggle type algorithms I love so much...

#include <stdio.h>

int In(int path[], int n)
{
	int i = 0;
	while(-1 != path[i])
		{
		if (path[i] == n) return 1;
		i++;
		}
	return 0;
}

int NextAdj(int path[], int i)
{
	if (i > 10) path[i+2] = -1;
	int last  = path[i+1];
	int up    = path[i] - 4;
	int left  = path[i] - 1;
	int right = path[i] + 1;
	int down  = path[i] + 4;
	
	//checking for previous adjs
	//order of adj return is up, left, right, down
	//so if last adj was left, try right then down
	if (last == down)
		{
		return -1;
		}
	else if (last == right)
		{
		if (down < 12 && 0 == In(path, down)) return down;
		else return -1;
		}
	else if (last == left)
		{
		if (0 != right%4 && 0 == In(path, right)) return right;
		else if (down < 12 && 0 == In(path, down)) return down;
		else return -1;
		}
	else if (last == up)
		{
		if (0 != (left+1)%4 && 0 == In(path, left)) return left;
		else if (0 != right%4 && 0 == In(path, right)) return right;
		else if (down < 12 && 0 == In(path, down)) return down;
		else return -1;
		}
	else if (last == -1)
		{
		if (up >= 0 && 0 == In(path, up)) return up;
		else if (0 != (left+1)%4 && 0 == In(path, left)) return left;
		else if (0 != right%4 && 0 == In(path, right)) return right;
		else if (down < 12 && 0 == In(path, down)) return down;
		else return -1;
		}
}

int Find(char word[], char board[])
{
	int n = 0;
	int path[12] = {0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	
	while(0 != word[n])
		{
		if (word[n] == board[path[n]])
			{
			n++;
			if (n == 12)
				{
				if (word[n] == 0) return 1;
				else return 0;
				}
			path[n] = -1;
			}
		if (0 == n)
			{
			path[0]++;
			if (path[0] == 12) return 0;
			}
		else
			{
			while(-1 == (path[n] = NextAdj(path, n-1)))
				{
				n--;
				if (0 == n)
					{
					path[0]++;
					if (path[0] == 12) return 0;
					break;
					}
				}
			}
		}
		return 1;
}

int main(int argc, char* argv[])
{

	if (argc != 2)
		{
		printf("Usage ...");
		return 0;
		}
	FILE* fp = fopen(argv[1], "r");
	
	char board[] = "ABCESFCSADEE";
	
	int i;
	char buffer[32];
	while(fgets(buffer, 32, fp))
		{
		i = 0;//stripping '\n' character
		while('\n' != buffer[i]) i++;
		buffer[i] = 0;
		
		if (1 == Find(buffer, board)) printf("True\n");
		else printf("False\n");
		}
	
	fclose(fp);
	return 0;
}
