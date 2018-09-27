#include <stdio.h>
#include <limits.h>



int minDistance(int dist[], bool sptSet[],int mx)
{
int min = INT_MAX, min_index;

for (int v = 0; v < mx; v++)
	if (sptSet[v] == false && dist[v] <= min)
		min = dist[v], min_index = v;

return min_index;
}
int printSolution(int dist[], int n,int mx)
{
printf("mxertex Distance from Source\n");
for (int i = 0; i < mx; i++)
	printf("%d tt %d\n", i, dist[i]);
}
void dijkstra(int **graph, int src,int mx)
{
	int dist[mx];
	bool sptSet[mx];
	for (int i = 0; i < mx; i++)
		dist[i] = INT_MAX, sptSet[i] = false;
	dist[src] = 0;
	for (int count = 0; count < mx-1; count++)
	{
	int u = minDistance(dist, sptSet,mx);
	sptSet[u] = true;
	for (int v = 0; v < mx; v++)
		if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
									&& dist[u]+graph[u][v] < dist[v])
			dist[v] = dist[u] + graph[u][v];
	}
	printSolution(dist, mx,mx);
}

int main()
{
int mx=9;
int graph[mx][mx] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
					{4, 0, 8, 0, 0, 0, 0, 11, 0},
					{0, 8, 0, 7, 0, 4, 0, 0, 2},
					{0, 0, 7, 0, 9, 14, 0, 0, 0},
					{0, 0, 0, 9, 0, 10, 0, 0, 0},
					{0, 0, 4, 14, 10, 0, 2, 0, 0},
					{0, 0, 0, 0, 0, 2, 0, 1, 6},
					{8, 11, 0, 0, 0, 0, 1, 0, 7},
					{0, 0, 2, 0, 0, 0, 6, 7, 0}
					};

	dijkstra(graph, 3,mx);

	return 0;
}

