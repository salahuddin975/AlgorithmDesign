/*
Describe an algorithm to enumerate all simple cycles of an undirected graph G
*/

#include <iostream>
#include <queue>

#include <iostream>

#define NUM_OF_VERTICES 5


enum COLOR{
	WHITE,
	GRAY,
	BLACK
};

int num_of_cycles = 0;

void dfs_visit_matrix(int G[][NUM_OF_VERTICES], int vertex, int parent, COLOR color[])
{
	color[vertex] = GRAY;

	for (int i = 0; i < NUM_OF_VERTICES; i++){
		if (G[vertex][i]){
			if (color[i] == WHITE){
				dfs_visit_matrix(G, i, vertex, color);
			}
			else if (i != parent && color[i] == GRAY){
				num_of_cycles = num_of_cycles + 1;
				std::cout << "Cycles from: " << vertex << std::endl;
			}
		}
	}

	color[vertex] = BLACK;
}


int main()
{
	int time = 0;
	int d[NUM_OF_VERTICES], f[NUM_OF_VERTICES];

	int G[][5] = {
		{ 0, 1, 1, 1, 1 },
		{ 1, 0, 1, 0, 0 },
		{ 1, 1, 0, 0, 2 },
		{ 1, 0, 0, 0, 1 },
		{ 1, 0, 2, 1, 0 }
	};

	COLOR color[] = { WHITE, WHITE, WHITE, WHITE, WHITE };

	//----------------------- DFS using matrix --------------------

	for (int i = 0; i < NUM_OF_VERTICES; i++){
		if (color[i] == WHITE) {
			dfs_visit_matrix(G, i, -1, color);
		}
	}

	std::cout << "Number of cycles: " << num_of_cycles << std::endl;

	return 0;
}

