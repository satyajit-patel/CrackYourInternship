// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
class Solution {
public:
    void state(int s, vector<int> adj[], vector<int>& vis, vector<int>& ans) {
        vis[s] = 1;
        ans.push_back(s);
        for(auto& child: adj[s]) {
            if(!vis[child]) {
                state(child, adj, vis, ans);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        
        vector<int> vis(V, 0);
        state(0, adj, vis, ans);
        
        return ans;
    }
};