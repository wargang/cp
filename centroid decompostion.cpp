
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
const int N = 1e5 + 5;
const int M = 20;
int n, q;
seti adj[N];
int depth[N], dp[N][M], sz[N], par[N], ans[N];
// PREPROCESSING
void dfs0(int i, int p) {
	for (int j : adj[i]) {
		if (j == p) continue;
		dp[j][0] = i;
		depth[j] = 1 + depth[i];
		dfs0(j, i);
	}
}
void init(int root) {
	depth[root] = 0;
	dp[root][0] = root;
	dfs0(root, -1);
	for (int j = 1; j < M; j++) {
		for (int i = 1; i <= n; i++) {
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
		}
	}
}
int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	for (int i = M - 1; i >= 0; i--) {
		if (depth[a] - (1ll << i) >= depth[b]) {
			a = dp[a][i];
		}
	}
	if (a == b) return a;
	for (int i = M - 1; i >= 0; i--) {
		if (dp[a][i] != dp[b][i]) {
			a = dp[a][i];
			b = dp[b][i];
		}
	}
	return dp[a][0];
}
int get_dist(int a, int b) {
	return depth[a] + depth[b] - 2 * depth[lca(a, b)];
}
// DECOMPOSITION
int dfs1(int i, int p) {
	sz[i] = 1;
	for (int j : adj[i]) {
		if (j == p) continue;
		dfs1(j, i);
		sz[i] += sz[j];
	}
	return sz[i];
}
int get_centroid(int i, int p, int tmp) {
	for (int j : adj[i]) {
		if (j == p) continue;
		if (sz[j] * 2 > tmp) return get_centroid(j, i, tmp);
	}
	return i;
}
void decompose(int i, int p) {
	int tmp = dfs1(i, p);
	int centr = get_centroid(i, p, tmp);
	par[centr] = p;
	for (int j : adj[centr]) {
		adj[j].erase(centr);
		decompose(j, centr);
	}
}
// QUERIES PART
void update(int st) {
	int cur = st;
	while (cur != -1) {
		ans[cur] = min(ans[cur], get_dist(st, cur));
		cur = par[cur];
	}
}
int query(int st) {
	int cur = st, anss = MAX;
	while (cur != -1) {
		anss = min(anss, ans[cur] + get_dist(st, cur));
		cur = par[cur];
	}
	return anss;
}

void wargang() {
	cin >> n >> q;
	rep(i, 0, n - 1) {
		int a, b;
		cin >> a >> b;
		adj[a].insert(b);
		adj[b].insert(a);
	}
	init(1);
	decompose(1, -1);
	rep(i, 1, n + 1) ans[i] = MAX;
	update(1);
	while (q--) {
		int type, i;
		cin >> type >> i;
		if (type == 1) {
			update(i);
		} else {
			int ans = query(i);
			cout << ans << endl;
		}
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

