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
inline void swap(ll *x,ll *y){ll tmp=*x;*x=*y;*y=tmp;}

vector<long long int> prime_factors(long long int n,ll mynum, ll rem){
    ll pos=mynum*mynum;
    vector<long long int> prime_factor_list;
    if(n%2==0){
        if(pos%2==rem)prime_factor_list.push_back(2);
    }
    while(n%2==0){
        n=n/2;
    }
    for(int i=3;i<=sqrt(n);i=i+2){
        while(n%i==0){
            if(pos%i==rem)prime_factor_list.push_back(i);
            n=n/i;
        }
    }
    if(n>2){
        if(pos%n==rem)prime_factor_list.push_back(n);
    }
    return prime_factor_list;
}

int main()
{
	string y;
	tc{
	    ll mynum=31623;
	    ll rem;
	    cout<<"1"<<" "<<mynum<<endl;
	    fflush(stdout);
	    cin>>rem;
	    ll val=(mynum*mynum)-rem;
	    vector<ll>plist=prime_factors(val,mynum,rem);
	    //sort(plist.begin(),plist.end(),greater<ll>());
        ll snum=10000007;
        ll rem2;
        cout<<1<<" "<<snum<<endl;
        fflush(stdout);
        cin>>rem2;
        ll calc=(snum*snum);
        vector<ll>final;
        for(ll ele : plist){
            if(calc % ele ==rem2){
                final.push_back(ele);
                break;
            }
        }
        if(final.size()==1){
            cout<<"2"<<" "<<final[0]<<endl;
            fflush(stdout);
            cin>>y;
        }
        else if(final.size()>1)cerr<<"wrong approach"<<endl;
        if(y=="NO")return 0;
        
	}
return 0;
}