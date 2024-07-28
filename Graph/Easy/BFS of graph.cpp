// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
class Solution {
public:
    void bfs(int s, vector<int> adj[], vector<int>& vis, vector<int>& ans) {
        vis[s] = 1;
        queue<int> q;
        q.push(s);
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            // cout<<node<<"->";
            ans.push_back(node);
            
            for(auto& child: adj[node]) {
                if(!vis[child]) {
                    vis[child] = 1;
                    q.push(child);
                }
            }
        }
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        
        vector<int> vis(V, 0);
        bfs(0, adj, vis, ans);
        return ans;
    }
};