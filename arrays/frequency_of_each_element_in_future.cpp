#include<bits/stdc++.h> 
using namespace std;
#define loop(x,k,n) for(int x = k; x < n; x++)      // i ko 0 se n
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
// for all a[i] , count all a[j] such that for all j>i && j<=n where a[i]==a[j]
ll count_freq_future(vector<ll> a, ll n){
    ll count=0;
    vector<ll>num_count(100001,0);
    for(ll i=0;i<n;i++)num_count[a[i]]+=1;
    for(ll i=0;i<n;i++){num_count[a[i]]-=1;count+=num_count[a[i]];}
    return count;
}
inline ll max_of_array(vector<ll>a){
    ll res=LONG_MIN;
    for(ll ele : a)if(ele>res)res=ele;
    return res;
}
inline ll min_of_array(vector<ll>a){
    ll res=LONG_MAX;
    for(ll ele : a)if(ele <res)res=ele;
    return res;
}

int main()
{
	tc{
        ll n;
        cin>>n;
        vector<ll>a(n);
        for(ll i=0;i<n;i++)cin>>a[i];
        cout<<count_freq_future(a,n)<<endl;
    }
return 0;
}