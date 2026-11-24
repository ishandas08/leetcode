class Solution {
public:
    vector<int> adj[1001];
    int iscycle(int src, int per, vector<bool>& vis) {
        vis[src] = true;
        for (int v : adj[src]) {
           if(!vis[v]){
                if(iscycle(v,src,vis)){
                    return true;
                }
           }
           else if(v!=per){
            return true;
           }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (int i = 0; i <= 1000; i++) {
            adj[i].clear();
        }
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            vector<bool> vis(edges.size() + 1, false);

            if (iscycle(u, -1, vis)) {
                return {u, v};
            }
        }
        return {};
    }
};