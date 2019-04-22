#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
const int MOD=1e9+7;
const int N = 1e5+5;
bool vis[N]={false};
vector<int> adj[N];
int a[N];
int x;
int dfs(int i){
    vis[i]=true;
    int s=a[i];
    for(auto x:adj[i]){
        if(!vis[x]){
            s+=dfs(x);
        }
    }
    //cerr<<i+1<<" "<<max(s,-x)<<endl;
    return max(s,-x);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n>>x;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout<<dfs(0)<<endl;
        x=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<N;i++){
            adj[i].clear();
        }
    }
    return 0;
    
}


