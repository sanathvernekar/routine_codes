#include <iostream>
#include<bits/stdc++.h>
using namespace std;



int main() {
	long long int n,m,k,l,res;
	cin>>n>>m>>k>>l;
	if(n<m)cout<<"-1"<<endl;
	else{
	    res=n/m;
	    if(((res*m)-k)<l){
	        cout<<"-1"<<endl;
	    }
	    else{
	        cout<<res<<endl;
	    }
	}
	
	return 0;
}