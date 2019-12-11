#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int r_dig[10]={3,0,1,2,2,2,2,2,2,3};
	    int l_dig[10]={0,3,3,2,1,1,1,1,1,1};
	    long long l,r,result=0,count=0;
	    cin>>l>>r;
	    int lr=l/10;
	    lr=(lr*10)+10;
	    int rr=r/10;
	    rr=rr*10;
	    int last_l=l%10;
	    int last_r=r%10;
	    if((rr-lr)==0)result=l_dig[last_l];
	    else result=(((rr-lr)/10)*3)+l_dig[last_l]+r_dig[last_r];
	    cout<<result<<endl;
	    //cout<<endl;
	}
	return 0;
}