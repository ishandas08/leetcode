class Solution {
public:
    void dfs(int i,vector<int>adj[],vector<int>&vis){
        vis[i]=1;
        for(auto it : adj[i]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        vector<int>adj[n];
        for(auto it :connections){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        int component=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                component++;
                dfs(i,adj,vis);
            }
        }
        return component-1;
    }
};