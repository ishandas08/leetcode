class Solution {
public:
    vector<vector<int>>adj;
    bool isCycledfs(int src,vector<bool>&vis,vector<bool>&pathVis){
        vis[src]=true;
        pathVis[src]=true;
        for(int v:adj[src]){
            if(!vis[v]){
                if(isCycledfs(v,vis,pathVis)){
                    return true;
                }
            }
            else if(pathVis[v]){
                return true;
            }
        }
        pathVis[src]=false;
        return false;
    }
    bool iscycle(int num){
        vector<bool>vis(num,false);
        vector<bool>pathVis(num,false);
        for(int i=0;i<num;i++){
            if(!vis[i]){
                if(isCycledfs(i,vis,pathVis)){
                    return true;
                }
            }
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.assign(numCourses,{});
        for(auto edge :prerequisites){
            int u=edge[0];
            int v=edge[1];
            adj[v].push_back(u);
        }
        if(iscycle(numCourses)){
            return false;
        }
        return true;
    }
};