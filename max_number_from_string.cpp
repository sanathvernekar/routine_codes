#include<bits/stdc++.h>

using namespace std;
int main()
 {
	long long int i,j,k,n,t,p;
	long long int temp;
	cin>>t;
	while(t--)
	    {
	        
	        string s;
	        cin>>s;
	        long long int len=s.length();
	        vector<long long int>v;
	        long long int dummy;
	        i=0;
	        while(i<len){
	            temp=0;
	            dummy=0;
	            p=1;
	            while(s[i]>='0' && s[i]<='9' && i<len){
	                temp=temp*10;
	                temp=temp+int(s[i]-'0');
	                i++;  
	            }
	            if(temp>0)v.push_back(temp);
	            i++;
	        }
	        long long int max=0;
	        for(i=0;i<v.size();i++){
	            if(v[i]>max)max=v[i];
	        }
	        cout<<max<<endl;
	    }
    return 0;
}
