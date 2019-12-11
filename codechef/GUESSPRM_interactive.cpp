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
#include <time.h> 

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
inline ll Random(ll lower, ll upper) {ll num = (rand() % (upper - lower + 1)) + lower;return num;} 
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
        if(pos%i==rem)prime_factor_list.push_back(i);
        while(n%i==0){
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
	    ll mynum=31623;//or check with 31623 or 31627
	    ll rem;
	    std::vector<ll>::iterator it;
	    cout<<"1"<<" "<<mynum<<endl;
	    fflush(stdout);
	    cin>>rem;
	    ll val1=(mynum*mynum)-rem;
	    vector<ll>plist1=prime_factors(val1,mynum,rem);
	    sort(plist1.begin(),plist1.end());
	    
	    
        ll snum=31627;
        ll chk=snum*snum;
        ll rem2;
        map<ll,ll>m;
        bool flag=false;
        for( ll ele : plist1){
            rem2=chk%ele;
            if(m.find(rem2)==m.end())m[rem2]=ele;
            else {flag=true;break;}
        }
        if(flag==false){
            cout<<1<<" "<<snum<<endl;
            fflush(stdout);
            cin>>rem2;
            cout<<2<<" "<<m[rem2]<<endl;
            fflush(stdout);
            cin>>y;
        }
        else {
            ll fst=plist1[plist1.size()-1];
            for(ll gd=1;gd<fst+1;gd++ )
            {
                snum=gd;
                chk=snum*snum;
                flag=false;
                m.clear();
                for(ll ele : plist1){
                    rem2=chk%ele;
                    if(m.find(rem2)==m.end())m[rem2]=ele;
                    else {flag=true;break;}
                }
                if(flag==false)break;
            }
            cout<<1<<" "<<snum<<endl;
            fflush(stdout);
            cin>>rem2;
            cout<<2<<" "<<m[rem2]<<endl;
            fflush(stdout);
            cin>>y;
        }
        if(y=="No")return 0;
        
	}
return 0;
}
