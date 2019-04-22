#include<bits/stdc++.h>
using namespace std;




int main()
 {
     long long int t,n,i,j,m;
     char temp;
     cin>>t;
     while(t--){
         bool flag=false;
         cin>>n>>m;
         int a[n][m];
         for(i=0;i<n;i++){
             for(j=0;j<m;j++){
                 cin>>temp;
                 if(temp=='.')a[i][j]=0;
                 else if(temp=='#')a[i][j]=-1;
             }
         }
         for(i=0;i<n-1;i++){
             for(j=0;j<m-1;j++){
                 if(a[i][j]==-1 || a[i][j+1]==-1 || a[i+1][j]==-1 || a[i+1][j+1]==-1){
                     continue;
                 }
                 else {
                     a[i][j]=1;
                     a[i][j+1]=1;
                     a[i+1][j]=1;
                     a[i+1][j+1]=1;
                 }
             }
         }
         for(i=0;i<n;i++){
             for(j=0;j<m;j++){
                 if(a[i][j]==0){
                     cout<<"NO"<<endl;
                     flag=true;
                     break;
                 }
             }
             if(flag==true)break;
         }
         if(flag==false){
             cout<<"YES"<<endl;
         }
     }
    return 0;
}