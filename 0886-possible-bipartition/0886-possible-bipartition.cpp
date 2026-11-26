class Solution {
public:
    bool bfs(int src,vector<vector<int>>&adj,vector<int>&color){
        queue<int>q;
        q.push(src);
        color[src]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int v:adj[node]){
                if(color[v]==-1){
                    color[v]=1-color[node];
                    q.push(v);
                }
                else if(color[v]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto it :dislikes){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        vector<int>color(n+1,-1);
        for(int i=0;i<=n;i++){
            if(color[i]==-1){
                if(bfs(i,adj,color)==false){
                    return false;
                }
            }
        }
        return true;
    }
};