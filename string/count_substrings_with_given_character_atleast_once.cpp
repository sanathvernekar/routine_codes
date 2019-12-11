#include <iostream>
#include<bits/stdc++.h>
#include <algorithm>
#include <map>
#include <cstdio>
#include <stack>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <cstring>
#include <utility>
#include <iterator>

using namespace std;
 
#define loop(x,k,n) for(int x = k; x < n; x++)     
#define revLoop(q,w) for (int q = w-1;q>=0 ;q--)
#define ll long long int
#define minMod 10e7+3
#define strInp(a) cin.getline(a,1000);
#define mp(a,b) make_pair(a,b)
#define init(a,n) memset(a,n,sizeof(a));
#define pb(i) push_back(i);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define tc int t; cin >> t; while(t--)
#define arrInp(a,n) for (int i=0;i<n;i++) cin >> a[i]



int main()
{
	FIO
	tc{
	    ll n;
	    cin>>n;
		string s;
		char c;
		cin>>s>>c;
		ll dp[n];
		memset(dp,0LL,sizeof(dp));
		ll i=0,cc=0,prev=-1;
		for(i=0;i<n;i++){
		    if(s[i]==c){
		        cc+=1;
		        dp[i]=(i-prev-1);
		        prev=i;
		    }
		}
		//for (i=0;i<n;i++)cout<<dp[i]<<" ";
		//cout<<endl;
		ll res=0;
		for(i=0;i<n;i++){
		    if(s[i]==c){
		        cc-=1;
		        res+=(n-cc);
		        res+=(dp[i]*(n-i-1-cc));
		    }
		}
		
		cout<<res<<endl;
	}
return 0;
}
