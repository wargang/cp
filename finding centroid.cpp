
// wargang

// The Harder You Work, the Luckier You Get


#include <bits//stdc++.h>
using namespace std;

// MACROS
#define int                     long long
#define pb                      push_back
#define MAX                     2e18+5
#define MIN                     -2e18-5
#define mod                     1000000007
#define eps                     1e-9
#define set(x)                  memset(x, 0, sizeof(x))
#define ff                      first
#define ss                      second
#define rep(i,a,b)              for(int i=a;i<b;i++)
#define sz(x)                   (int)x.size()
#define endl                    "\n"
#define deb(x)                  cout << #x << "=" << x << endl
#define deb2(x, y)              cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z)           cout << #x << "=" << x << "," << #y << "=" << y<< "," << #z << "=" << z << endl
#define deb4(x, y, z, a)        cout << #x << "=" << x << "," << #y << "=" << y<< "," << #z << "=" << z << "," << #a << "=" << a << endl
#define all(x)                  x.begin(), x.end()

typedef pair<int, int>          pii;
typedef vector<int>             vi;
typedef vector<pii>             vpii;
typedef map<int, int>            mpii;
typedef set<int>                seti;
template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}

int mpow(int base, int exp);


// cout << fixed << setprecision(9) <<
const int N = 3e5 + 5;
int n;
int sz[N];
vi adj[N];
void dfs(int i, int p) {
	sz[i] = 1;
	for (int j : adj[i]) {
		if (j == p) continue;
		dfs(j, i);
		sz[i] += sz[j];
	}
}
int centroid(int i, int p) {
	for (int j : adj[i]) {
		if (j == p) continue;
		if (sz[j] > (n / 2)) return centroid(j, i);
	}
	return i;
}

void wargang() {
	cin >> n;
	rep(i, 0, n - 1) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1, 0);
	int ans = centroid(1, 0);
	cout << ans;
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

		wargang();


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

