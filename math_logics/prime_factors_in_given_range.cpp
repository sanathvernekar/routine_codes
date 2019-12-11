#include<bits/stdc++.h>

using namespace std;
vector<long long int > prime_range(long long int a,long long int b)
{
    vector<long long int >prime_range_list;
    long long int lmt=b+1;
    bool primes[lmt];
    memset(primes,true,sizeof(primes));
    for(long long int p=2;p*p<lmt;p++){
        if(primes[p]==true){
            for(long long int i=p*2;i<lmt;i=i+p){
                primes[i]=false;
            }
        }
    }
    long long int start=a;
    if(a==1){
        start=a+1;
    }
    for(long long int x=start;x<lmt;x++){
        if(primes[x]==true){
            prime_range_list.push_back(x);
        }
    }
    return prime_range_list;
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	    {
	        long long int a,b;
	        cin>>a>>b;
	        vector<long long int>res=prime_range(a,b);
	        for(auto y:res){
	            cout<<y<< " ";
	        }
	        cout<<endl;
	    }
    return 0;
}
