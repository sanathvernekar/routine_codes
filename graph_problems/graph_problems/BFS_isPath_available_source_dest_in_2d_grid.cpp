#include<bits/stdc++.h>
#define ll long long int 
#define mod 1000000007
using namespace std;
typedef pair<int ,int>ipair;
#define max 1000
void ispath(int map[][1000],int n,int sx,int sy,bool vis[][1000]){
    queue<ipair>q;
    int i;
    int x,y,tx,ty;
    int mx[4]={-1,1,0,0};
    int my[4]={0,0,1,-1};
    q.push(make_pair(sx,sy));
	// q.emplace_back(sx,sy); //vector.emplace_back(x,y) does the same task as of vector.push_back(make_pair(x,y))
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(i=0;i<4;i++){
            tx=x+mx[i];
            ty=y+my[i];
            if(tx<0 || ty<0)continue;
            if(tx>=n || ty>=n)continue;
            else if(!vis[tx][ty] && map[tx][ty]>0 ){
                vis[tx][ty]=true;
                q.push(make_pair(tx,ty));
            }
        }
    }
    
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	    {
	        int sx,sy,dx,dy,n,i,j;
	        cin>>n;
	        bool vis[1000][1000];
	        int map[1000][1000];
	        for(i=0;i<n;i++){
	            for(j=0;j<n;j++){
	                cin>>map[i][j];
	                vis[i][j]=false;
	                if(map[i][j]==1){sx=i;sy=j;}
	                if(map[i][j]==2){dx=i;dy=j;}
	            }
	        }
	        ispath(map,n,sx,sy,vis);
	        if(vis[dx][dy]==true)cout<<"1"<<endl;
	        else cout<<"0"<<endl;
	        
	    }
    return 0;
}
//here 1->source 2-> destination 3->path 0->wall or blocked path
//is path available from source to destination 
// kind of snake and ladder problem 
