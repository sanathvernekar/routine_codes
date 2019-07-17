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
#define arrInp(a,n) for (int i=0;i<n;i++) cin >> a[i];

char mat[100][100];
int dist[100][100];
bool visited[100][100];

void bfs(int sx,int sy,int n){
    queue<pair<int,int>>q;
    int x,y;
    int tx,ty;
    dist[sx][sy]=0;
    q.push(make_pair(sx,sy));
    visited[sx][sy]=true;
    int mx[4]={0,1,0,-1};
    int my[4]={-1,0,1,0};
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            tx=x+mx[i];
            ty=y+my[i];
            if(tx <0 || ty <0)continue;
            else if(tx>=n || ty >=n)continue;
            else if(visited[tx][ty]==false && (mat[tx][ty]=='P' || mat[tx][ty]=='E')){
                q.push(make_pair(tx,ty));
                dist[tx][ty]=dist[x][y]+1;
                visited[tx][ty]=true;
            }
        }
        
    }
    
}

int main()
{
	FIO
	{
	    int n;
	    cin>>n;
	    int startx=0,starty=0;
	    int endx=0,endy=0;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            cin>>mat[i][j];
	            visited[i][j]=false;
	            if(mat[i][j]=='S'){startx=i;starty=j;}
	            if(mat[i][j]=='E'){endx=i;endy=j;}
	        }
	    }
	    bfs(startx,starty,n);
	    cout<<dist[endx][endy]<<endl;
	    
	    
	}



return 0;
}
