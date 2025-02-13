#include <cstdio>
#include <cstdlib>
#include <cassert>

#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

/*Union find by path compression and union by ranks*/
int P[5000], R[5000];
void init() {
    for(int i=0;i<5000;i++) {
        P[i]=i;
        R[i]=0;
    }
}
int find(int n) {
    if(P[n] == n) return n;
    return P[n] = find(P[n]);
}
void join(int a, int b) {
    a=find(a);
    b=find(b);
    if(R[a]<R[b]) P[a] = b;
    else {
        P[b] = a;
        if(R[a] == R[b]) R[a]++;
    }
}

typedef pair<int,int> pii;
typedef pair<int,pii> edge;
typedef long long ll;

#define co(e) e.first
#define n1(e) e.second.first
#define n2(e) e.second.second
#define pb push_back

#define all(A) A.begin(), A.end()

int main() {
    int T;
    scanf("%d",&T);
    
    assert(T>=1 && T<=5);
    
    while(T--) {
        int N, M1, M2;
        scanf("%d %d %d",&N,&M1,&M2);
        
        assert(N>=1 && N<=5000);
        assert(M1>=1 && M1<=20000);
        assert(M2>=1 && M2<=20000);
        
        vector<edge> e1, e2;
        for(int i=0;i<M1;i++) {
            int a, b, c;
            scanf("%d %d %d",&a,&b,&c);
            
            assert(a>=0 && a<N && b>=0 && b<N);
            assert(a != b);
            assert(c>=1 && c<=1000000000);
            
            e1.pb(edge(c,pii(a,b)));
        }
        for(int i=0;i<M2;i++) {
            int a, b, c;
            scanf("%d %d %d",&a,&b,&c);
            
            assert(a>=0 && a<N && b>=0 && b<N);
            assert(a != b);
            assert(c>=1 && c<=1000000000);
            
            e2.pb(edge(c,pii(a,b)));
        }
        
        /*Sorting the edges by weights*/
        sort(all(e1));
        sort(all(e2));
        reverse(all(e2));
        
        /*
        Implement the kruskal's algorithm.
        Parse through M2 first.
        Parse through M1 then.
        */
        int cnt=0;
        ll r1=0, r2=0;
        init();
        for(int i=0;i<M2;i++) if( find(n1(e2[i])) != find(n2(e2[i])) ) {
            join(n1(e2[i]),n2(e2[i]));
            r2 += co(e2[i]);
            cnt++;
        }
        for(int i=0;i<M1;i++) if( find(n1(e1[i])) != find(n2(e1[i])) ) {
            join(n1(e1[i]),n2(e1[i]));
            r1 += co(e1[i]);
            cnt++;
        }
        if(cnt < N-1) {
            printf("impossible\n");
        } else {
            assert(cnt == N-1);
            printf("%lld %lld\n",r2,r1+r2);
        }
    }
    return 0;
}
