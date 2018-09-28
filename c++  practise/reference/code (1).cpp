#include <iostream>
using namespace std;

struct Node{
    int val,cost;
    Node* next;
};
struct Edge{
    int src,dest,weight;
};


class Graph{
  Node* getAdjList(int value,int weight ,Node* head){
      Node* newnode = new Node;
      newnode->val = value;
      newnode->cost = weight;
      newnode->next = head;
      return newnode;
  }
  
  
  int N;  
  
  public:
  Node **head;
    Graph(Edge edges,int nedges,int vertices){
        head=new Node*[vertices]();
        this->N=vertices;
        
        for(int i=0;i<N;++i)
        head[i]=nullptr;
        
        for(int j=0;j<nedges;++j){
            int src=edges[j].src;
            int dest=edges[j].dest;
            int weight=edges[j].weight;
            
            Node* newnode= getAdjList(dest,weight,head[src]);
            head[j]=newnode;
        }
        
    }
    
    ~Graph() {
		for (int i = 0; i < N; i++)
			delete[] head[i];

		delete[] head;
	}
};


void printlist(Node* ptr,int src){
    while(ptr!=nullptr){
        cout<<src<<" "<<ptr->val<<" "<<ptr->cost<<" ...";
        ptr=ptr->next;
    }
    cout<<endl;
}

int main() {
    
    int nedges,vertices;
    cin>>vertices>>nedges;
    Edge edges[nedges];
    for(int i=0;i<nedges;i++){
        cin>>edges[i].src>>edges[i].dest>>edges[i].weight;
    }
    Graph graph(edges,nedges,vertices);
    for(int j=0;j<vertices;j++){
        printlist(Graph.head[j],j);
    }
	
	return 0;
}