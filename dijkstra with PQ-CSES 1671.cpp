// --------------------------------------------------<C++ TEMPLATE>------------------------------------------------
/**
    *  Nitin Gangwar
    *  @wargang (codechef,codeforces,spoj,gfg)
    *  MNNIT allahabad
    *  CSE'23
    *  iamnitingangwar2000@gmail.com
**/

#include <bits//stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// MACROS
#define int                     long long
#define mp                      make_pair
#define pb                      push_back
#define MAX                     1e17
#define MIN                     -1e17
#define PI                      3.1415926535897932384626433832795
#define mod                     1000000007
#define set(x)                  memset(x, 0, sizeof(x))
#define clr(x)                  memset(x, -1, sizeof(x))
#define ff                      first
#define ss                      second
#define rep(i,n)                for(int i=0;i<(n);i++)
#define FOR(i,a,b)              for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)             for(int i=(a);i>=(b);i--)
#define test()                  int t;cin>>t;while(t--)
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
// typedef long int                ld;
// typedef unsigned long int       lu;
// typedef long long int           ll;
// typedef unsigned long long int  llu;


// cout << fixed << setprecision(9) <<
int mpow(int base, int exp);

const int T2 = 105; const int T3 = 1005; const int T4 = 10005; const int T5 = 100005;
const int N = 1e5 + 5;
int n, m;
vpii adj[N];
vi dist(N);
vector<bool> vis(N);

void dijkstra(int src) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist.assign(n + 1, MAX);
    dist[src] = 0;
    pq.push({0, src});

    while (pq.size()) {
        auto t = pq.top();
        pq.pop();
        int v = t.ss, d = t.ff;

        if (vis[v]) continue;
        vis[v] = 1;

        for (auto i : adj[v]) {
            int vertex = i.ff, cost = i.ss;

            if (dist[vertex] > dist[v] + cost) {
                dist[vertex] = dist[v] + cost;
                pq.push({dist[vertex], vertex});
            }
        }
    }
}


void solve() {
    cin >> n >> m;
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
    }
    dijkstra(1);
    rep(i, n) cout << dist[i + 1] << " ";
}




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
    // cin >> t;
    for (int i = 1; i <= t; i++) {

        // cout<<"Case #"<<i<<": ";

        solve();


    }
    return 0;
}

