#include <iostream>


#define NUM_OF_VERTICES 4
#define INF -55555


void FloydAlgorithm(int G[NUM_OF_VERTICES][NUM_OF_VERTICES], int P[][NUM_OF_VERTICES])
{
	for (int i = 0; i < NUM_OF_VERTICES; i++){
		G[i][i] = 0;
	}

	for (int k = 0; k < NUM_OF_VERTICES; k++){
		for (int i = 0; i < NUM_OF_VERTICES; i++){
			for (int j = 0; j < NUM_OF_VERTICES; j++){
				if (G[i][k] + G[k][j] > G[i][j] && i != j){
					G[i][j] = G[i][k] + G[k][j];
					P[i][j] = k;
					std::cout << "K: " << k << "  ";
				}
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}


void PrintPath(int G[][NUM_OF_VERTICES], int P[][NUM_OF_VERTICES], int i, int j)
{
	int k = P[i][j];

//	std::cout << "k: " << k << ", i: " << i << ", j: " << j << std::endl;
	std::cout << k << "  at: " << i << ", " << j << std::endl;

	if (k != -1 && (G[i][k] < G[i][j])){
		PrintPath(G, P, i, k);
	}

	if (k != -1 && (G[k][j] < G[i][j])){
		PrintPath(G, P, k, j);
	}
//	std::cout << k << "  ";

	std::cout << std::endl;
}


void PrintDistance(int G[NUM_OF_VERTICES][NUM_OF_VERTICES], int P[][NUM_OF_VERTICES])
{
	int max = 0, m, n;
	for (int i = 0; i < NUM_OF_VERTICES; i++){
		for (int j = 0; j < NUM_OF_VERTICES; j++){
			std::cout << G[i][j] << "  ";
			
			if (max < G[i][j]){
				max = G[i][j];
				m = i;
				n = j;
			}
		}
		std::cout << std::endl;
	}
	std::cout << "PrintPath: max: " << max << ", m: " << m << ", n: " << n << std::endl;
	PrintPath(G, P, m, n);
}


void FloydAllPairLongestPath()
{
	int P[NUM_OF_VERTICES][NUM_OF_VERTICES] = {
		{ -1, -1, -1, -1 },
		{ -1, -1, -1, -1 },
		{ -1, -1, -1, -1 },
		{ -1, -1, -1, -1 }
	};

	int G[NUM_OF_VERTICES][NUM_OF_VERTICES] = {
		{ 0, 3, INF, 7 },
		{ 8, 0, 2, INF },
		{ 5, INF, 0, 1 },
		{ 2, INF, INF, 0 }
	};

	FloydAlgorithm(G, P);
	PrintDistance(G, P);
}