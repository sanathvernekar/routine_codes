#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int 

ll factorial[2000000];
ll max_fact=1;
ll fact(ll x){
    ll i;
    if(x<=max_fact)return factorial[x];
    else{
        for(i=max_fact+1;i<=x;i++){
            factorial[i]=(factorial[i-1]*i)%mod;
        }
        max_fact=x;
        return factorial[x];
    }
}


int main()
{
	factorial[0]=1;
	factorial[1]=1;
	ll t;
	cin>>t;
	while(t--){
	ll n;
	cin>>n;
	cout<<fact(n)<<endl;

	}

	return 0;
}


