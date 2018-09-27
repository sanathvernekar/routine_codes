#include<bits/stdc++.h>
//to find largest prime factors of a given number and if required 
//return the list of all prime factors of a given number 
using namespace std;


vector<long long int> prime_factors(long long int n){
    long long int max=1;
    vector<long long int> prime_factor_list;
    if(n%2==0)max=2;
    while(n%2==0){
        prime_factor_list.push_back(2);
        n=n/2;
    }
    for(int i=3;i<=sqrt(n);i=i+2){
        while(n%i==0){
            prime_factor_list.push_back(i);
            if(i>max)max=i;
            n=n/i;
        }
    }
    if(n>2){
        if(n>max)max=n;
        prime_factor_list.push_back(n);
    }
    cout<<max<<endl;
    return prime_factor_list;
    
        
}

int main()
 {
     int t;
	cin>>t;
	while(t--)
	    {
	        long long int n;
	        cin>>n;
	        vector<long long int> result;
	        result=prime_factors(n);
	        
	    }
    return 0;
}
