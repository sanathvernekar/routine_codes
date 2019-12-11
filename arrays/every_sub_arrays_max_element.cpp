/*#include<bits/stdc++.h>
#define ll long long int 
#define mod 1000000007
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	    {
	        ll n,k;
	        cin>>n>>k;
	        ll a[n];
	        map<ll , ll>m;
	        ll i;
	        for(i=0;i<n;i++)cin>>a[i];
	        for(i=0;i<k;i++){
	            m[a[i]]++;
	        }
	        auto it=m.rbegin();
	        cout<<it->first<<" ";
	        ll pos=0;
	        for(i=k;i<n;i++){
	            m[a[i]]++;
	            m[a[pos]]--;
	            if(m[a[pos]]==0)m.erase(a[pos]);
	            pos++;
	            it=m.rbegin();
	            cout<<it->first<<" ";
	            
	        }
	        cout<<endl;
	    }
    return 0;
}*/
// best solution 
#include<iostream>
using namespace std;

#define ll long long int

int main() 
{
    int li;
    cin >> li;
    while(li--)
    {
        ll n,t;
        cin >> n >> t;
        ll arr[n];
        
        int initialMax = -1;
        ll pos;
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
            
        }
        
        for(int j=0;j<t;j++)
        {
            if(arr[j] > initialMax)
            {
                initialMax = arr[j];
                pos = j;
            }
        }
        
        cout << initialMax << " ";
       
        for(int i=1;i<n-t+1;i++)
        {
            if(pos>=i)
            {
                if(arr[i+t-1] > initialMax)
                {
                    cout << arr[i+t-1] << " ";
                    initialMax = arr[i+t-1];
                    pos = i+t-1;
                }
                else
                {
                    cout << initialMax << " ";
                }
            }
            else if(pos<i)
            {
                ll newMax=-1;
                for(int j=i;j<=i+t-1;j++)
                {
                    if(arr[j] > newMax)
                    {
                        newMax = arr[j];
                        pos = j;
                    }
                }
                initialMax = newMax;
                
                cout << initialMax << " ";
            }
        }
        
        cout << "\n";
    }
	return 0;
}
/*
 or 
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
	    int n, k;
	    cin>>n>>k;
	    int a[n];
	    forall(i,0,n) cin>>a[i];
	    forall(i,0,n-k+1)
	        cout<<*max_element(a+i, a+i+k)<<' ';
	    cout<<'\n';
	}
}
*/
