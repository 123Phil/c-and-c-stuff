// Phillip Stewart
// another codeEval challenge
// this one's pretty messy...

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

std::string int_string(int a)
{
	std::ostringstream o;
	o << a;
	return o.str();
}

void print_adj(std::vector<int> adj, int pos)
{
	std::cout << "adj #" << int_string(pos) << ": ";
	int n = adj.size() - 1;
	int i;
	for (i = 0; i < n; i++) {
		std::cout << int_string(adj[i]) << " ";
	}
	std::cout << int_string(adj[i]) << std::endl;
}

std::vector<int> get_adjs(int x, int y, int pos)
{
	//Can be majorly simplified, but I wanted
	//up,down,left,right separate for copying later
	std::vector<int> adjs;
	//Up, Down, left, right:
	if (pos >= x) {
		adjs.push_back(pos-x);
	}
	if (pos < x*(y-1)) {
		adjs.push_back(pos+x);
	}
	if (pos % x != 0) {
		adjs.push_back(pos-1);
	}
	if (pos % x != x-1) {
		adjs.push_back(pos+1);
	}
	//Corners:
	if (pos > x && pos % x != 0) {
		adjs.push_back(pos-(x+1));
	}
	if (pos >= x && pos % x != x-1) {
		adjs.push_back(pos-(x-1));
	}
	if (pos < x*(y-1) && pos % x != 0) {
		adjs.push_back(pos+(x-1));
	}
	if (pos < x*(y-1) && pos % x != x-1) {
		adjs.push_back(pos+(x+1));
	}
	
//	print_adj(adjs, pos);
	
	return adjs;
	
}

std::string solve_grid(int x, int y, std::string grid)
{
	std::string solved;
	
	for (int i = 0; i < x*y; i++) {
		if (grid[i] != '*') {
			std::vector<int> adjs;
			adjs = get_adjs(x,y,i);
			int num_adjs = adjs.size();
			int dots = 0;
			for (int j = 0; j < num_adjs; j++) {
				if (grid[adjs[j]] == '*') {
					dots++;
				}
			}
			solved = std::string(solved + int_string(dots));//???
		}
		else {
			solved = std::string(solved + "*");
		}
	}
	
//std::cout << grid << std::endl;
	return solved;
}


int main(int argc, char* argv[])
{

	if (argc != 2)
		{
		std::cout << "Usage ...";
		return 0;
		}
	std::ifstream fp(argv[1]);
	
	
	std::string line, grid;
	int x, y;
	while(getline(fp, line))
		{
			std::istringstream ss(line);
			
			ss >> x;
			ss.ignore();
			ss >> y;
			grid = line.substr(4);
			
			std::cout << solve_grid(y,x,grid) << std::endl;
			//std::cout << "X: "<<x<<" Y: "<<y<<" Grid: "<<grid<< std::endl;
		}
	
	fp.close();
	return 0;
}
