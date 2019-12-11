#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	
	long long min=LONG_MAX;
	long long max=LONG_MIN;
	cin>>n;
	long long a[n];
	for(int i=0;i<n;i++){
	    cin>>a[i];
	    if(a[i]<min)min=a[i];
	    if(a[i]>max)max=a[i];
	}
	int count=max-min+1-n;
	cout<<count<<endl;
	return 0;
}
