// --------------------------------------------------<C++ TEMPLATE>------------------------------------------------
/**
    *  Nitin Gangwar
    *  @wargang (codechef,codeforces,spoj,gfg)
    *  MNNIT allahabad
    *  CSE'23
    *  iamnitingangwar2000@gmail.com
**/

#include <bits//stdc++.h>
using namespace std;

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
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()


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
// typedef long int                ld;
// typedef unsigned long int       lu;
// typedef long long int           ll;
// typedef unsigned long long int  llu;


// cout << fixed << setprecision(9) <<
int mpow(int base, int exp);

const int T2 = 105; const int T3 = 1005; const int T4 = 10005; const int T5 = 100005;
const int N = 16;

int arr[N], allmask, dp[1 << N][N], times[1 << N][N], n;

int ways(int mask, int last) {
    if (dp[mask][last] != -1)
        return dp[mask][last];
    else {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) continue;
            if ((mask | (1 << i)) == ((1 << n) - 1)) {
                dp[mask][last] = abs(arr[last] - arr[i]) + arr[i];
                times[mask][last] = 1;
                return dp[mask][last];
            } else {
                int val = abs(arr[i] - arr[last]) + ways(mask | 1 << i, i);
                if (val > dp[mask][last]) {
                    times[mask][last] = 0;
                    dp[mask][last] = val;
                }
                if (val == dp[mask][last]) {
                    times[mask][last] += times[mask | 1 << i][i];
                }
            }
        }
        return dp[mask][last];
    }
}


void solve() {
    while (1) {
        cin >> n;
        if (n == 0) break;
        memset(dp, -1, sizeof dp);
        memset(times, 0, sizeof times);
        rep(i, n) cin >> arr[i];
        allmask = (1 << n) - 1;
        int ans = 0;
        int t = 0;
        int cc = 0;
        for (int i = 0; i < n; i++) {
            t = max(t, arr[i] + ways(1 << i, i) );
            if (t > ans) {
                ans = t;
                cc = times[1 << i][i];
            } else if (ans == t) {
                cc += times[1 << i][i];
            }
        }
        cout << ans + 2 * n << " " << cc << endl;
    }

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
