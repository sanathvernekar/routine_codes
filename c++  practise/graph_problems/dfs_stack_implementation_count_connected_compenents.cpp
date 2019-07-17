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
//dfs implementation using stack 
// return number of connected nodes for the given node 

vector<int>adj[100001];
vector<bool>visited(100001,false);
int ans=0;
void  dfs(int s) {
        stack<int>stk;
        stk.push(s);
        while(!stk.empty()){
            s=stk.top();
            stk.pop();
            if(!visited[s]){
                cout<<s<<" ";
                visited[s]=true;
                ans++;
            }
            //in this case  while iterating a vector list use auto operator to iterate through all the elements
            //and as well as if you use auto use *iterator name while accessing that 
            // else use directly for(int iterator_name : adj[s]) to access the elements in the list seperately
            
            for(auto i=adj[s].begin();i!=adj[s].end();++i){
            //for(int  i : adj[s]){
                if(visited[*i]==false){
                    stk.push(*i);
                }
            }
        }
        
}
int main()
{
	int n,m;
	int count=0;
	cin>>n>>m;
	int u,v;
	for(int i=0;i<m;i++){
	    cin>>u>>v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
	int x;
	cin>>x;
	dfs(x);
	cout<<n-ans<<endl;

return 0;
}
