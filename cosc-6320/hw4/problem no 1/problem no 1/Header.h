#include <iostream>
#include <set>


#define NUM_OF_VERTICES 5
#define INF 555555

enum COLOR{
	WHITE,
	GRAY,
	BLACK
};

struct Node
{
	int vertex;
	Node *next;
};

