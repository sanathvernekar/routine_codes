#include<bits/stdc++.h>
#define ll long long int 
#define mod 1000000007
using namespace std;
bool isSubsetSum(ll arr[], ll n, ll sum) 
{ 
    // The value of subset[i%2][j] will be true  
    // if there exists a subset of sum j in  
    // arr[0, 1, ...., i-1] 
    bool subset[2][sum + 1]; 
  
    for (ll i = 0; i <= n; i++) { 
        for (ll j = 0; j <= sum; j++) { 
  
            // A subset with sum 0 is always possible  
            if (j == 0) 
                subset[i % 2][j] = true;  
  
            // If there exists no element no sum  
            // is possible  
            else if (i == 0) 
                subset[i % 2][j] = false;  
            else if (arr[i - 1] <= j) 
                subset[i % 2][j] = subset[(i + 1) % 2] 
             [j - arr[i - 1]] || subset[(i + 1) % 2][j]; 
            else
                subset[i % 2][j] = subset[(i + 1) % 2][j]; 
        } 
    } 
  
    return subset[n % 2][sum]; 
} 
int main()
 {
	ll t;
	cin>>t;
	while(t--)
	    {
	        ll n;
	        cin>>n;
	        ll a[n],i,sum=0;
	        for(i=0;i<n;i++){cin>>a[i];sum+=a[i];}
	        //cout<<sum<<endl;
	        if(n==1)cout<<"NO"<<endl;
	        else if(sum%2==1)cout<<"NO"<<endl;
	        else{
	            
	            sum=sum/2;
	            /*
	            ll local_sum=0;
	            sort(a,a+n);
	            for(i=0;i<n;i++)cout<<a[i]<<" ";
	            cout<<endl;
	            i=0;
	            while(i<n && local_sum<sum ){
	                local_sum+=a[i];
	                i++;
	            }
	            if(local_sum==sum)
	            */if(isSubsetSum(a,n,sum)==true)
	            cout<<"YES"<<endl;
	            else cout<<"NO"<<endl;
	        }
	    }
    return 0;
}
