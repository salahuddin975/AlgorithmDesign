#include <iostream>
#include <limits.h>
#include <list>
#include <stack>

#define NEG_INF INT_MIN
#define NUM_OF_NODE 5

using namespace std;

struct Node {
	int v;
	int weight;
};


void add_edge(list<Node> *G, int u, int v, int weight)
{
	Node node;
	node.v = v;
	node.weight = weight;

	G[u].push_back(node);
}

void topological_sort(list<Node> *G, int v, bool visited[], stack<int> &stk)
{
	visited[v] = true;

	list<Node>::iterator it;

	for (it = G[v].begin(); it != G[v].end(); ++it) {
		Node node = *it;

		if (!visited[node.v]){
			topological_sort(G, node.v, visited, stk);
		}
	}

	stk.push(v);
}


int longest_path(list<Node> *G, int source, stack<int> stk, int dist[], int &pos, int prnt[][NUM_OF_NODE])
{
	int max_len = NEG_INF;

	dist[source] = 0;
	list<Node>::iterator it;

	while (stk.empty() == false)
	{
		int u = stk.top();
		stk.pop();

		if (dist[u] != NEG_INF)
		{
			for (it = G[u].begin(); it != G[u].end(); ++it){
				if (dist[it->v] < dist[u] + it->weight){
					dist[it->v] = dist[u] + it->weight;
					prnt[source][it->v] = u;
				}
			}
		}
	}

	for (int i = 0; i < NUM_OF_NODE; i++){
		if (max_len < dist[i]){
			max_len = dist[i];
			pos = i;
		}
	}

	return max_len;
}


void print_path(int prnt[][NUM_OF_NODE], int source, int dest)
{
	std::stack<int> st;
	while (source != dest){
		st.push(dest);
		dest = prnt[source][dest];
	}
	st.push(source);

	while (!st.empty()){
		std::cout << st.top() << "->";
		st.pop();
	}
	std::cout << std::endl;
}


void find_longest_path(list<Node> *G)
{
	stack<int> stk;
	int dist[NUM_OF_NODE];
	bool visited[NUM_OF_NODE];

	for (int i = 0; i < NUM_OF_NODE; i++){
		visited[i] = false;
	}

	for (int i = 0; i < NUM_OF_NODE; i++){
		if (visited[i] == false)
			topological_sort(G, i, visited, stk);
	}


	int len, source, dest, pos;
	int max_len = NEG_INF;
	int prnt[NUM_OF_NODE][NUM_OF_NODE];

	for (int i = 0; i < NUM_OF_NODE; i++){
		for (int j = 0; j < NUM_OF_NODE; j++){
			prnt[i][j] = i;
		}
	}

	for (int i = 0; i < NUM_OF_NODE; i++)
	{
		for (int i = 0; i < NUM_OF_NODE; i++){
			dist[i] = NEG_INF;
		}

		int len = longest_path(G, i, stk, dist, pos, prnt);

//		std::cout << "source: " << i << ", len: " << len << std::endl;

		if (max_len < len){
			max_len = len;
			source = i;
			dest = pos;
		}
	}

	std::cout << "Longest path len: " << max_len << std::endl;

	std::cout << "Path: ";
	print_path(prnt, source, dest);
}

int main()
{
	list<Node>* G;
	G = new list<Node>[NUM_OF_NODE];

	add_edge(G, 0, 1, 10);
	add_edge(G, 0, 3, 30);
	add_edge(G, 0, 4, 100);
	add_edge(G, 1, 2, 150);
	add_edge(G, 3, 2, -10);
	add_edge(G, 2, 4, 10);
	add_edge(G, 3, 2, 20);
	add_edge(G, 3, 4, 60);

	find_longest_path(G);

    return 0;
}
