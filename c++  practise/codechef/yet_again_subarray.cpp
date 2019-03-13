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
	    ll n,k;
	    cin>>n>>k;
	    ll a[n],i,j,m,lcount,l,y,z,slen,f;
	    ll bcount=0;
	    ll mymaxi=-1;
	    ll mymin=2001;
	    ll ifzero[2001]={0};
	    bool flag=false;
	    ll track;
	    //ll s[2001]={0};
	    ll startpoint=2001;
	    bool myflag=false;
	    for(i=0;i<n;i++){cin>>a[i];ifzero[a[i]]+=1;if(a[i]<startpoint)startpoint=a[i];}
	    for(i=startpoint;i<2001;i++){
	        if(ifzero[ifzero[i]]>0){flag=true;break;}
	    }
	    if(flag==false)cout<<0<<endl;
	    else {
	    for(i=0;i<n;i++){
	        ll s[2001]={0};
	        ll distcount=0;
	        mymaxi=-1;
	        mymin=2001;
	        for(j=i;j<n;j++){
	            ll kele=0;
	            slen=(j-i+1);
	            distcount+=1;
	            if(a[j]>mymaxi)mymaxi=a[j];
	            if(a[j]<mymin)mymin=a[j];
	            s[a[j]]+=1;
	            if(s[a[j]]>1)distcount-=1;
	            //find kth element 
	            if (distcount==slen){
	                if(s[1]==1)bcount+=1;
	            }
	            else {
	                if (k>=slen){
	                //calc m
	                if(k%slen==0){
	                    m=k/slen;
	                }
	                else {
	                    m=k/slen;
	                    m+=1;
	                }
	                
	                if(k%slen==0){
	                    if(s[s[mymaxi]]>0)bcount+=1;
	                }
	                else if((m*(slen-1))<k){
	                    if(s[s[mymaxi]]>0)bcount+=1;
	                }
	                else {
	                    kele=0;
	                    for(l=mymin;l<=mymaxi;l++){
	                        kele+=(m*s[l]);
	                        if(kele>=k){
	                            if(s[s[l]]>0)bcount+=1;
	                            break;
	                        }
	                    }
	                }
	            }
	            else {
	                kele=0;
	                for(l=mymin;l<=mymaxi;l++){
	                       kele+=s[l];
	                       if(kele>=k){if(s[s[l]]>0)bcount+=1;break;}
	                   }
	                   
	                }
	            }
	            
	            }
	        }
	    }
	    cout<<bcount<<endl;
	    }
return 0;
}
