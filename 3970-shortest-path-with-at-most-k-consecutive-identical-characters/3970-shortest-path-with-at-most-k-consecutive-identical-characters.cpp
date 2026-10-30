
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        
        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty()) {

            auto [d, node, cnt] = pq.top();
            pq.pop();

            if(d != dist[node][cnt]) continue;

            if(node == n - 1) return d;

            for(auto &it : adj[node]) {

                int nbr = it.first;
                int wt = it.second;

                int newCnt;

                if(labels[node] == labels[nbr]) {
                    newCnt = cnt + 1;
                }
                else {
                    newCnt = 1;
                }

                if(newCnt > k) continue;

                if(d + wt < dist[nbr][newCnt]) {
                    dist[nbr][newCnt] = d + wt;
                    pq.push({d + wt, nbr, newCnt});
                }
            }
        }

        return -1;
    }
};
