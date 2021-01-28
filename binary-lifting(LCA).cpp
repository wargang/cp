
#include <bits//stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// MACROS
#define int                     long long
#define pb                      push_back
#define MAX                     1e17
#define MIN                     -1e17
#define PI                      3.1415926535897932384626433832795
#define mod                     1000000007
#define eps                     1e-9
#define set(x)                  memset(x, 0, sizeof(x))
#define clr(x)                  memset(x, -1, sizeof(x))
#define ff                      first
#define ss                      second
#define rep(i,a,b)              for(int i=a;i<b;i++)
#define sz(x)                   x.size()
#define endl                    "\n"
#define deb(x)                  cout << #x << "=" << x << endl
#define deb2(x, y)              cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x)                  x.begin(), x.end()
#define lb(a,x)                 lower_bound(all(a),x)
#define ub(a,x)                 upper_bound(all(a),x)

typedef priority_queue<int>     maxHeap;
typedef priority_queue<int,     vector<int>, greater<int>> minHeap;
typedef pair<int, int>          pii;
typedef vector<int>             vi;
typedef vector<string>          vs;
typedef vector<pii>             vpii;
typedef vector<vi>              vvi;
typedef map<int, int>            mpii;
typedef set<int>                seti;
typedef multiset<int>           mseti;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}
// typedef long int                ld;
// typedef unsigned long int       lu;
// typedef long long int           ll;
// typedef unsigned long long int  llu;


// cout << fixed << setprecision(9) <<
int mpow(int base, int exp);

const int T2 = 105; const int T3 = 1005; const int T4 = 10005; const int T5 = 100005;
const int N = 3e3;

int n, q, zee;
vi lvl(N);

void dfs(int u, int p, vvi &memo, vi adj[]) {
    memo[u][0] = p;
    for (int i = 1; i <= zee; i++) {
        memo[u][i] = memo[memo[u][i - 1]][i - 1];
    }
    for (int v : adj[u]) {
        if (v != p) {
            lvl[v] = lvl[u] + 1;
            dfs(v, u, memo, adj);
        }
    }
}

int lca(int u, int v, vvi &memo, vi adj[]) {
    if (lvl[u] < lvl[v]) swap(u, v);

    for (int i = zee; i >= 0; i--) {
        if (lvl[u] - (1ll << i) >= lvl[v])
            u = memo[u][i];
    }

    if (u == v) return v;
    for (int i = zee; i >= 0; i--) {
        if (memo[u][i] != memo[v][i]) {
            u = memo[u][i];
            v = memo[v][i];
        }
    }
    return memo[u][0];

}


void solve() {
    cin >> n;
    vi adj[n + 1];
    rep(i, 0, n) {
        int x;
        cin >> x;
        while (x--) {
            int y;
            cin >> y;
            adj[i + 1].pb(y);
            adj[y].pb(i + 1);
        }
    }
    zee = (int)ceil(log2(n));
    vvi memo(n + 1, vi(zee + 1, -1));
    lvl.assign(n + 1, 0);
    dfs(1, 1, memo, adj); //   remember its always dfs(root, root) <=======
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v, memo, adj) << endl;
    }





}


/* TIPS
1. for interactive prob remove fastio and endl
2. for vector pass as reference
3.

*/



int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {

        cout << "Case " << i << ":\n";

        solve();


    }
    return 0;
}

int mpow(int base, int exp) {
    base %= mod;
    int result = 1;
    while (exp > 0) {
        if (exp & 1) result = ((int)result * base) % mod;
        base = ((int)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

