#include <bits//stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// MACROS
#define int                     long long
#define pb                      push_back
#define MAX                     2e18+5
#define MIN                     -2e18-5
#define mod                     1000000007
#define eps                     1e-9
#define set(x)                  memset(x, 0, sizeof(x))
#define clr(x)                  memset(x, -1, sizeof(x))
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

typedef priority_queue<int>     maxHeap;
typedef priority_queue<int,     vector<int>, greater<int>> minHeap;
typedef pair<int, int>          pii;
typedef vector<int>             vi;
typedef vector<pii>             vpii;
typedef map<int, int>            mpii;
typedef set<int>                seti;
template<typename T> // find_by_order, order_of_key
using pbds = tree<T , null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update>;
template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}
// typedef long long int           ll;

int mpow(int base, int exp);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}


// cout << fixed << setprecision(9) <<
const int N = 1e6 + 5;
int n, m;
int a[200005];
struct node {
	int l, r, i;
};
int block, sum;
int cnt[N], ans[200005];
node queries[200005];
bool cmp(node a, node b) {
	if (a.l / block == b.l / block) return a.r < b.r;
	return a.l / block < b.l / block;
}
void add(int pos) {
	sum -= cnt[pos] * cnt[pos] * pos;
	cnt[pos]++;
	sum += cnt[pos] * cnt[pos] * pos;
}
void remove(int pos) {
	sum -= cnt[pos] * cnt[pos] * pos;
	cnt[pos]--;
	sum += cnt[pos] * cnt[pos] * pos;
}
//https://codeforces.com/problemset/problem/86/D
// https://codeforces.com/contest/86/submission/142002616


void solve() {
	cin >> n >> m;
	rep(i, 1, n + 1) cin >> a[i];
	for (int i = 0; i < m; i++) {
		cin >> queries[i].l >> queries[i].r;
		queries[i].i = i;
	}
	block = sqrt(n) + 1;
	sort(queries, queries + m, cmp);
	int l = 1, r = 0; sum = 0;
	for (int i = 0; i < m; i++) {
		int cur_l = queries[i].l, cur_r = queries[i].r;
		while (l < cur_l) {
			remove(a[l]);
			l++;
		}
		while (l > cur_l) {
			l--;
			add(a[l]);
		}
		while (r < cur_r) {
			r++;
			add(a[r]);
		}
		while (r > cur_r) {
			remove(a[r]);
			r--;
		}
		ans[queries[i].i] = sum;
	}
	rep(i, 0, m) cout << ans[i] << endl;

}


/* TIPS
------------------------------------------------------------------------------------
5. Builtin_popcountll FOR LONG LONG ////////////////////////////////////////////////
1. for interactive prob remove fastio and endl
2. for vector pass as reference
3. dont use set and clr when n * t is very large use loop till n instead.
4. don't forget to clear the graph
5.

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
	// cin >> t;
	for (int i = 1; i <= t; i++) {

		// cout<<"Case #"<<i<<": ";

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
