// Phil
//
// For CodeEval challenge - https://www.codeeval.com/open_challenges/9/
// Implementation of a stack data structure
// pushes values from file and pops/prints every other




#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>

typedef struct node
{
	int val;
	struct node* next;
}node;


class stioc
{
	node* head;
	int numItems;

public:
	stioc()
	{
		head = NULL;
		numItems = 0;
	}
	
	void push(int value)
	{
		node* a = new node();
		a->next = head;
		a->val = value;
		head = a;
		numItems++;
	}
	
	int pop()
	{
		if (NULL == head) return NULL;
		node* a = head;
		head = head->next;
		int num = a->val;
		delete a;
		numItems--;
		return num;
	}
	
	int len()
	{
		return numItems;
	}
	
	int isEmpty()
	{
		if (NULL == head) return 1;
		else return 0;
	}
};


int main(int argc, char* argv[])
{
	if (argc != 2)
		{
		std::cout << "Usage ...";
		return 0;
		}
	std::ifstream file(argv[1]);
	
	std::string line;
	stioc* s = new stioc();
	int num, i;
	while(!file.eof())
	{
		getline(file, line);
		//for num in line: s->push(num)
		std::istringstream ss(line);
		while(ss >> num)
			{
			s->push(num);
			}
		if (s->isEmpty()) continue;
		//while(-1 != (num = s->pop()): print every other
		for (i = (s->len()+1)/2; i > 0; i--)
			{
			num = s->pop();
			std::cout << num << ' ';//better way to do space??
			s->pop();
			}
		std::cout << std::endl;
	}
	
	
	file.close();
	return 0;
}
