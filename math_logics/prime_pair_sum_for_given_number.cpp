#include<bits/stdc++.h>

using namespace std;
vector<long long int >prime_pair(long long int n){
    vector<long long int >res;
    long long int lmt=n+1;
    long long int count=0;
    bool primes[lmt];
    memset(primes,true,sizeof(primes));
    for(long long int p=2;p*p<lmt;p++){
        if(primes[p]==true){
            for(long long int i=p*2;i<lmt;i=i+p){
                    primes[i]=false;
                    
            }
        }
    }
    long long int x,y;
    vector<long long int >prime_list;
    for(long long int j=2;j<=lmt;j++){
        if(primes[j]==true){
            prime_list.push_back(j);
            count++;
        }
    }
    x=0;
    y=count-1;
    for(long long int k=0;k<count && x<=y;k++){
        
        if((prime_list[x]+prime_list[y])==n){
            res.push_back(prime_list[x]);
            res.push_back(prime_list[y]);
            return res;
        }
        else if((prime_list[x]+prime_list[y])<n){
            x=x+1;
        }
        else if((prime_list[x]+prime_list[y])>n){
            y=y-1;
        }
    }
    res.push_back(1);
    res.push_back(1);
    return res;
                                                                          
}


int main()
 {
    int t;
	cin>>t;
	while(t--)
	    {
	        long long int n;
	        cin>>n;
	        vector<long long int >res=prime_pair(n);
	        for(auto z:res){
	            cout<<z<<" ";
	        }
	        cout<<endl;
	    }
    return 0;
}
