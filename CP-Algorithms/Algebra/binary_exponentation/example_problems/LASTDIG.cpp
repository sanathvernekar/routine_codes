#include<bits/stdc++.h>


using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define tc int t; cin >> t; while(t--)


inline ll binpow(ll a, ll b, ll m){
    a=a%m;
    ll res=1;
    while(b>0){
        if(b & 1 )res=(res*a)%m;
        a=(a*a)%m;
        b >>= 1;
    }
    return res;
}


void solve(){
	//your code here
	ll a,b,m;
	cin>>a>>b;
	cout<<binpow(a,b,10)<<endl;
}
int main()
{
	FIO
	tc{
	    solve();
	}
return 0;
}
