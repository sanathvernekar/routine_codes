#include<bits/stdc++.h>
#define ll long long int 
#define mod 1000000007
using namespace std;
int main()
 {
    ll t;	
	cin>>t;
	while(t--)
	    {
	        string s;
	        int c[256]={0};
	        c['A']=2;c['B']=22;c['C']=222;c['D']=3;c['E']=33;c['F']=333;c['G']=4;
	        c['H']=44;c['I']=444;c['J']=5;c['K']=55;c['L']=555;c['M']=6;c['N']=66;c['O']=666;
	        c['P']=7;c['Q']=77;c['R']=777;c['S']=7777;c['T']=8;c['U']=88;c['V']=888;c['W']=9;
	        c['X']=99;c['Y']=999;c['Z']=9999;c[' ']=0;
	        getline(cin, s);
            while (s.length()==0 )
            getline(cin, s);
	        ll l=s.length();
	        for(ll i=0;i<l;i++)cout<<c[s[i]];
	        cout<<endl;
	    }
    return 0;
}
