#include <bits//stdc++.h>
using namespace std;

// MACROS
#define int                     long long
#define mp                      make_pair
#define pb                      push_back
#define MAX                     1e9
#define MIN                     -1e9
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


const int T2 = 105; const int T3 = 1005; const int T4 = 10005; const int T5 = 100005;
const int N = 3e5;

int dp[20][500][5];

int dig(int i, int n, int sum, int flag, vi limit) {
    if (i == n)
        return sum;
    if (dp[i][sum][flag] != -1)
        return dp[i][sum][flag];
    int lim = 9;
    if (flag)
        lim = limit[i];
    int ans = 0;
    for (int j = 0; j <= lim; j++) {
        if ( j < lim)
            ans += dig(i + 1, n, sum + j, 0, limit);
        else
            ans += dig(i + 1, n, sum + j, flag, limit);
    }
    if (!flag)
        return dp[i][sum][flag] = ans;
    return ans;
}

void solve() {
        int a, b;
        cin >> a >> b;
        int a1 = a - 1, a2 = b;
        vi one, two;
        while (a1 > 0) {
            int rem = a1 % 10;
            one.pb(rem);
            a1 /= 10;
        }
        while (a2 > 0) {
            int rem = a2 % 10;
            two.pb(rem);
            a2 /= 10;
        }
        reverse(all(one)); reverse(all(two));
        clr(dp);
        int ans1 = dig(0, one.size(), 0, 1, one);
        
        clr(dp);
        int ans2 = dig(0, two.size() , 0, 1, two);
        cout << ans2 - ans1 << endl;

}


int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {

        solve();
    }
    return 0;
}


