#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct Edge
{
    int source, destination, weight;
};

struct Graph
{
    int n, E;
    struct Edge* edge;
};

struct Graph* createGraph(int n, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph));
    graph->n = n;
    graph->E = E;
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
    return graph;
}

void mindist(int dist[], int n)
{
    int i;
    printf("\nVertex\tDistance from Source Vertex\n");
    for (i = 0; i < n; ++i)
	printf("%d \t\t %d\n", i, dist[i]);
}

void bellman(struct Graph* graph, int source)
{
    int n = graph->n;
    int E = graph->E;
    int dist[50];
    int i,j,u,v,weight;
    for (i = 0; i < n; i++)
	dist[i] = 50;
    dist[source] = 0;

    for (i = 1; i <= n - 1; i++)
    {
	for (j = 0; j < E; j++)
	{
	    u = graph->edge[j].source;
	    v = graph->edge[j].destination;
	    weight = graph->edge[j].weight;
	    if (dist[u] + weight < dist[v])
		dist[v] = dist[u] + weight;
	}
    }

    for (i = 0; i < E; i++)
    {
	u = graph->edge[i].source;
	v = graph->edge[i].destination;
	weight = graph->edge[i].weight;
	if (dist[u] + weight < dist[v])
	    printf("This graph contains negative edge cycle\n");
    }

    mindist(dist, n);
    return;
}

int main()
{
    int i, n, E, source;
    struct Graph* graph = createGraph(n, E);
    clrscr();
    printf("Enter number of vertices in graph: ");
    scanf("%d",&n);

    printf("Enter number of edges in graph: ");
    scanf("%d",&E);

    printf("Enter your source vertex number: ");
    scanf("%d",&source);

    printf("\nEnter edge properties:  source, destination, weight: \n");
    for(i = 0; i < E; i++)
    {
	scanf("%d",&graph->edge[i].source);
	scanf("%d",&graph->edge[i].destination);
	scanf("%d",&graph->edge[i].weight);
    }
    bellman(graph, source);
    getch();
    return 0;
}