using namespace std;
#include<iostream>
#include<climits>  
#define size 9


int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;
	for (int i = 0; i < size; i++)
		if (sptSet[i] == false && dist[i] <= min)
			min = dist[i], min_index = i;
	return min_index;
}


void printPath(int parent[], int j)
{
	if (parent[j] == -1)
		return;
	printPath(parent, parent[j]);
	cout << j << " ";
}


void printSolution(int dist[], int n, int parent[])
{
	int src = 0;
	cout << "Vertex\t Distance\tPath";
	for (int i = 1; i < size; i++) {
		printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i],src);
		printPath(parent, i);
	}
}


void dijkstra(int graph[size][size], int src)
{
	int dist[size];
	bool sptSet[size] = { false };
	int parent[size] = { -1 };
	for (int i = 0; i < size; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;
	for (int count = 0; count < size - 1; count++) {
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < size; v++)
			if (!sptSet[v] && graph[u][v]
				&& dist[u] + graph[u][v] < dist[v]) {
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
	}
	printSolution(dist, size, parent);
}


int main()
{
	int graph[size][size] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 19, 0, 0, 0 },
						{ 0, 0, 4, 0, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 14, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
	dijkstra(graph, 0);
	return 0;
}
