#include<bits/stdc++.h>

using namespace std;
int index(vector<int> freq ,int lmt){
    int max=-1;
    int idx=-1;
    for(int i=0;i<lmt;i++){
        if(freq[i]>max){
            max=freq[i];
            idx=i;
        }
        
    }
    return idx;
}
int main()
 {
	int i,j,k,n,t,temp;
	cin>>t;
	//vector <int > a(t,0);
	for(i=0;i<t;i++)
	    {
	        cin>>n;
	        vector <int> a(60,0);
	        vector<int > freq(60,0);
	        for(j=0;j<n;j++){
	            cin>>a[j];
	            freq[a[j]]++;
	        }
	        int lmt_count=0;
	        for(k=0;k<61;k++){
	            if(freq[k]>0)lmt_count++;
	        }
	        //lmt_count=lmt_count+1;
	        for(k=0;k<lmt_count;k++){
	            int my_ele=index(freq,61);
	            if(my_ele>=0){
	                for(int l=freq[my_ele];l>0;l--){
	                cout<<my_ele<<" ";
	            }
	            freq[my_ele]=0;
	            }
	            
	        }
	        cout<<endl;
	        
	    }
    return 0;
}
