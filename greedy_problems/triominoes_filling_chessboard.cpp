/*   Author : - Lilliput     */
#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

int main()
{
	ll t;
	cin>>t;
	while(t--){
	   ll n,i,j,k,count=1;
	   cin>>n;
	   ll a[n][n];
	   for(i=0;i<n;i++){
	       for(j=0;j<n;j++){
	           a[i][j]=0;
	       }
	   }
	   if(n==1 || n==3 || n==5)cout<<-1<<endl;
	   else if(n%2==0){
	       ll num=n/2;
	       cout<<num*num<<endl;
	       count=num*num;
	       count=1;
	       for(i=0;i<n;i=i+2){
	           for(j=0;j<n;j=j+2){
	               a[i][j]=count;
	               a[i][j+1]=count;
	               a[i+1][j+1]=count;
	               count=count+1;
	           }
	       }
	       for(i=0;i<n;i++){
	           for(j=0;j<n;j++){
	               cout<<a[i][j]<<" ";
	           }
	           cout<<endl;
	       }
	   }
	   else{
	       ll p=(n-7)/2;
	       ll lmt=p;
	       ll res=16+(p*9)+(p*(p-1));
	       cout<<res<<endl;
	       p=n-7;
	       //fill 7*7 matrix
	       {
	           
	           for(j=0;j<6;j=j+2){
	               a[p][j]=res;
	               a[p+1][j]=res;
	               a[p][j+1]=res;
	               res=res-1;
	           }
	           a[p][6]=res;
	           a[p+1][5]=res;
	           a[p+1][6]=res;
	           res=res-1;
	           a[p+1][1]=res;
	           a[p+2][0]=res;
	           a[p+2][1]=res;
	           res=res-1;
	           a[p+1][3]=res;
	           a[p+2][2]=res;
	           a[p+2][3]=res;
	           res=res-1;
	           a[p+2][4]=res;
	           a[p+2][5]=res;
	           a[p+3][4]=res;
	           res=res-1;
	           a[p+2][6]=res;
	           a[p+3][5]=res;
	           a[p+3][6]=res;
	           res=res-1;
	           a[p+3][0]=res;
	           a[p+3][1]=res;
	           a[p+4][0]=res;
	           res=res-1;
	           a[p+3][2]=res;
	           a[p+4][1]=res;
	           a[p+4][2]=res;
	           res=res-1;
	           a[p+3][3]=res;
	           a[p+4][3]=res;
	           a[p+4][4]=res;
	           res=res-1;
	           a[p+5][0]=res;
	           a[p+5][1]=res;
	           a[p+6][0]=res;
	           res=res-1;
	           a[p+5][2]=res;
	           a[p+6][2]=res;
	           a[p+6][3]=res;
	           res=res-1;
	           a[p+5][3]=res;
	           a[p+5][4]=res;
	           a[p+6][4]=res;
	           res=res-1;
	           a[p+4][5]=res;
	           a[p+4][6]=res;
	           a[p+5][6]=res;
	           res=res-1;
	           a[p+5][5]=res;
	           a[p+6][5]=res;
	           a[p+6][6]=res;
	           res=res-1;
	           
	   }
	   //filling Row wise of the matrix above 7*7 matrix
	       for(i=0;i<p;i=i+2){
	           for(j=0;j<n-3;j=j+2){
	               a[i][j]=res;
	               a[i][j+1]=res;
	               a[i+1][j+1]=res;
	               res=res-1;
	           }
	       }
	       // fill 2*3 grid with 2 l shaped blocks from top to bottom
	       for(i=0;i<p;i=i+2){
	           
	           {
	               a[i][j]=res;
	               a[i+1][j]=res;
	               a[i][j+1]=res;
	               res=res-1;
	               a[i][j+2]=res;
	               a[i+1][j+1]=res;
	               a[i+1][j+2]=res;
	               res=res-1;
	           }
	       }
	       
	       
	       //from row =n-7 till end fill with blocks from top
	       for(i=p;i<n-1;i=i+2){
	           for(j=7;j<n;j=j+2){
	               a[i][j]=res;
	               a[i][j+1]=res;
	               a[i+1][j]=res;
	               res=res-1;
	           }
	       }

	       //fill final row at the bottom
            i=n-1;
	       for(j=7;j<n;j=j+2){
	           a[i-1][j+1]=res;
	           a[i][j]=res;
	           a[i][j+1]=res;
	           res=res-1;
	       }
	       //print the matrix
	       for(i=0;i<n;i++){
	           for(j=0;j<n;j++){
	               cout<<a[i][j]<<" ";
	           }
	           cout<<endl;
	       }
	   } 
	}
return 0;
}
