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
vector<int>adj[100001];
vector<bool>visited(100001,false);
int soldiers[100001];
int csol=0;
int totalkilled=0;
int totalsoldiers=0;
int injuredsoldiers=0;
vector<int >ktent;

void dfs(int s,int n){
    int max=INT_MIN;
    vector<int>here;
    int maxid=0;
    stack<int>stk;
    stk.push(s);
    while(!stk.empty()){
        s=stk.top();
        stk.pop();
        if(visited[s]==false){
            visited[s]=true;
            here.push_back(s);
            //if(soldiers[s]>max){max=soldiers[s];maxid=s;}
        }
        for ( int  ele : adj[s]){
            if(visited[ele]==false){
                stk.push(ele);
            }
        }
    }
    sort(here.begin(),here.end());
    for(int val : here){
        if(soldiers[val]>max){
            max=soldiers[val];
            maxid=val;
        }
    }
    totalkilled+=max;
    injuredsoldiers-=max;
    ktent.push_back(maxid);
    
}

int main()
{
	FIO
	{
        int n,m;
        cin>>n>>m;
        
        for(int i=1;i<=n;i++){cin>>soldiers[i];injuredsoldiers+=soldiers[i];}
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=1;i<=n;i++){
            if(visited[i]==false){
                dfs(i,n);
            }
        }
        cout<<totalkilled<<" "<<injuredsoldiers<<endl;
        sort(ktent.begin(),ktent.end());
        for(int e: ktent){
            cout<<e<<" ";
        }
        cout<<endl;

    }


return 0;
}
