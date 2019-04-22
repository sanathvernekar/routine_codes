#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <cmath>
#define nfs ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define pr 1000000007
#define pb push_back
#define lim 100000
using namespace std;
int freq[20][100001],part[20][100001]; ll ans[100001],fans=0;
int main()
{
	nfs;
	int i,j,n,m,inp,k;
	cin>>n>>m;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++){
			cin>>inp;
			freq[i][inp]++;
		}

	for(j=lim;j;j--){
		ll tmp=1,tmp2=1;
		for(i=0;i<n;i++){
			for(k=j;k<=lim;k+=j)
				part[i][j] += freq[i][k];
			tmp += part[i][j];
			part[i][j]++;
			tmp2 = (tmp2*part[i][j])%pr;
			// cout<<i<<" "<<j<<" "<<part[i][j]<<endl;
		}

		ans[j] = (tmp2 + (pr - tmp)%pr)%pr;
		for(k=2*j;k<=lim;k+=j) ans[j] = (ans[j] + (pr - ans[k])%pr)%pr;
		fans = (fans + (ans[j]*j)%pr)%pr;
	}


	cout<<fans<<"\n";
	
}

