/*
[2] (Undirected graph, Programming) Write a C++ program to find all the connected components of an undirected graph G.
*/

#include <iostream>
#include <queue>

#define NUM_OF_VERTICES 5


enum COLOR{
	VISITED,
	NOT_VISITED
};

void visit_component(int G[][NUM_OF_VERTICES], int source, COLOR mark[])
{
	std::queue<int> q;
	mark[source] = VISITED;
	q.push(source);

	while (q.empty() != true)
	{
		int vertex = q.front();
		q.pop();
		std::cout << vertex << " ";

		for (int i = 0; i < NUM_OF_VERTICES; i++){
			if (G[vertex][i]){
				if (mark[i] != VISITED){
					mark[i] = VISITED;
					q.push(i);
				}
			}
		}
	}

}

void visit_graph(int G[][NUM_OF_VERTICES])
{
	COLOR mark[NUM_OF_VERTICES];

	for (int i = 0; i < NUM_OF_VERTICES; i++){
		mark[i] = NOT_VISITED;
	}

	for (int i = 0; i < NUM_OF_VERTICES; i++){
		if (mark[i] == NOT_VISITED){
			std::cout << "Component: ";
			visit_component(G, i, mark);
			std::cout << std::endl;
		}
	}
}


int main()
{
	int G[][NUM_OF_VERTICES] = {
		{0, 1, 1, 0, 0},
		{1, 0, 1, 0, 0},
		{1, 1, 0, 0, 0},
		{0, 0, 0, 0, 1},
		{0, 0, 0, 1, 0}
	};

	visit_graph(G);

	return 0;
}

