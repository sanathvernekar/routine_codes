#include <iostream>
#include<bits/stdc++.h>
#include <algorithm>
#include <map>
#include <cstdio>
#include <stack>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <cstring>
#include <utility>
#include <iterator>

using namespace std;
 
#define loop(x,k,n) for(int x = k; x < n; x++)     
#define revLoop(q,w) for (int q = w-1;q>=0 ;q--)
#define ll long long int
#define minMod 10e7+3
#define strInp(a) cin.getline(a,1000);
#define mp(a,b) make_pair(a,b)
#define init(a,n) memset(a,n,sizeof(a));
#define pb(i) push_back(i);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define tc int t; cin >> t; while(t--)
#define arrInp(a,n) for (int i=0;i<n;i++) cin >> a[i]
inline ll sumofdigits(ll n){ll res=0;for (res = 0; n > 0;res += n % 10, n /= 10);return res;}
inline ll maxi(ll a, ll b){return a>b?a:b;}
inline ll mini(ll a, ll b){return a<b?a:b;}
inline void swap(ll *x,ll *y){ll tmp=*x;*x=*y;*y=tmp;}

string longDivision(string number, int divisor) 
{ 
    string ans; 
    int idx = 0; 
    int temp = number[idx] - '0'; 
    while (temp < divisor) 
       temp = temp * 10 + (number[++idx] - '0'); 
    while (number.size() > idx) 
    { 
        ans += (temp / divisor) + '0'; 
        temp = (temp % divisor) * 10 + number[++idx] - '0'; 
    } 
    if (ans.length() == 0) 
        return "0"; 
    return ans; 
} 

string multiply(string num1, string num2) 
{ 
    int n1 = num1.size(); 
    int n2 = num2.size(); 
    if (n1 == 0 || n2 == 0) 
    return "0"; 
    vector<int> result(n1 + n2, 0); 
    int i_n1 = 0;  
    int i_n2 = 0;  
    for (int i=n1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int n1 = num1[i] - '0'; 
        i_n2 = 0;  
        for (int j=n2-1; j>=0; j--) 
        { 
            int n2 = num2[j] - '0'; 
            int sum = n1*n2 + result[i_n1 + i_n2] + carry; 
            carry = sum/10; 
            result[i_n1 + i_n2] = sum % 10; 
   
            i_n2++; 
        } 
        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
        i_n1++; 
    } 
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
    i--; 
    if (i == -1) 
    return "0"; 
    string s = ""; 
       
    while (i >= 0) 
        s += std::to_string(result[i--]); 
   
    return s; 
} 

bool isSmaller(string str1, string str2) 
{ 
	// Calculate lengths of both string 
	int n1 = str1.length(), n2 = str2.length(); 

	if (n1 < n2) 
	return true; 
	if (n2 < n1) 
	return false; 

	for (int i=0; i<n1; i++) 
	if (str1[i] < str2[i]) 
		return true; 
	else if (str1[i] > str2[i]) 
		return false; 

	return false; 
} 

// Function for find difference of larger numbers 
string findDiff(string str1, string str2) 
{ 
	// Before proceeding further, make sure str1 
	// is not smaller 
	if (isSmaller(str1, str2)) 
		swap(str1, str2); 

	// Take an empty string for storing result 
	string str = ""; 

	// Calculate length of both string 
	int n1 = str1.length(), n2 = str2.length(); 

	// Reverse both of strings 
	reverse(str1.begin(), str1.end()); 
	reverse(str2.begin(), str2.end()); 
	
	int carry = 0; 

	// Run loop till small string length 
	// and subtract digit of str1 to str2 
	for (int i=0; i<n2; i++) 
	{ 
		// Do school mathematics, compute difference of 
		// current digits 
		
		int sub = ((str1[i]-'0')-(str2[i]-'0')-carry); 
		
		// If subtraction is less then zero 
		// we add then we add 10 into sub and 
		// take carry as 1 for calculating next step 
		if (sub < 0) 
		{ 
			sub = sub + 10; 
			carry = 1; 
		} 
		else
			carry = 0; 

		str.push_back(sub + '0'); 
	} 

	// subtract remaining digits of larger number 
	for (int i=n2; i<n1; i++) 
	{ 
		int sub = ((str1[i]-'0') - carry); 
		
		// if the sub value is -ve, then make it positive 
		if (sub < 0) 
		{ 
			sub = sub + 10; 
			carry = 1; 
		} 
		else
			carry = 0; 
			
		str.push_back(sub + '0'); 
	} 

	// reverse resultant string 
	reverse(str.begin(), str.end()); 

	return str; 
} 
string removezeros(string s){
 string res;
 int pos=0;
 for(int i=0;i<s.length();i++){
  if(s[i]=='0')pos+=1;
  else break;
 }
 for(int i=pos;i<s.length();i++){
     res+=s[i];
 }
    return res;
    
}



int main()
{
	FIO
	tc{
	    string k;
	    int n;
	    int num=2;
	    cin>>n;
	    cin>>k;
	    string val=longDivision(k,n);
	    string mul=multiply(val,to_string(n));
	    //cout<<val<<" "<<mul<<endl;
	    if(k==mul)cout<<0<<endl;
	    else {
	        string x=findDiff(k,mul);//(k-(val*n))
	        x=removezeros(x);
	        string y=findDiff(to_string(n),x);//(n-(k-(val*n)))
	        y=removezeros(y);
	        string pk;
	        //cout<<x<<" "<<y<<endl;
	        if(n%2==1){
	            
	            //string x=findDiff(k,multiply(val,to_string(n)));
	            if(isSmaller(x,y)==true){
	                pk=multiply(x,to_string(num));
	                pk=removezeros(pk);
	                cout<<pk<<endl;
	            }
	            else 
	            
	            {   pk=multiply(y,to_string(num));
	                pk=removezeros(pk);
	                cout<<pk<<endl;
	                }
	            
	        }
	        else {
	            int lmt=n/2;
	            int gd=stoi(x);
	            if(gd==lmt){
	                cout<<n-1<<endl;
	            }
	            else {
	                
	                if(isSmaller(x,y)==true){
	                pk=multiply(x,to_string(num));
	                pk=removezeros(pk);
	                cout<<pk<<endl;
	            }
	            else 
	            
	            {   pk=multiply(y,to_string(num));
	                pk=removezeros(pk);
	                cout<<pk<<endl;
	                }
	                }
	        }
	    }
	}
	/*
	tc{
	    ll n,k;
	    cin>>n>>k;
	    ll val=k/n;
	    if((val*n)==k)cout<<0<<endl;
	    else{
	        if(n %2==1){
	            //odd 
	            cout<<mini((k-(val*n)),(n-(k-(val*n))))*2<<endl;
	            //cout<<mini(abs((val*n)-k),(n-abs((val*n)-k)))*2<<endl;
	            
	        }
	        else {
	            //even
	            ll lmt=n/2;
	            if((k-(val*n))==lmt){
	                cout<<n-1<<endl;
	            }
	            else {
	                cout<<mini((k-(val*n)),(n-(k-(val*n))))*2<<endl;
	                //cout<<mini(abs(k-(val*n)),(n-abs(k-(val*n))))*2<<endl;
	            }
	        }
	    }
	}
	
	*/
return 0;
}