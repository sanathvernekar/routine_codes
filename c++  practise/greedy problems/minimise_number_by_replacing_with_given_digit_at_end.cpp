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
		string n;
		int d;
		cin>>n>>d;
		int l=n.length();
		int i,max=0,min=0,spos=0,epos=0,count=0;
		int var;
		int j;
		int globalcount=0;
		
            int spoint=-1,epoint=l;
		    while(spoint<epoint && min<d){
		        min=d;
		        count=0;
		        for(i=spoint+1;i<l;i++){
		            var=(int(n[i])-48);
		            if(var<=min){
		                if(var<min){
		                    min=var;
		                    spoint=i;
		                    count=1;
		                }
		                else {
		                    spoint=i;
		                    count+=1;
		                }
		            }
		        }
		        globalcount+=count;
		        for(j=0;j<count;j++)cout<<min;
		        if(min==d)break;
		    }
		    int lmt=l-globalcount;
		    for(i=0;i<lmt;i++)cout<<d;
		    cout<<endl;

	}
return 0;
}
