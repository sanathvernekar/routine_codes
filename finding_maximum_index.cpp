#include <bits/stdc++.h>
using namespace std;

int main() {
//code
int t;
cin>>t;
while(t--){
int n;
cin>>n;
vector<pair<int , int>> v;
for(int i = 0 ; i < n ; i++){
int a;
cin>>a;
v.push_back(make_pair(a , i));
}
sort(v.begin() , v.end());
int len = v.size() - 1;
int ans = 0;
int max_index = v[len].second;
for(int i = len-1 ; i >= 0;i--){
ans = max(ans , max_index - v[i].second);
max_index = max(max_index , v[i].second);
}
cout<<ans<<'\n'; }
return 0;
    
}
