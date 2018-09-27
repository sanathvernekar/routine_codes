#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int main(){
    int m,s,x,y,z,n;
    cin>>n>>m>>s; //Input the number of nodes(0 based), number of edges and the source vertex.
    int G[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(i==j)
                G[i][j]=0;
            else
                G[i][j]=INF;
        }

    for(int i=0;i<m;i++){
        cin>>x>>y>>z; //Input the starting vertex of the edge, the ending vertex and the cost of the edge.
        G[x][y]=z;
    }
    //Code for Floyd Warshall which computes all pair shortest path.
    for(int k=0; k<n; k++)  {
        for(int i=0; i<n; i++)  {
          for(int j=0; j<n; j++)  {
            G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
          }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<G[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
