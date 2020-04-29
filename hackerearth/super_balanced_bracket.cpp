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
inline ll sumofdigits(ll n){ll res=0;for (res = 0; n > 0;res += n % 10, n /= 10);return res;}
inline ll maxi(ll a, ll b){return a>b?a:b;}
inline ll mini(ll a, ll b){return a<b?a:b;}
inline void swap(ll *x,ll *y){ll tmp=*x;*x=*y;*y=tmp;}

int main()
{
	FIO
	{
       tc{
           string s;
           cin>>s;
           int n=s.length();
           int count=0;
           bool high=false;
           bool low=false;
           bool flag=false;
           int l=0;int r=0;
           for(int i=0;i<n;i++){
               if(s[i]=='(' && flag==false){flag=true;l=1;r=0;}
               else if(s[i]=='(' && flag==true){l=l+1;r=0;}
               else if(s[i]==')' && flag==false){l=l-1;r=r+1;
                   if(l<0){l=0;r=0;}
                   if(r>count)count=r;
               }
               else if(s[i]==')' && flag==true){flag=false;l=l-1;r=r+1;if(r>count)count=r;}
               //if(s[i]=='(' && high==false){high=true;low=false;}
           }
           cout<<count*2<<endl;
       }

    }


return 0;
}
