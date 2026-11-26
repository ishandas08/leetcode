class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<vector<int>>adj(n);
        vector<int>outdegree(n,0);

        for(int i=0;i<n;i++){
            for(int v:graph[i]){
                adj[v].push_back(i);
                outdegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(outdegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int v :adj[node]){
                outdegree[v]--;
                if(outdegree[v]==0){
                    q.push(v);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};