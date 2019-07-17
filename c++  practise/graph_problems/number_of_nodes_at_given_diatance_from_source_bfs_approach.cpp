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
 
#define loop(x,k,n) for(int x = k; x < n; x++)     
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
inline ll sumofdigits(ll n){ll res=0;for (res = 0; n > 0;res += n % 10, n /= 10);return res;}
inline ll maxi(ll a, ll b){return a>b?a:b;}
inline ll mini(ll a, ll b){return a<b?a:b;}

vector<int>adj[100001];
int bfs(int s,int d){
    if(d==1)return adj[s].size();
    else {
        int level[100001]={0};
        //vector<int>level[100001];
        int dist[100001]={0};
        bool visited[100001]={false};
        dist[s]=0;
        queue<int>q;
        q.push(s);
        visited[s]=true;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            for(int ele : adj[t]){
                if(!visited[ele]){
                    q.push(ele);
                    visited[ele]=true;
                    dist[ele]=dist[t]+1;
                    level[dist[ele]]+=1;
                    //level[dist[ele]].push_back(ele);
                    
                }
            }
        }
        return level[d];
    }
}
int main()
{
	FIO
	int n,e;
	cin>>n>>e;
	for(int i=0;i<e;i++){
	    int u,v;
	    cin>>u>>v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
	int query;
	cin>>query;
	while(query--){
	    int node,distance;
	    cin>>node>>distance;
	    cout<<bfs(node,distance)<<endl;
	}
	
return 0;
}
