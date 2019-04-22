#include<bits/stdc++.h>
using namespace std;
bool valid(char ch) {
    if(tolower(ch)>='a' && tolower(ch)<='z') return 1;
    if(ch>='0' && ch<='9') return 1;
    return 0;
}
bool check(string s) {
    int n = s.size();
    int i = 0, j= n-1;
    while(i < j) {
        if(s[i] != s[j]) return 0;
        i++; j--;
    }
    return 1;
}
int main()
 {
	//code
	int t;
	cin>>t;
	cin.ignore();
	while(t--) {
	    string s;
	    getline(cin, s);
	    string res;
	    for(int i=0;i<s.size();i++) {
	        if(valid(s[i])) {
	            res += tolower(s[i]);
	        }
	    }
	    cout<<(check(res) ? "YES\n" : "NO\n");
	}
	return 0;
}
