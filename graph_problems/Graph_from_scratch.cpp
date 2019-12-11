#include<iostream>
 
using namespace std;
 
// A structure to represent a node in the adjacency list.
struct node
{
	int data;
	struct node *link;
};
 
// A structure to represent list of vertexes connected to the given vertex.
struct vertexlist
{
	struct node *vlisthead;
};
 
// A structure to maintain the graph vertexes and its connections to other vertexes.
struct Graph
{
	int v;
	struct vertexlist *vl; 
};
/ A function to declare the graph according to the number of vertex.
struct Graph* CreateGraph(int n)
{
	int i;
	struct Graph *vlist = new Graph;
	vlist->v = n;
 
	// declare a list for n vertex.
	vlist->vl = new vertexlist[n+1];
 
	// Assign the head to NULL.
	for(i = 0; i < n+1; i++)
	{
		vlist->vl[i].vlisthead = NULL;
	}
 
	return vlist;
}
 
// A function to create a new data node.
struct node* NewNode(int value)
{
	struct node *newnode = new node;
	newnode->data = value;
	newnode->link = NULL;
 
	return newnode;
}

// A  function to add the edge into the undirected graph.
void InsertNode(Graph *G, int v1, int v2)
{
	node *newnode1 = NewNode(v1);
	node *newnode2 = NewNode(v2);
	node *temp = new node;
	// Since it is undirected graph, count each edge as two connection.
	// Connection 1, v2 to v1.
	if(G->vl[v2].vlisthead == NULL)
	{
		// If the head is null insert the node to the head.
		G->vl[v2].vlisthead = newnode1;
	}
	else
	{
		// Otherwise, add the node at the beginning.
		newnode1->link = G->vl[v2].vlisthead;
		G->vl[v2].vlisthead = newnode1;
	}
	// Connection 2, v1 to v2.
	if(G->vl[v1].vlisthead == NULL)
	{
		// If the head is null insert the node to the head.
		G->vl[v1].vlisthead = newnode2;
	}
	else
	{
		// Otherwise, add the node at the beginning.
		newnode2->link = G->vl[v1].vlisthead;
		G->vl[v1].vlisthead = newnode2;
	}
}
int main()
{
	int i, v, e;
 
	// Take the input of the number of vertex and edges the graph have.
	cout<<"Enter the number of vertexes of the graph: ";
	cin>>v;
	struct Graph *G = CreateGraph(v);
	cout<<"\nEnter the number of edges of the graph: ";
	cin>>e;
	int edge[e][2];
 
	// Take the input of the adjacent vertex pairs of the given graph.
	for(i = 0; i < e; i++)
	{
		cout<<"\nEnter the vertex pair for edge "<<i+1;
		cout<<"\nV(1): ";
		cin>>edge[i][0];
		cout<<"V(2): ";
		cin>>edge[i][1];
 
		InsertNode(G, edge[i][0], edge[i][1]);
	}
 	// Print the incidence list representation of the graph.
	cout<<"\n\nThe incidence list representation for the given graph: ";
	for(i = 0; i < v; i++)
	{
		cout<<"\n\tV("<<i+1<<") -> {  ";
		while(G->vl[i+1].vlisthead != NULL)
		{
			cout<<G->vl[i+1].vlisthead->data<<"  ";
			G->vl[i+1].vlisthead = G->vl[i+1].vlisthead->link;
		}
		cout<<"}";
	}
}
