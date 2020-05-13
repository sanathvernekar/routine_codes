/*-------------------- Author : Sanath Vernekar  --------------------*/ 
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
#define mod 1000000007
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
inline void swap(ll *x,ll *y){ll tmp=*x;*x=*y;*y=tmp;}
unsigned int gcd(unsigned int u, unsigned int v)
{
    int shift;
    if (u == 0) return v;
    if (v == 0) return u;
    shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do {
        v >>= __builtin_ctz(v);
        if (u > v) {
            unsigned int t = v;
            v = u;
            u = t;
        }  
        v = v - u;
    } while (v != 0);
    return u << shift;
}
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

ll factorial[2000000];
ll max_fact=1;
ll fact(ll x){
    ll i;
    if(x<=max_fact)return factorial[x];
    else{
        for(i=max_fact+1;i<=x;i++)factorial[i]=(factorial[i-1]*i)%mod;
        max_fact=x;
        return factorial[x];
    }
}

int modInverse(int a, int m) 
{ 
	int m0 = m; 
	int y = 0, x = 1; 
	if (m == 1) return 0; 
	while (a > 1) 
	{
		int q = a / m; 
		int t = m; 
		m = a % m, a = t; 
		t = y; 
		y = x - q * y; 
		x = t; 
	}  
	if (x < 0) x += m0; 
	return x; 
} 



void solve(){
	//your code here
}
int main()
{
	FIO
	factorial[0]=1;
	factorial[1]=1;
	tc{
	solve();
	}
return 0;
}
