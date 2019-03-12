/*
[1] (Directed Graph, Programming) Write a C++ program to compute the longest path of a dag. As always, we 
are looking for the most efficient way. Please state the complexity of your algorithm.
*/

#include "Header.h"


void ListRepresentationOfGraph(int G[][NUM_OF_VERTICES], Node *G_list[NUM_OF_VERTICES])
{
	bool flag;
	Node *head;

	for (int i = 0; i < NUM_OF_VERTICES; i++){
		flag = 1;
		for (int j = 0; j < NUM_OF_VERTICES; j++){
			if (G[i][j] != 0 && G[i][j] != INF){
				Node *node = new Node;
				node->vertex = j;
				node->next = nullptr;

				if (flag){
					G_list[i] = node;
					head = node;
					flag = 0;
				}
				else{
					head->next = node;
					head = head->next;
				}
			}
		}
	}

	// Print Graph
	for (int i = 0; i < NUM_OF_VERTICES; i++){
		head = G_list[i];
		std::cout << i << ": ";
		while (head != nullptr){
			std::cout << head->vertex << "->";
			head = head->next;
		}
		std::cout << std::endl;
	}
}




/*
void longest_path_matrix(int G[][NUM_OF_VERTICES], int vertex, COLOR color[], int &distance, int &max)
{
	color[vertex] = GRAY;
	distance = distance + 1;

	for (int i = 0; i < NUM_OF_VERTICES; i++){
		if (G[vertex][i]){
			if (color[i] == WHITE){
				longest_path_matrix(G, i, color, distance, max);
			}
		}
	}

	if (max < distance){
		max = distance;
	}

	std::cout << "vertex: " << vertex+1 << ", distance: " << distance << ", max: " << max << std::endl;

	distance = distance - 1;
}



void longest_path(Node *G_list[], int vertex, COLOR color[], int &distance, int &max)
{
	color[vertex] = GRAY;
	distance = distance + 1;

	Node *list = G_list[vertex];
	while (list != nullptr) {
		if (color[list->vertex] == WHITE){
			longest_path(G_list, list->vertex, color, distance, max);
		}
		list = list->next;
	}

	if (max < distance){
		max = distance;
	}

	std::cout << "vertex: " << vertex + 1 << ", distance: " << distance << ", max: " << max << std::endl;

	distance = distance - 1;
}
*/

void dfs_visit(int G[][NUM_OF_VERTICES], Node *G_list[NUM_OF_VERTICES]);
void dijkstra_shortest_path(int G[][NUM_OF_VERTICES], Node *G_list[NUM_OF_VERTICES]);
void FloydAllPairLongestPath();
void all_pair_longest_path();


int main()
{

	all_pair_longest_path();

	/*
	int G[][5] = {
		{ 0, 10, INF, 30, 100 },
		{ INF, 0, 50, INF, INF },
		{ INF, INF, 0, INF, 10 },
		{ INF, INF, 20, 0, 80 },
		{ INF, INF, INF, INF, 0 }
	};

	Node *G_list[NUM_OF_VERTICES] = { nullptr, nullptr, nullptr, nullptr, nullptr };
	
	std::cout << "------------ dfs list representation ------------ " << std::endl;
	ListRepresentationOfGraph(G, G_list);

//	dfs_visit(G, G_list);
	
	dijkstra_shortest_path(G, G_list);

	//FloydAllPairLongestPath();
	
	/*
	std::cout << std::endl;

	int time = 0;
	int d[NUM_OF_VERTICES], f[NUM_OF_VERTICES];

	int G[][5] = { 
		{ 0, 1, 1, 0, 0 },
		{ 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 1, 1 },
		{ 0, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 0}
	};

	COLOR color[] = { WHITE, WHITE, WHITE, WHITE, WHITE };


	//----------------------- Max distance -------------------------

	int distance = -1, max_len = 0;
	for (int i = 0; i < NUM_OF_VERTICES; i++){
		color[i] = WHITE;
	}

	for (int i = 0; i < NUM_OF_VERTICES; i++){
		if (color[i] == WHITE) {
			longest_path_matrix(G, i, color, distance, max_len);
		}
	}

	std::cout << "Longest path length: " << max_len << std::endl;




	// ----------------------- Longest length using list representation of Graph -----------------------


	distance = -1; max_len = 0;
	for (int i = 0; i < NUM_OF_VERTICES; i++){
		color[i] = WHITE;
	}

	for (int i = 0; i < NUM_OF_VERTICES; i++){
		if (color[i] == WHITE) {
			longest_path(G_list, i, color, distance, max_len);
		}
	}

	std::cout << "Longest path length: " << max_len << std::endl;
	*/

	return 0;
}

