

#include<bits/stdc++.h>
#define ll long long int 
#define mod 1000000007
using namespace std;

int main()
 {
	int t;
	cin>>t;
	while(t--)
	    {
	        ll n;
	        cin>>n;
	        ll a[n];
	        for(ll i=0;i<n;i++)cin>>a[i];
	        ll count=0,sum=0;
	        unordered_map<ll,ll>mp;
	        for(ll i=0;i<n;i++){
	            sum+=a[i];
	            if(sum==0)count+=1;
	            if(mp.find(sum)!=mp.end()){
	                count+=mp[sum];
	            }
	            mp[sum]+=1;
	        }
	        cout<<count<<endl;
	        
	    }
    return 0;
}




/*
#include <bits/stdc++.h>
using namespace std;
int sub(int a[],int n){
    int sum=0,count=0;
    unordered_map<int,int>ump;
    ump[0]++;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(ump.find(sum)!=ump.end()){
                count+=ump[sum];
            }
        ump[sum]++;
    }
    return count;
}
int main() {
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)cin>>a[i];
	    cout<<sub(a,n)<<"\n";
	}
	return 0;
}

*/
