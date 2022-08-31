// https://leetcode.com/problems/maximum-genetic-difference-query/
class trie{
    class trie *child[2];
    int end;
    public: 
    trie(){
        this->child[0] = this->child[1]=NULL;
        this->end=0;
    }
        void insert(int x){
            auto tmp = this;
            for (int i = 20; i >= 0; i--) {
                int ch = 0;
                if (x & (1 << i)) ch = 1;
                // cout<<i<<" "<<ch<<endl;
                if (tmp->child[ch] == NULL) tmp->child[ch] = new trie();
                // cout<<tmp->end<<endl;
                tmp->end++;
                tmp = tmp->child[ch];
            }
            tmp->end++;
        }
        void remove(int x){
            auto tmp = this;
            for (int i = 20; i >= 0; i--) {
                int ch = 0;
                if (x & (1 << i)) ch = 1;
                if (tmp->child[ch] == NULL) tmp->child[ch] = new trie();
                tmp->end--;
                tmp = tmp->child[ch];
            }
            tmp->end--;
        }
        int query(int x){
            int ans=0;
            auto cur = this;
            for(int i=20; i>=0; i--){
                int idx = 0;
                if(x & (1<<i)) idx=1;
                if(cur->child[1-idx] != NULL and cur->child[1-idx]->end > 0){
                    cur=cur->child[1-idx];
                    ans |= 1<<i;
                }else{
                    cur=cur->child[idx];
                }
            }
            return ans;
        }
};
class Solution {
public:
    void dfs(int i, int p, vector<int> adj[], vector<vector<int>> que[], vector<int> &ans, struct trie root){
        root.insert(i);
        for(auto j: que[i]){
            int val = j[0], idx=j[1];
            ans[idx] = root.query(val);
        }
        for(int j: adj[i]){
            dfs(j, i, adj, que, ans, root);
        }
        root.remove(i);
    }
    vector<int> maxGeneticDifference(vector<int>& par, vector<vector<int>>& queries) {
        int n=par.size(), q=queries.size(), root=-1;
        vector<vector<int>> que[n];
        vector<int> adj[n], ans(q);
        for(int i=0; i<n; i++){
            if(par[i] != -1){
                adj[par[i]].push_back(i);
            }else{
                root=i;
            }
        }
        for(int i=0; i<q; i++){
            int node = queries[i][0], val=queries[i][1];
            que[node].push_back({val, i});
        }
        class trie roott;
        dfs(root, -1, adj, que, ans, roott);
        return ans;
    }
};
