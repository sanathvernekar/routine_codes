#include<bits/stdc++.h>

using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	    {
	        long long int n,k;
	        cin>>n>>k;
	        long long int a[26881];
	        long long int count=0;
	        long long int lmt=sqrt(n);
	        
	        if(sqrt(n)==lmt){
	            a[0]=lmt;
	            count++;
	        }
	        else if(sqrt(n)!=lmt){
	            lmt=lmt+1;
	        }
	        for(long long int i=1;i<lmt;i++){
	            if(n%i==0){
	                a[count]=i;
	                a[count+1]=n/i;
	                count=count+2;
	            }
	        }
	        sort(a,a+count);
	        if(k>count){
	            cout<<-1<<endl;
	        }
	        else{
	            cout<<a[k-1]<<endl;
	        }
	    }
    return 0;
    //31622777 31622776
}
