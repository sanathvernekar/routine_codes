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
#define mx 100001
pair<ll , pair<ll,ll>>graph[mx];
ll id[mx];
void initialise(){
    for(ll i=0;i<mx;i++)id[i]=i;
}
ll root(ll x){
    while(id[x]!=x){
        id[x]=id[id[x]];
        x=id[x];
    }
    return x;
}
void union1(ll x, ll y){
    ll p=root(x);
    ll q=root(y);
    id[p]=id[q];
}
long long int kruskal(int e, int v, pair<ll , pair<ll,ll>>graph[]){
    ll mincost=0;
    ll cost,st,en;
    for(ll i=0;i<e;i++){
        st=graph[i].second.first;
        en=graph[i].second.second;
        cost=graph[i].first;
        if(root(st)!=root(en)){
            mincost+=cost;
            union1(st,en);
        }
    }
    return mincost;
}
int main()
{
	initialise();
	ll e,v,w,st,en;
	cin>>v>>e;
	for(ll i=0;i<e;i++){
	    cin>>st>>en>>w;
	    graph[i]=make_pair(w,make_pair(st,en));
	}
	sort(graph,graph+e);
	ll minimumcost=kruskal(e,v,graph);
	cout<<minimumcost<<endl;

return 0;
}
