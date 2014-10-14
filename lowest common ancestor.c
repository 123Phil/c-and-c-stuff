// Phillip Stewart
// codeEval challenge to find the lowest common ancestor in a tree

#include <stdlib.h>
#include <stdio.h>


typedef struct node
{
	int val;
	struct node* left;
	struct node* right;
}node;


void insert(node* N, int value)
{
	if (value < N->val)
		{
		if (N->left == NULL)
			{
			node* a = (node*) malloc(sizeof(node));
			a->val = value;
			a->left = NULL;
			a->right = NULL;
			N->left = a;
			}
		else
			{
			insert(N->left, value);
			}
		}
	else if (value > N->val)
		{
		if (N->right == NULL)
			{
			node* a = (node*) malloc(sizeof(node));
			a->val = value;
			a->left = NULL;
			a->right = NULL;
			N->right = a;
			}
		else
			{
			insert(N->right, value);
			}
		}
	else
		{
		printf("Value already in tree\n");
		}
}

int LCA(node* N, int v1, int v2)
{
	while((v1 < N->val && v2 < N->val) || (v1 > N->val && v2 > N->val))
		{
		if (v1 < N->val) N = N->left;
		else if (v1 > N->val) N = N->right;
		}

	return N->val;
}



int main(int argc, char* argv[])
{
	node* head = (node*) malloc(sizeof(node));
	head->val = 30;
	head->right = NULL;
	head->left = NULL;
	
	insert(head, 8);
	insert(head, 52);
	insert(head, 3);
	insert(head, 20);
	insert(head, 10);
	insert(head, 29);
	

	if (argc != 2)
		{
		printf("Usage ...");
		return 0;
		}
	FILE* fp = fopen(argv[1], "r");
	
	int v1,v2;
	int common;
	char buffer[80];
	while(fgets(buffer, 80, fp))
		{
		sscanf(buffer, "%d %d", &v1, &v2);
		common = LCA(head, v1, v2);
		printf("%d\n", common);
		}
	
	fclose(fp);
	return 0;
}
