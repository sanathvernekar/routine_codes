#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
 
 
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define tc int t; cin >> t; while(t--)
 
ll prime_factors(long long int n,ll backup){
    ll max=1;
    if(n%2==0)max=2;
    while(n%2==0){
        n >>= 1;
    }
    for(int i=3;i<=sqrt(n);i=i+2){
        while(n%i==0){
            if(i>backup)return i;
            n=n/i;
        }
    }
    if(n>2){
        if(n>max)max=n;
    }
    return max;
}
 
 
int main()
{
	FIO
	tc
	{
       ll n;
       cin>>n;
       ll res=prime_factors((n+1),n);
       //cout<<sum;
       if(n==1)cout<<"YES"<<endl;
       else if(n==2)cout<<"NO"<<endl;
       else if(n==3)cout<<"YES"<<endl;
       else if(res>n)cout<<"NO"<<endl;
       else cout<<"YES"<<endl;
    
    }
return 0;
}
