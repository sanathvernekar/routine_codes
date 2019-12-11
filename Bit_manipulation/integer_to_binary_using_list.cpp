#include<bits/stdc++.h>


using namespace std;

list <int > binary(int n){
    list<int>b;
    int x=n;
    while(x>0){
        b.push_back(x%2);
        x=x/2;
    }
    return b;
    
}
int main(){
    int n;
    cin>>n;
    list <int > bin=binary(n);
    for(auto x : bin){
        cout<<x;
    }
    cout<<endl;
    
    return 0;
}
