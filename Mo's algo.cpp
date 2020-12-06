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
#define mp                      make_pair
#define pb                      push_back
#define MAX                     1e9
#define MIN                     -1e9
#define PI                      3.1415926535897932384626433832795
#define MOD                     1000000007
#define SET(x)                  memset(x, 0, sizeof(x))
#define CLR(x)                  memset(x, -1, sizeof(x))
#define ff                      first
#define ss                      second
#define REP(i,n)                for(int i=0;i<(n);i++)
#define FOR(i,a,b)              for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)             for(int i=(a);i>=(b);i--)
#define test()                  int t;cin>>t;while(t--)
#define endl                    "\n"


typedef priority_queue<int>     maxHeap;
typedef priority_queue<int,     vector<int>, greater<int>> minHeap;
typedef pair<int, int>          pii;
typedef vector<int>             vi;
typedef vector<string>          vs;
typedef vector<pii>             vii;
typedef vector<vi>              vvi;
typedef map<int,int>            mpii;
typedef set<int>                seti;
typedef multiset<int>           mseti;
typedef long int                ld;
typedef unsigned long int       lu;
typedef long long int           ll;
typedef unsigned long long int  llu;

const int T2=105; const int T3=1005; const int T4=10005; const int T5=100005;

struct Node {
	int L,R,idx;
};
int block;
int freq[5000005]={0}, ans[400005]={0};
bool comp(Node a, Node b){
	if(a.L/block != b.L/block)
	return a.L/block<b.L/block;
	
	return a.R<b.R;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    {
        int N;
        cin>>N;
        int arr[N+5];
        REP(i,N) cin>>arr[i];
        
        
        int M;
        cin>>M;
        Node query[M+5];
        REP(i,M){
        	int L,R;
        	cin>>L>>R;
        	L--,R--;
        	query[i].L=L,query[i].R=R,query[i].idx=i;
        }
        block = (int)sqrt(N);
        sort(query, query+M, comp);
        int currL=0, currR=-1, sum=0;
        REP(i,M){
        	int L=query[i].L,R=query[i].R;
        	while(currR<R){
        		currR++;
        		freq[arr[currR]]++;
        		if(freq[arr[currR]]==1)
        		sum++;
        	}
        	while(currL<L){
        		freq[arr[currL]]--;
        		if(freq[arr[currL]]==0)
        		sum--;
        		currL++;
        	}
        	while(currR>R){
        		freq[arr[currR]]--;
        		if(freq[arr[currR]]==0)
        		sum--;
        		currR--;
        	}
        	while(currL>L){
        		currL--;
        		freq[arr[currL]]++;
        		if(freq[arr[currL]]==1)
        		sum++;
        	}
        	ans[query[i].idx] = sum;
        }
        REP(i,M)
        cout<<ans[i]<<endl;
        
    }
    return 0;
}
