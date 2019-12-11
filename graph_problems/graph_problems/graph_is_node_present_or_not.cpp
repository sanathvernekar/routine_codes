# graph representation in Matrix form 
#graph traversal 
#BFS or DFS
#breadth first search or depth first search 

#depending on the situation of the search algorithm
#include <iostream>

    using namespace std;

    //bool A[100][100];

    
    int main()
    {
        int x, y, nodes, edges,query,a_new,b_new;
        //initialize();       //Since there is no edge initially
        cin >> nodes;       //Number of nodes
        cin >> edges;       //Number of edges
        bool A[nodes][nodes];
        for (int i=0;i<nodes;++i)
        {
            for (int j=0;j<nodes;++j)
            {
                A[i][j]=false;
            }
        }
        for(int i = 0;i < edges;++i)
        {
            cin >> x >> y;
            A[x][y] = true;     //Mark the edges from vertex x to vertex y
       }
       cin>>query;
       for (int k=0;k<query;k++)
       {
           cin>>a_new>>b_new;
           //cout<<a_new<<b_new;
           if(A[a_new][b_new]==true)
           {
               cout<<"YES"<<endl;
           }
           else
           {
               cout<<"NO"<<endl;
           }
       }
      return 0;
    }
