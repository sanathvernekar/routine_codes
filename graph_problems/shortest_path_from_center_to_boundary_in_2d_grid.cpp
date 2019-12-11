#include<bits/stdc++.h>
#include <utility>
//typedef pair<int ,int>ipair;
using namespace std;
int grid[101][101];
int escape_from_grid(int grid[][101],int row,int col,int sx,int sy) {
    //cout<<sx<<" "<<sy<<endl;
    
    if(sx==0 || sy==0 || sx==row-1 || sy==col-1)return 0;
    int x,y,tx,ty,i;
    int mx[4]={-1,1,0,0};
    int my[4]={0,0,1,-1};
    queue<pair<int,int>>q;
    bool vis[101][101];memset(vis,false,sizeof(vis));
    int dist[101][101];memset(dist,0,sizeof(dist));
    q.push(make_pair(sx,sy));
    int mini=101;
    dist[sx][sy]=0;
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(i=0;i<4;i++){
            tx=x+mx[i];
            ty=y+my[i];
            
            if(tx<0 || ty<0)continue;
            if(tx>=row || ty>=col)continue;
            else if(!vis[tx][ty] && grid[tx][ty]==0 ){
                //cout<<tx<<" "<<ty<<endl;
                vis[tx][ty]=true;
                dist[tx][ty]=dist[x][y]+1;
                q.push(make_pair(tx,ty));
                if(tx==0 || ty==0 || tx==row-1 || ty==col-1){if(dist[tx][ty]<mini)mini=dist[tx][ty];}
            }
        }
    }
    if(mini==101)return -1;
    else return mini;
}
 
int main() {
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int grid_x;
    cin >> grid_x;
    int grid_y;
    cin >> grid_y;
    int sx,sy;
    for (int i_grid = 0; i_grid < grid_x; i_grid++) {
        for (int j_grid = 0; j_grid < grid_y; j_grid++) {
            cin >> grid[i_grid][j_grid];
            if(grid[i_grid][j_grid]==2){sx=i_grid;sy=j_grid;}
        }
    }
 
    int out_;
    out_ = escape_from_grid(grid,grid_x,grid_y,sx,sy);
    cout << out_;
    
    return 0;
}

