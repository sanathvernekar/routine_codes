#include<bits/stdc++.h>
#define ll long long int 
#define mod 1000000007
using namespace std;
ll sum_of_all_digits_of_array(ll a[], ll n){
    ll sum=0;
    ll i;
    register ll temp;
	for(i=0;i<n;i++){
	   temp=a[i];
	   while(temp>0){
	         sum+=(temp%10);
	         temp=temp/10;
	        }
	   }
	   return sum;
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	    {
	        ll sum=0,n,i;
	        cin>>n;
	        ll a[n];
	        for(i=0;i<n;i++)cin>>a[i];
	        sum=sum_of_all_digits_of_array(a,n);
	        if(sum%3==0)cout<<"1"<<endl;
	        else cout<<"0"<<endl;
	    }
    return 0;
}
