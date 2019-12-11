#include<bits/stdc++.h>
using namespace std;
typedef int ll;
#define f(i,a,b) for(i=a;i<b;i++)
template <typename T>
inline void scan_num(T &a) {
	register T c;
	a = 0;
	do c = getchar_unlocked(); while(c < '0');
	do {
		a = (a << 1) + (a << 3) + c - '0';
		c = getchar_unlocked();
	} while (c >= '0');
}
 
template <typename T>
inline void print_num(T a) {
	char s[11];
	T t = -1;
	do {
		s[++t] = a % 10 + '0';
		a /= 10;
	} while (a > 0);
	while (t >= 0) putchar_unlocked(s[t--]);
	putchar_unlocked('\n');
}
void swap(ll *x,ll *y)
{
    ll tmp=*x;
    *x=*y;
    *y=tmp;
}
ll r,c,cnt;
ll a[1002][1002];
ll visit[1002][1002];
bool is_valid(ll x,ll y)
{
    if((x>=0&&x<r)&&(y>=0&&y<c))
    return true;
    return false;
}
void bfs(ll x,ll y)
{
    if((is_valid(x,y))&&(!visit[x][y])&&(a[x][y]))
    {
        visit[x][y]=1;
        cnt--;
        bfs(x+1,y);
        bfs(x-1,y);
        bfs(x,y+1);
        bfs(x,y-1);
    }
}
int main()
{
    ll q,x,i,j,y;
    scan_num(r);
    scan_num(c);
    scan_num(q);
    cnt=0;
    for(i=0;i<r;i++)
    for(j=0;j<c;j++){
    scan_num(a[i][j]);
    if(a[i][j])
    cnt++;}
    memset(visit,0,sizeof(visit));
    while(q--)
    {
        scan_num(x);
        scan_num(y);
        x--;
        y--;
        bfs(x,y);
        print_num(cnt);
    }
}
