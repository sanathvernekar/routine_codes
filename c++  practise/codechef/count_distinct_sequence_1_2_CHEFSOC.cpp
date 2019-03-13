#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    vector<int> inp(n);
	    for(int i=0;i<n;i++)
	        scanf("%d",&inp[i]);
	    vector<long long> out(n);
	    vector<long long> sec(n);
	    out[n-1] = 1;
	    for(int i=n-2;i>=0;i--)
	    {
	        sec[i+1] = 1;
	        out[i] = 1 + out[i+1];
	        if(inp[i]==2&&i+2<n)
	        {
	            out[i]+=out[i+2];
	            if(inp[i+1]==2&&i+3<n)
    	            out[i]+=1+out[i+3];
    	        else
    	            out[i]+=1;
    	        if(i+3<n&&inp[i+3]==2)
    	            out[i]+=sec[i+3];
    	        sec[i+1]+=1;
    	        if(i+3<n&&inp[i+3]==2)
    	            sec[i+1]+=sec[i+3];
	        }
	        out[i]%=1000000007;
	        sec[i]%=1000000007;
	    }
	    printf("%lld\n",out[0]);
	}
}

