#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
int main()
 {
 ios_base::sync_with_stdio(false);
cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    ll  n;
	    cin>>n;
	    ll  a[n];
	    unordered_map<ll , ll > hash;
	    for(ll i=0;i<n;i++){
	        cin>>a[i];
	        hash[a[i]]++;
	    }
         bool flag=false;
	    for(ll i=0;i<n;i++){
	       if(hash[a[i]]==1){
	           cout<<a[i]<<endl;
	           flag=true;
	           break;
	       }
	    }
	    if(flag==false){
	        cout<<"0"<<endl;
	    }
	}
	return 0;
}
