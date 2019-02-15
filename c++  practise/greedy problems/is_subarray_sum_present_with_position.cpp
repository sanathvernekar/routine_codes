#include<bits/stdc++.h>
#define ll long long int 
#define mod 1000000007
using namespace std;

int main()
 {
	ll t;
	cin>>t;
	while(t--)
	    {
	        ll n,s,i;
	        cin>>n>>s;
	        ll a[n];
	        ll l=0,r=0,c=0,sum=0;
	        for(i=0;i<n;i++)cin>>a[i];
	        i=0;
	        bool bk=false;
	        while(r<=n && l<=n){
	            if(sum<s){
	                sum+=a[r];
	                r=r+1;
	            }
	            else if(sum>s){
	                sum-=a[l];
	                l=l+1;
	            }
	            else if(sum==s)break;
	            //i++;
	        }
	        if(r>=n ){
	            while(l<=n && sum>s){
    	                sum-=a[l];
    	                l=l+1;
    	                if(sum==s)break;
	            }
	        }
	        if(l==r)cout<<"-1"<<endl;
	        else
	        cout<<l+1<<" "<<r<<endl;
	    }
    return 0;
}
