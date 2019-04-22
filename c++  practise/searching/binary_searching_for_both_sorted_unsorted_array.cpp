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
ll a[100001];
int binarySearch(int low,int high,int key)
{
    //for sorted arrays
   while(low<=high)
   {
     int mid=(low+high)/2;
     if(a[mid]<key)
     {
         low=mid+1;
     }
     else if(a[mid]>key)
     {
         high=mid-1;
     }
     else
     {
         return mid;
     }
   }
   return -1; 
 }
 int revBinarySearch(int low,int high,int key)
{
    // for reverse sorted arrays 
   while(low<=high)
   {
     int mid=(low+high)/2;
     if(a[mid]<key)
     {
        high=mid-1;   
     }
     else if(a[mid]>key)
     {
         low=mid+1;
         
     }
     else
     {
         return mid;
     }
   }
   return -1; 
 }


int main()
{
	FIO
	ll n;
	cin>>n;
	ll i;
	for(i=0;i<n;i++)cin>>a[i];
	ll q;
	cin>>q;
	for(i=0;i<q;i++){
	    ll key;
	    cin>>key;
	    if(a[0]<a[n-1])
	    cout<<binarySearch(0,n,key)+1<<endl;
	    else 
	    cout<<n-revBinarySearch(0,n-1,key)<<endl;
	}

return 0;
}
