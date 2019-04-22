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



int main()
{
	FIO
	tc{
        map<string,ll,ll>points;
        map<string,ll,ll>::iterator it;
        string a,b,d;
        ll ap,bp;
        ll i;
        for(i=0;i<12;i++){
            cin>>a>>ap>>d>>bp>>b;
            ll pa,pb;
            if(a>b){pa=3;pb=0;}
            else if(a==b){pa=1;pb=1;}
            else {pa=0;pb=3;}
            it=points.find(a);
            if(it==points.end())points.insert({a,pa,(ap-bp)});
            else points.at(a)=(points.find(a)->second)+pa;
            it=points.find(b);
            if(it==points.end())points.insert({b,pb});
            else points.at(b)=(points.find(b)->second)+pb;
            it=goaldif.find(a);
            if(it==goaldif.end())points.insert({a,ap-bp});
            else goaldif.at(a)=(goaldif.find(a)->second)+(ap-bp);
            it=goaldif.find(b);
            if(it==goaldif.end())points.insert({a,bp-ap});
            else goaldif.at(b)=(goaldif.find(b)->second)+(bp-ap);
        }
        ll mp=-1;
        ll mg=-1;
        string sa,sb;
        ll wpa,wpb;
        ll gpa,gpb;
        for(it=points.begin();it!=points.end();++it){
            if(it->second>mp){mp=it->second;sa=it->first;}
        }
        wpa=mp;
        it=points.find(sa);
        points.erase(it);
        mp=-1;
        for(it=points.begin();it!=points.end();++it){
            if(it->second>mp){mp=it->second;sb=it->first;}
        }
        wpb=mp;
        if(wpa!=wpb)cout<<sa<<" "<<sb<<endl;
        else {
            cout<<"sorry";
        }

    }


return 0;
}
