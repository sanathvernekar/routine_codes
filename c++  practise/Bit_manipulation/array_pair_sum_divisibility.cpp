#include<bits/stdc++.h>

using namespace std;
int main()
 {
	int i,j,k,n,t;
	//my_list=new list<int>[100]; //2D list declaration
	//my_list::iterator it;
	cin>>t;
	while(t--)
	    {
	        cin>>n;
	        vector <int > a(n,0);
	        int sum=0;
	        for(i=0;i<n;i++){
	            cin>>a[i];
	            sum+=a[i];
	            }
	            cin>>k;
	            if(sum%k||n%2)cout<<"False";
	            else cout<<"True";
	            cout<<endl;
	    }
    return 0;
}
