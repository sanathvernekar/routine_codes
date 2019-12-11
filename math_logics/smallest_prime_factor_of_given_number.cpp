#include<bits/stdc++.h>

using namespace std;
long long int smallest_prime(long long int n){
    long long int min=1;
    if(n==1)return 1;
    else if(n%2==0)return 2;
    else {
        for(long long int i=3;i<=sqrt(n);i=i+2){
            if(n%i==0)return i;
        }
    }
    return n;
}
int main()
 {
	int t;
	//cin>>t;
	t=1;
	while(t--)
	    {
	        long long int n;
			n=586;
	        //cin>>n;
	        for(long long int i=1;i<=n;i++){
	            cout<<smallest_prime(i)<<" ";
	        }
	        cout<<endl;
	        
	    }
    return 0;
}
