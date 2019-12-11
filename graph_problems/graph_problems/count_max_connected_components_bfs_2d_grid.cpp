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

vector<int>soldiers;
int tent[1001][1001];
bool visited[1001][1001];
int n ,m;

void bfs(int i ,int j){
    int counter=1;
    queue<pair<int,int>>q;
    int x,y;
    int mx[8]={-1,0,1,-1,1,-1,0,1};
    int my[8]={-1,-1,-1,0,0,1,1,1};
    q.push(make_pair(i,j));
    visited[i][j]=true;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int l=0;l<8;l++){
            int tx=x+mx[l];
            int ty=y+my[l];
            if(tx<0 || ty <0)continue;
            if(tx>=n || ty>= m)continue;
            else if(visited[tx][ty]==false && tent[tx][ty]==1){
                counter+=1;
                q.push(make_pair(tx,ty));
                visited[tx][ty]=true;
            }
            
        }
    }
    soldiers.push_back(counter);
    
    
}

int main()
{
	FIO
	{
        tc{
            cin>>n>>m;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cin>>tent[i][j];
                }
            }
            
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    visited[i][j]=false;
                }
            }
            
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(visited[i][j]==false && tent[i][j]==1){
                        bfs(i,j);
                    }
                    
                }
            }
            int max_ele=0;
            for(int ele : soldiers){
                if(ele>max_ele)max_ele=ele;
            }
            cout<<soldiers.size()<<" "<<max_ele<<endl;
            soldiers.clear();
        }

    }


return 0;
}
