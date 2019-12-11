#include<bits/stdc++.h>

using namespace std;

long long int kprime(long long int n, long long int k){
    long long int kmax=1;
    long long int kt=0;
    
    if(n%2==0){
        kt=kt+1;
        if(kt==k)return 2;
    }
    while(n%2==0){
        n=n/2;
    }
    long long int prev=2;
    for(int i=3;i<=sqrt(n);i=i+2){
        while(n%i==0){
            if(prev!=i){
                prev=i;
                kt=kt+1;
                if(kt==k)return i;
            }
            n=n/i;
        }
    }
    if(n>2){
        kt=kt+1;
        if(kt==k)return n;
    }
    else return -1;
    
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	    {
	        long long int n,k;
	        cin>>n>>k;
	        cout<<kprime(n,k);
	        cout<<endl;
	    }
    return 0;
}
