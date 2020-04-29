#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//int diff(int ,int);
int diff(int i,int j){
    if(i>j)return (26-i+j);
    else return (j-i);
}

int main() {
	string s;
	int k,i,j;
	bool flag=false;
	char start='a';
	cin>>s;
	cin>>k;
	
	int len=s.length();
	map<char,int >c;
	for(i=1;i<27;i++){
	    c[start+i-1]=i;
	    //c.insert(pair<char,int>(start+i-1,i));
	}
	int a[len-1][2];
	for(i=0;i<len;i++){
	    int temp1=c[s[i]];
	    int temp2=c[s[i+1]];
	    a[i][0]=diff(temp1,temp2);
	    a[i][1]=0;
	}
	
	for(j=0;j<k;j++){
	    int max=0;
	    int pos=0;
	    for(i=0;i<len-1;i++){
	        if(a[i][0]>=max && a[i][1]==0){
	            max=a[i][0];
	            pos=i;
	        }
	    }
	    a[pos][1]=1;
	    //cout<<a[pos][0]<<" ";
	}
	//cout<<endl;
	int val=0;
	int sum=0;
	for(i=len-1;i>=0;i--){
	    if(a[i][1]==0){
	        //flag=false;
	        sum=sum+a[i][0]+val;
	        val=val+1;
	    }
	    else if(a[i][1]==1){
	        //flag=true;
	        val=0;
	    }
	}
	
	/*for(i=0;i<len-1;i++)cout<<a[i][0]<<" ";
	cout<<endl;
	for(j=0;j<len-1;j++)cout<<a[j][1]<<" ";
	cout<<endl;*/
	cout<<sum;
	
	
	
	
	return 0;
}
