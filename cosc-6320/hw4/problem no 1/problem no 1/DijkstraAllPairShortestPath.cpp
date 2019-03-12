#include "Header.h"


#define NUM_OF_VERTICES 5


void shortest_path_matrix(int G[][NUM_OF_VERTICES], int source)
{
	int min = INF;
	int min_w;
	int d[NUM_OF_VERTICES];
	std::set<int> S;


	for (int i = 0; i < NUM_OF_VERTICES; i++)
	{
		std::cout << "Source: " << i << std::endl;

		for (int j = 0; j < NUM_OF_VERTICES; j++){
			S.insert(j);
			d[j] = G[i][j];
		}

		while (!S.empty()){
			for (auto w = S.begin(); w != S.end(); w++){      // minimum distance and vertex
				if (min > d[*w]){
					min = d[*w];
					min_w = *w;
				}
			}

//			for (int k = 0; k < NUM_OF_VERTICES; k++)
//				std::cout << d[k] << ", ";
//			std::cout << ", Erase: " << min_w << std::endl;

			S.erase(min_w);

			if (min == INF)
				break;

			for (auto v = S.begin(); v != S.end(); v++){     // calculate new distance
				if (d[*v] > G[min_w][*v] + d[min_w])
					d[*v] = d[min_w] + G[min_w][*v];
			}

			min = INF;
		}

		for (int j = 0; j < NUM_OF_VERTICES; j++){
			if (d[j] != INF)
				std::cout << j << ": " << d[j] << std::endl;
			else
				std::cout << j << ": " << "not reachable!" << std::endl;
		}
	}

}


void dijkstra_shortest_path(int G[][NUM_OF_VERTICES], Node *G_list[NUM_OF_VERTICES])
{

	std::cout << "------------- Dijkstra all pair shortest path ---------------" << std::endl;
	shortest_path_matrix(G, 0);
}
