#include<bits/stdc++.h>
using namespace std;




int main()
 {
     long long int n,i,x,y,z;
     cin>>n;
     while(n--){
         cin>>x>>y>>z;
         if((x+y-z)==0 || (x-y+z)==0 || (y-x+z)==0){
             cout<<"yes"<<endl;
             continue;
         }
         else {
             cout<<"no"<<endl;
             continue;
         }
     }
    return 0;
}