#include <iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long int 
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
vector<int>adj[200001];
int max_depth=0;
vector<bool>visited(200001,false);
int dist[200001];
ll a[200001];
vector<ll>lvl[200001];
void  bfs(int s) {
        dist[1]=0;
        queue<int>q;
        q.push(s);
        lvl[0].push_back(a[s]);
        visited[s]=true;
        while(!q.empty()){
            s=q.front();
            q.pop();
            //for(auto i=adj[s].begin();i!=adj[s].end();++i){
            for(int  i : adj[s]){
                if(visited[i]==false){
                    q.push(i);
                    visited[i]=true;
                    dist[i]=dist[s]+1;
                    lvl[dist[i]].push_back(a[i]);
                    if(dist[i]>max_depth)max_depth=dist[i];
                }
            }
        }
        
}
int main()
{
    FIO;
	int n,m;
	int count=0;
	int q;
	cin>>n;
	int u,v;
	//for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<n-1;i++){
	    cin>>u>>v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
	bfs(1);
	cin>>q;
	cout<<lvl[q-1].size()<<endl;
	//for(int i=0;i<=max_depth;i++){
	  //  sort(lvl[i].begin(),lvl[i].end());
	    /*for(int ele:lvl[i]){
	        cout<<ele<<" ";
	    }
	    cout<<endl;
	    */
	//}
	/*
	int level;
	ll x;
    while(q--){
        cin>>level>>x;
        level=level%(max_depth+1);
        ll ans=-1;
        for(ll ele : lvl[level]){
            if(ele >=x){
                ans=ele;
                break;
            }
        }
        cout<<ans<<endl;
    }
    */

return 0;
}
