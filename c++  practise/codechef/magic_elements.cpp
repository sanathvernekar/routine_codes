#include<bits/stdc++.h>


using namespace std;


int main(){
    long long  t;
    cin>>t;
    while(t--){
        long long n,k,count=0;
        cin>>n>>k;
        long long a[n];
        long long i;
        long long sum=0;
        for(i=0;i<n;i++){
            cin>>a[i];
            sum=sum+a[i];
        }
        for(int j=0;j<n;j++){
            if((a[j]+k) > (sum-a[j])){
                count=count+1;
            }
        }
        cout<<count<<endl;
        
    }
    
    
    return 0;
}
