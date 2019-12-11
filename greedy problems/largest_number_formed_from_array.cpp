#include<bits/stdc++.h>

using namespace std;

bool mycompare(int x,int y)
{string k,l;
k=to_string(x);
l=to_string(y);    
return (k+l>=l+k);
}

int main() {
    
int t;
cin>>t;
while(t--)
{int n;
cin>>n;
vector<int> a(n);
for(int i=0;i<n;i++)
cin>>a[i];
sort(a.begin(),a.end(),mycompare);
string output;
for(int i=0;i<n;i++)
{string m=to_string(a[i]);
output+=m;
}
cout<<output<<endl;

    
}
	return 0;
}
