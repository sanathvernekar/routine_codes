#include <iostream>
using namespace std;

int main() {
	int n;
	int j;
	bool terminate=false;
	cin>>n;
	int a[n];
	int my_arr[101]={0};
	for(int i=0;i<n;i++){
	    cin>>a[i];
	    my_arr[a[i]]+=1;
	}
	int  c_arr[101]={-1};
	int count=0;
	for(j=0;j<101;j++){
	    if(my_arr[j]==1){
	        my_arr[j]=9999;
	        count=count+1;
	    }
	}
	if(count%2!=0){
	    cout<<"NO"<<endl;
	    terminate=true;
	}
	if(terminate==false){
	    cout<<"YES"<<endl;
	    int num=0;
	    for(j=0;j<101;j++){
	        if(my_arr[j]==9999){
	            c_arr[j]=num%2;
	            num=num+1;
	        }
	    }
	    for(j=0;j<n;j++){
	        if(my_arr[a[j]]==9999){
	            if(c_arr[a[j]]==0)cout<<"A";
	            else if(c_arr[a[j]]==1)cout<<"B";
	        }
	    }
	    cout<<endl;
	    
	}
}
