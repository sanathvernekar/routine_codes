#include <bits/stdc++.h> 
using namespace std; 
bool isShuffledSubstring(string needle, string haystack);



bool isShuffledSubstring(string needle, string haystack) 
{
	//O(n) time complexity
    int cur_val=needle.length();
    if(cur_val>haystack.length())return false;
    int val[128];
    int val2[2][128];
    memset(val,0,sizeof(val));
    memset(val2,0,sizeof(val2));
    for(int i=0;i<cur_val;i++){
        val[needle[i]]+=1;
    }
    queue<char>q;
    for(int i=0;i<cur_val;i++){
        q.push(haystack[i]);
        val2[0][haystack[i]]+=1;
    }
    bool flag=true;
    int wrong_val=0;
    
    for(int i=0;i<128;i++){
        
        if(val[i]!=val2[0][i]){wrong_val+=1;val2[1][i]=1;}
    }
    if(wrong_val==0)return true;
    int init_point=0;
    for(int i=cur_val;i<haystack.length();i++){
        char ini=q.front();
        q.pop();
        char cur=haystack[i];
        q.push(cur);
        val2[0][ini]-=1;
        val2[0][cur]+=1;
        if(val2[1][ini]==1 && val2[0][ini]==val[ini]){
            //init wrong & now rectified
            wrong_val-=1;
            val2[1][ini]=0;
        }
        else if(val2[1][ini]==0 && val2[0][ini]!=val[ini]){
            //init correct & now turned wrong
            wrong_val+=1;
            val2[1][ini]=1;
        }
        
        if(val2[1][cur]==1 && val2[0][cur]==val[cur]){
            //init wrong & now rectified
            wrong_val-=1;
            val2[1][cur]=0;
        }
        else if(val2[1][cur]==0 && val2[0][cur]!=val[cur]){
            //init correct & now turned wrong
            wrong_val+=1;
            val2[1][cur]=1;
        }
        if(wrong_val==0)return true;
        
    }
    return false;
}


int main(){
    int t;
    cin>>t;
    while(t--)
    {
    	string needle, haystack;
    	cin>>needle;
    	cin>>haystack;

    	if (isShuffledSubstring(needle, haystack)) 
			cout << "Yes"; 
		else
			cout << "No"; 
		cout << endl; 
    }
    return 0;
}

