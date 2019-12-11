#include <iostream>
#include<bits/stdc++.h>
#include <algorithm>
#include <map>
#include <cstdio>
#include <stack>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <cstring>
#include <utility>
#include <iterator>
 
using namespace std;
 
#define loop(x,k,n) for(int x = k; x < n; x++)      // i ko 0 se n
#define revLoop(q,w) for (int q = w-1;q>=0 ;q--)
#define ll long long int
#define minMod 10e7+3
#define strInp(a) cin.getline(a,1000);
#define mp(a,b) make_pair(a,b)
#define init(a,n) memset(a,n,sizeof(a));
#define pb(i) push_back(i);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define tc int t; cin >> t; while(t--)
#define arrInp(a,n) for (int i=0;i<n;i++) cin >> a[i]
//bfs implementation using queue
// return number of connected nodes for the given node 

vector<int>adj[100001];
vector<bool>visited(100001,false);
int dist[100001];
void  bfs(int s) {
        dist[1]=-1;
        queue<int>q;
        q.push(s);
        visited[s]=true;
        while(!q.empty()){
            s=q.front();
            q.pop();
            for(auto i=adj[s].begin();i!=adj[s].end();++i){
            //for(int  i : adj[s]){
                if(visited[*i]==false){
                    q.push(*i);
                    visited[*i]=true;
                    dist[*i]=dist[s]+1;
                }
            }
        }
        
}
int main()
{
    FIO;
	int n,m;
	int count=0;
	cin>>n;
	int u,v;
	for(int i=0;i<n-1;i++){
	    cin>>u>>v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
	bfs(1);
	int q,index;
	cin>>q;
	int min=INT_MAX;
    while(q--){
        int a;
        cin>>a;
        if(dist[a]<min){
            min=dist[a];
            index=a;
        }
    }
	cout<<index<<endl;

return 0;
}
