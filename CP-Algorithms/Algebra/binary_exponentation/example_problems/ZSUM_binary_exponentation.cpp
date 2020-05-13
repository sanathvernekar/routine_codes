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
#define mod 10000007
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
inline void swap(ll *x,ll *y){ll tmp=*x;*x=*y;*y=tmp;}

inline ll binpow(ll a, ll b){
    a=a%mod;
    ll res=1;
    while(b>0){
        if(b & 1 )res=(res*a)%mod;
        a=(a*a)%mod;
        b >>= 1;
    }
    return res;
}


void solve(){
	//your code here
	//Zsum solution for spoj
	while(1){
    	ll n,k;
    	cin>>n>>k;
    	if(n==0 && k==0)break;
    	ll res=(binpow(n,n)+binpow(n,k))%mod;
    	ll res2=(2*binpow((n-1),(n-1)))%mod;
    	ll res3=(2*binpow((n-1),k))%mod;
    	res=(res+res2+res3)%mod;
    	cout<<res<<"\n";
	}
}
int main()
{
	FIO
	{
	    solve();
	}
return 0;
}
