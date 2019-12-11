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
ll st[1000000];
ll a[1000000];
/*
//inline ll min(ll x ,ll y){return x<y?x:y;}
//inline ll max(ll x,ll y){return x>y?x:y;}
// segment tree point update and Range query 

//whole program is written in 1 based indexing
// either we can declare a global array or a local array and pass it to build and update function 
*/
void build(ll node,ll start,ll end ,ll st[],ll a[] ){
    if(start==end){st[node]=a[start];return ;}
    else{
        ll mid=(start+end)/2;
        build(2*node,start,mid,st,a);
        build(2*node+1,mid+1,end,st,a);
        st[node]=min(st[2*node],st[2*node+1]);
    }
}

void update(ll node,ll start,ll end ,ll idx ,ll val,ll st[]){
    if(start==end){
        st[node]=val;
        return;
    }
    else {
        ll mid=(start+end)/2;
        if(idx>=start && idx<=mid)update(2*node,start,mid,idx,val,st);
        else update(2*node+1,mid+1,end,idx,val,st);
        st[node]=min(st[node*2],st[node*2+1]);
    }
}

ll query(ll node, ll start, ll end, ll l, ll r,ll st[]){
    if(r<start || end<l)return INT_MAX;// here return outof case value 
    if(l<=start && r>=end)return st[node];
    else{
        ll mid=(start+end)/2;
        ll p1=query(2*node,start,mid,l,r,st);
        ll p2=query(2*node+1,mid+1,end,l,r,st);
        return min(p1,p2);
    }
}

int main()
{
	
	ll n,q;
	cin>>n>>q;
	//ll a[n+1],st[2*n+1];
	for(ll i=1;i<=n;i++)cin>>a[i];
	//construct segment tree
	build(1,1,n,st,a);
	while(q--){
	    char w;
	    ll x,y;
	    cin>>w>>x>>y;
	    if(w=='u'){
	        //update segment tree
	        a[x]=y;
	        update(1,1,n,x,y,st);
	        
	    }
	    else if(w=='q'){
	        //Query Segment tree
	        cout<<query(1,1,n,x,y,st)<<endl;
	    }
	}
return 0;
}
