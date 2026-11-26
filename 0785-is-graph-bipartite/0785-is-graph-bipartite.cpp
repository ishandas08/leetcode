class Solution {
public:
    bool bfs(int src,vector<vector<int>>&graph,vector<int>&color){
        queue<int>q;
        q.push(src);
        color[src]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int v:graph[node]){
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
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(bfs(i,graph,color)==false){
                    return false;
                }
            }
        }
        return true;
    }
};