#include "Header.h"


void dfs_matrix(int G[][NUM_OF_VERTICES], int vertex, COLOR color[], int &time, int d[], int f[])
{
	color[vertex] = GRAY;
	time = time + 1;
	d[vertex] = time;

	for (int i = 0; i < NUM_OF_VERTICES; i++){
		if (G[vertex][i]){
			if (color[i] == WHITE){
				dfs_matrix(G, i, color, time, d, f);
			}
		}
	}

	color[vertex] = BLACK;
	time = time + 1;
	f[vertex] = time;
}


void dfs_list(Node *G_list[], int vertex, COLOR color[], int &time, int d[], int f[])
{
	color[vertex] = GRAY;
	time = time + 1;
	d[vertex] = time;

	Node *list = G_list[vertex];
	while (list != nullptr) {
		if (color[list->vertex] == WHITE){
			dfs_list(G_list, list->vertex, color, time, d, f);
		}
		list = list->next;
	}

	time = time + 1;
	f[vertex] = time;
	color[vertex] = BLACK;
}


void dfs_visit_matrix(int G[][NUM_OF_VERTICES])
{
	int time = 0;
	int d[NUM_OF_VERTICES], f[NUM_OF_VERTICES];
	COLOR color[] = { WHITE, WHITE, WHITE, WHITE, WHITE };

	for (int i = 0; i < NUM_OF_VERTICES; i++){
		if (color[i] == WHITE) {
			dfs_matrix(G, i, color, time, d, f);
		}
	}

	for (int i = 0; i < NUM_OF_VERTICES; i++){
		std::cout << "Vertex " << i << ", discovery time: " << d[i] << ", finish time: " << f[i] << std::endl;
	}

}


void dfs_visit_list(Node *G_list[NUM_OF_VERTICES])
{
	int time = 0;
	int d[NUM_OF_VERTICES], f[NUM_OF_VERTICES];
	COLOR color[] = { WHITE, WHITE, WHITE, WHITE, WHITE };

	for (int i = 0; i < NUM_OF_VERTICES; i++){
		color[i] = WHITE;
	}

	for (int i = 0; i < NUM_OF_VERTICES; i++){
		if (color[i] == WHITE) {
			dfs_list(G_list, i, color, time, d, f);
		}
	}

	for (int i = 0; i < NUM_OF_VERTICES; i++){
		std::cout << "Vertex " << i << ", discovery time: " << d[i] << ", finish time: " << f[i] << std::endl;
	}
}


void dfs_visit(int G[][NUM_OF_VERTICES], Node *G_list[NUM_OF_VERTICES])
{
	std::cout << "\n----------- dfs matrix visit -------------" << std::endl;
	dfs_visit_matrix(G);

	std::cout << "\n----------- dfs list visit -------------" << std::endl;
	dfs_visit_list(G_list);
}


