#include <iostream>
#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
vector<long long int> factors(long long int n){
    vector<long long int> factor_list;
    for (ll i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
             
            if (n/i == i) 
                factor_list.push_back(i); 
  
            else{
                factor_list.push_back(i);
                factor_list.push_back(n/i);
            }
        }
    }

    return factor_list;
}
ll  check( ll  a[], ll  n){   
    
    while(--n>0 && a[n]==a[0]);
    return n!=0;
}


int main() {
	
    ll n;
    cin>>n;
    vector<ll>res=factors(n);
    sort(res.begin(),res.end());
    for(ll x:res)cout<<x<<" ";
	return 0;
}