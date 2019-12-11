#include<bits/stdc++.h>
using namespace std;

int main()
 {
	int i,j,k,n,t,temp;
	
	cin>>t;
	
	for(i=0;i<t;i++)
	    {
	        int flag=0;
	        cin>>n;
	        vector <bool> a(101,false);
	        a[0]=true;
	        for(j=0;j<n;j++)
	        {
	            cin>>temp;
	            if(temp>0)a[temp]=true;
	        }
	        for(k=0;k<101;k++){
	            if(a[k]==false){
	                cout<<k<<endl;
	                break;
	            }
	        }
	    }
    return 0;
}
