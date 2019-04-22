#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;

// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-9

// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd

// Useful container manipulation / traversal macros
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                   memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair

// Some common useful functions
#define maX(a,b)                    ( (a) > (b) ? (a) : (b))
#define miN(a,b)                    ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)               ( (n >> b) & 1)
#define DREP(a)			    sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)		    (lower_bound(all(arr),ind)-arr.begin())

using namespace std;

#if DEBUG && !ONLINE_JUDGE

    #define debug(args...)     (Debugger()) , args

    class Debugger
    {
        public:
        Debugger(const std::string& _separator = ", ") :
        first(true), separator(_separator){}

        template<typename ObjectType>
        Debugger& operator , (const ObjectType& v)
        {
            if(!first)
                std:cerr << separator;
            std::cerr << v;
            first = false;
            return *this;
        }
        ~Debugger() {  std:cerr << endl;}

        private:
        bool first;
        std::string separator;
    };

    template <typename T1, typename T2>
    inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
    {
        return os << "(" << p.first << ", " << p.second << ")";
    }

    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
    {
        bool first = true;
        os << "[";
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if(!first)
                os << ", ";
            os << v[i];
            first = false;
        }
        return os << "]";
    }

    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::set<T>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
        {
            if(!first)
                os << ", ";
            os << *ii;
            first = false;
        }
        return os << "]";
    }

    template<typename T1, typename T2>
    inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
        {
            if(!first)
                os << ", ";
            os << *ii ;
            first = false;
        }
        return os << "]";
    }

#else
    #define debug(args...)                  // Just strip off all debug tokens
#endif

typedef long long LL;

typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef pair<LL, LL> PLL;

typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<vector<int> > VVI;
typedef vector<VL> VVL;

int ni()
{
    int _num; s(_num);
    return _num;
}

/*-------------------------Main code begins now ------------------------------*/
int testnum;
struct UnionFind
{
    VI dad, mass;
    int N;
    UnionFind(int _N)
    {
        N = _N;
        dad.resize(N);
        mass.resize(N);
        forall(i, 0, N)
            dad[i] = -1, mass[i] = 1;
    }

    int find(int a)
    {
        if(dad[a] < 0) return a;
        return dad[a] = find(dad[a]);
    }

    bool merge(int a, int b)
    {
        int c1 = find(a), c2 = find(b);
        if(c1 != c2)
        {
            N--;
            if(mass[c1] < mass[c2]) swap(c1, c2);
            mass[c1] += mass[c2];
            dad[c2] = c1;
            return true;
        }
        return false;
    }

    int comps()
    {
        return N;
    }
};

typedef pair<int, PII> edge;
#define FROM second.first
#define TO   second.second
#define COST first


void preprocess()
{
    
}
int N, M1, M2;
const int max_edge = 100005;
edge one[max_edge], two[max_edge];

void solve()
{
    UnionFind uf(N);    

    // Sort edges of second type in decreasing order
    sort(two, two + M2);
    reverse(two, two + M2);

    LL profit = 0;

    // Create a max spanning forest of type 2 edges
    forall(i, 0, M2)
    {
        edge e = two[i];
        if(uf.merge(e.FROM, e.TO))
            profit += e.COST;
    }
    LL cost = profit;

    // Sort edges of type 1 in incrasing order of cost
    sort(one, one + M1);

    // Add edges of type 1 to maximal forest created earlier
    forall(i, 0, M1)
    {
        edge e = one[i];
        if(uf.merge(e.FROM, e.TO))
            cost += e.COST;
    }

    if(uf.comps() > 1)
        printf("Impossible\n");
    else
        printf("%lld %lld\n", profit, cost);
}
int cnt = 0;
void check(int &var, int lo, int hi)
{
    assert( s(var) == 1);
    assert( lo <= var && var <= hi);
}

bool input()
{
    int u, v, c;
    check(N, 2, 5000); 
    check(M1, 1, 20000);
    check(M2, 1, 20000);

    forall(e, 0, M1)
    {
        check(u, 0, N-1);
        check(v, 0, N-1);
        assert(u != v);
        check(c, 0, 1000000000);
        one[e] = edge( c, PII(u,v));
    }

    forall(e, 0, M2)
    {
        check(u, 0, N-1);
        check(v, 0, N-1);
        assert( u != v);
        check(c, 0, 1000000000);
        two[e] = edge( c, PII(u,v));
    }
    return true;
}


int main()
{
    preprocess();
    int T = 1;
    check(T, 1, 5);
    for(testnum=1;testnum<=T;testnum++)
    {
        if(!input()) break;
        solve();
    }
}
