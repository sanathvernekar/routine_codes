#include<bits/stdc++.h>
using namespace std;
int maxLen(int A[],int n);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        cout<<maxLen(A,N)<<endl;
    }
}



//the major concept here is if sum is 15 somewhere,after moving frward with
//i if we found 15 again,so there must be a subarray between pervious 15 and current 15 whose sum is 0; 

int maxLen(int A[],int n)
{
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

