#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	    {
	        int i,j,k,n;
	        cin>>n;
	        int a[n],count[21]={0},res=0,reso=0;
	        for(i=0;i<n;i++){
	            cin>>a[i];
	            count[a[i]]+=1;
	        }
	        if(n==2){
	            for(i=0;i<=20;i++){
	                if(count[i]==1 && count[i-1]==1)cout<<(i+(i-1))<<endl;
	            }
	        }
	        else{
                for(i=20;i>0;i--){
                    if(count[i]>0 && count[i-1]>0){
                        if(count[i]>=count[i-1]){
                            count[i-1]=0;
                        }
                        else count[i-1]-=count[i];
                    } 
                }
                for(i=0;i<21;i++){
                    if(count[i]>0)res+=(i*count[i]);
                }
                cout<<res<<endl;
	        }
	    }
    return 0;
}
