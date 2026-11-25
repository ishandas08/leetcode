class Solution {
public:
    vector<vector<int>>adj;
    bool dfs(int curr,vector<vector<int>>&adj,vector<bool>&vis,vector<bool>& pathVis,stack<int>&st){
        vis[curr]=true;
        pathVis[curr] = true;
        for(int v:adj[curr]){
            if(!vis[v]){
                if(dfs(v,adj,vis,pathVis,st)){
                    return true;
                }
            }
            else if(pathVis[v]){
                return true;
            }
        }
        pathVis[curr]=false;
        st.push(curr);
        return false;
    }
    vector<int>toposort(int numCourses,vector<vector<int>>&adj){
        vector<bool>vis(numCourses,false);
        vector<bool> pathVis(numCourses, false);
        stack<int>st;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathVis,st)){
                    return {};
                }
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adj.assign(numCourses,{});
        for(auto edge :prerequisites){
            int u=edge[0];
            int v=edge[1];
            adj[v].push_back(u);
        }
         return toposort(numCourses,adj);
    }
};