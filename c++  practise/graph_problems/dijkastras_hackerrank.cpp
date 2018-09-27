#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n,int source, vector<pair<int, int> > G[]) {
    int INF = (int)1e9;
    vector<int> D(n, INF);
    D[source] = 0;
    set<pair<int, int> > Q;
    Q.insert({0,source});
    while(!Q.empty())   {
        auto top = Q.begin();
        int u = top->second;
        Q.erase(top);
        for(auto next: G[u])    {
            int v = next.first, weight = next.second;
            if( D[u] + weight < D[v] ) {
                if(Q.find( {D[v],v})!=Q.end())
                    Q.erase(Q.find( {D[v], v} ));
                D[v] = D[u] + weight;
                Q.insert( {D[v], v} );
            }
        }
    }
    return D;
}

int main(){
    int n,m,s,x,y,z;
    cin>>n>>m>>s; 
    //Input the number of nodes(0 based), number of edges and the source vertex.

    vector<pair<int,int> > *G=new vector<pair<int,int> >[n];
    vector<int>ans;
    for(int i=0;i<m;i++){
        cin>>x>>y>>z; 
        //Input the starting vertex of the edge, the ending vertex and the cost of the edge.
        G[x].push_back(make_pair(y,z));
    }
    ans = dijkstra(n,s,G); //ans has the cost from source to all the vertices.
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}
