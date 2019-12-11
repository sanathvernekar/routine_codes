#include <bits/stdc++.h>
#include<string.h>

using namespace std;

bool palindromeCheck(string s){
    int l=0;
    l=s.length();
    bool flag=true;
    for (int i=0;i<l;i++)
    {
        if(s[i]!=s[l-i-1])
        {
            
            flag=false;
            break;
        }
    }
    return flag;
}

int main() {
    string s;
    cin >> s;
    bool result = palindromeCheck(s);
    if(result == true)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    
    return 0;
}

