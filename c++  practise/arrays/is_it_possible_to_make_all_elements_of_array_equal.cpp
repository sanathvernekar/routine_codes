    #include<bits/stdc++.h>
    #define ll long long
     
    using namespace std;
     
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr);
        ll t;
        cin>>t;
        while(t--){
            ll n,x,y,z;
            cin>>n>>x>>y>>z;
            ll a,flag=0,b;
            for(ll i=0;i<n;i++){
                cin>>a;
                while(a%x==0 && a>0){
                    a=a/x;
                }
                while(a%y==0 && a>0){
                    a=a/y;
                }
                while(a%z==0 && a>0){
                    a=a/z;
                }
                //mx = max(mx,a[i]);
                //cout<<a[i]<<" ";
                if(i==0){
                    b=a;
                    continue;
                }
                flag += a==b;
                b=a;
            }
            if(flag!=n-1) cout<<"She can't"<<endl;
            else cout<<"She can"<<endl;
        }
    }
