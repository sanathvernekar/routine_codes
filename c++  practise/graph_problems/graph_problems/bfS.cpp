#include <bits/stdc++.h>

using namespace std;

#define ipair pair<int,int>
#define W 6

class Graph{
private:
    int V;
    vector<ipair> *adjL;
    vector<bool> visited;
    vector<int> distFromSrc;
    
public:
    Graph(int V);
    void addEdge(int src,int dest);
    void BFS(int src); 
};

Graph::Graph(int V){
    this->V = V;
    adjL = new vector<ipair>[V];
    visited = vector<bool>(V,false);
    distFromSrc = vector<int>(V,-1);
}

void Graph::addEdge(int src,int dest){
    adjL[src].push_back(make_pair(dest,W));
    adjL[dest].push_back(make_pair(src,W));
}

void Graph::BFS(int src){
    distFromSrc[src] = 0;
    queue<int> q;
    q.push(src);
    visited[src] = true;
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto &x : adjL[u]){
            int v = x.first;
            if(!visited[v] && (distFromSrc[v] == -1 || distFromSrc[u] + W < distFromSrc[v])){
                visited[v] = true;
                distFromSrc[v] = distFromSrc[u] + W;
                q.push(v);
            } 
        }
    }
    for(int i = 1; i < V; i++){
        if(i == src)
            continue;
        cout<<distFromSrc[i]<<" ";   
    }
    cout<<endl;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        int m;
        cin >> n >> m;
        Graph g(n+1);
        for(int a1 = 0; a1 < m; a1++){
            int u;
            int v;
            cin >> u >> v;
            g.addEdge(u,v);
        }
        int s;
        cin >> s;
        g.BFS(s);
    }
    return 0;
}
