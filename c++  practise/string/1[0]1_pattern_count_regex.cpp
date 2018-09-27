#include <bits/stdc++.h>

using namespace std;

void solve(){
	string str;
	cin>>str;
	regex r("1[0]+1");
	smatch m;
	int count=0;
	while(regex_search(str,m,r)) // this function is searching for the regular expression in the string 
		{
		int index=m.position(0)+m.length()-1;// for this case 10101 (answer should be 2 in this case)
		str=str.substr(index);              // after firstmatch we need to start our next search from index 2 
		++count;   //increment the counter every times a string matches with regular expression
		}
	cout<<count<<"\n";
}
int main()
{
int t;
cin>>t;
while(t--)
	{
	solve();
	}
return 0;
}


