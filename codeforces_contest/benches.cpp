#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	long long  sum=0;
	int occupancy=0;
	long long  max=INT_MIN;
	long long  min=INT_MAX;
	cin>>n;
	cin>>m;
	int  a[n]={0};
	for(int i=0;i<n;i++){
	    cin>>a[i];
	    sum=sum+a[i];
	    if(a[i]<min)min=a[i];
	    if(a[i]>max)max=a[i];
	}
	int total=sum+m;
	if(total%n==0){
	    occupancy=total/n;
	    
	}
	else {
	    occupancy=(total/n)+1;
	}
	int res=0;
	if(occupancy>max)res=occupancy;
	else res=max;
	cout<<res<<" "<<max+m;
	return 0;
}
