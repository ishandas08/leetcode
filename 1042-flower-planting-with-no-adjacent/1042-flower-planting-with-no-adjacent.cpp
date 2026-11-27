class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>>adj(n+1);
        for(auto it : paths){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n + 1, 0);
        for(int i=0;i<=n;i++){
            bool used[5]={false};
            for(int v:adj[i]){
                used[color[v]]=true;
            }
            for(int c=1;c<=4;c++){
                if(!used[c]){
                    color[i]=c;
                    break;
                }
            }
        }
        color.erase(color.begin());
        return color;
    }
};