#include<bits/stdc++.h>
#define ll long long int 
#define mod 1000000007
using namespace std;
ll sum_subsequence(ll a[],ll n){
    ll ans=0;
    for(ll i=0;i<n;i++)ans+=a[i];
    return (ans*pow(2,n-1));
}
int main()
 {
	ll t;
	cin>>t;
	while(t--)
	    {
	        string s;
	        cin>>s;
	        ll a[10000];
	        ll n=s.length();
	        for(ll i=0;i<n;i++)a[i]=(int)s[i]-'0';
	        cout<<sum_subsequence(a,n)<<endl;
	        
	    }
    return 0;
}
