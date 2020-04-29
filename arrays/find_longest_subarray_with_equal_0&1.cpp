// find longest subarray with equal zero and one's 
#include <bits/stdc++.h>
using namespace std;
int maxLen(int arr[], int n);
int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		cout<<maxLen(a,n)<<endl;
		
	}
	return 0;
}

int maxLen(int A[],int n)
{
    for(int i=0;i<n;i++)if(A[i]==0)A[i]=-1;
    map<int,int>m;
    int sum=0,len=0;
    //m[0]=-1;
    for(int i=0;i<n;i++){
        sum+=A[i];
        if(A[i]==0 && len==0)len=1;
        if(sum==0)len=i+1;
        if(m.find(sum)!=m.end()){
            len=max(len,i-m[sum]);
        }
        else m[sum]=i;
    }
    return len;
    
}

