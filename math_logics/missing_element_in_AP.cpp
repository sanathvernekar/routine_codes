#include<bits/stdc++.h>

using namespace std;
int res(int a[],int n){
    int i,d1,d2,d3,d;;
    if(n==2){
	            return((a[0]+a[1])/2);
	        }
	        else{
	            d1=a[1]-a[0];
	            d2=a[2]-a[1];
	            if(d1==d2){
	                d=d1;
	                for(i=0;i<n;i++){
	                    if(!((a[0]+(i*d))==a[i])){
	                        return(a[0]+(i*d));
	                    }
	                    else{
	                        continue;
	                    }
	                }
	            }
	            else{
	                if((a[0]+(2*d2))==a[1]){
	                    return(a[0]+d2);
	                }
	                else{
	                    return(a[1]+d1);
	                }
	            }
	        }
    
}
int main()
 {
	int i,j,k,t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        int a[n];
	        for(i=0;i<n;i++){
	            cin>>a[i];
	        }
	        cout<<res(a,n)<<endl;
	        
	    }
    return 0;
}
