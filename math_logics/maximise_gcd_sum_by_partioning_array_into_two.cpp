#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define tc int t; cin >> t; while(t--)
inline ll max(ll a, ll b){return a>b?a:b;}
inline ll min(ll a, ll b){return a<b?a:b;}
unsigned int gcd(unsigned int u, unsigned int v)
{
    int shift;
    if (u == 0) return v;
    if (v == 0) return u;
    shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do {
        v >>= __builtin_ctz(v);
        if (u > v) {
            unsigned int t = v;
            v = u;
            u = t;
        }  
        v = v - u;
    } while (v != 0);
    return u << shift;
}

int main()
{
	FIO
	tc{
		set<int>s;
		int n;
		cin>>n;
		int a[n];
		int maxi=INT_MIN;
		int sec_maxi=INT_MIN;
		int mini=INT_MAX;
		for(int i=0;i<n;i++){
		    cin>>a[i];
		    if(a[i]>maxi){sec_maxi=maxi;maxi=a[i];}
		    else if(a[i]>sec_maxi && a[i]!=maxi)sec_maxi=a[i];
		    if(a[i]<mini)mini=a[i];
		    s.insert(a[i]);
		}
		if(sec_maxi==INT_MIN)sec_maxi=maxi;
		if(mini==1){
		    cout<<1+maxi<<endl;
		}
		else if(maxi==mini){
		    cout<<maxi+maxi<<endl;
		}
		else if(s.size()==2){
		    int gcdq=0;
		    for(int ele : s)gcdq+=ele;
		    cout<<gcdq<<endl;
		}
		else {
		    int cmp1=0,cmp2=0;
		    
		    int gcd1,gcd2;
		    s.erase(s.find(maxi));
		    gcd1=mini;
		    for(int i: s){
		        gcd1=gcd(i,gcd1);
		    }
		    cmp1=gcd1+maxi;
		    
            s.erase(s.find(sec_maxi));
		    s.insert(maxi);
		    gcd2=mini;
		    for(int i : s){
		        gcd2=gcd(i,gcd2);
		    }
		    cmp2=gcd2+sec_maxi;
		    
		    if(cmp1>cmp2)cout<<cmp1<<endl;
		    else cout<<cmp2<<endl;
		    
		    
		
	    }
	}



return 0;
}
