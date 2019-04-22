#include <iostream>
#include<bits/stdc++.h>
using namespace std;

long long int  divisors(long long int n) 
{ 
    long long int count=0;
    for (long long int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i) 
                count=count+1; 
            else 
                count=count+2;
        } 
    }
    return count;
} 

int main() {
	long long int n;
	cin>>n;
	if(n==1)cout<<1;
	else{
	    cout<<divisors(n)<<endl;
	}
	
	return 0;
}