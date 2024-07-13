//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        // create adjacency list
        map<int, list<pair<int, int>>> adj;
        for(auto i: edges){
            int u = i[0];
            int v = i[1];
            int w = i[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<int> dist(n+1, INT_MAX); // for storing distance
        vector<int> parent(n+1, -1); // to track path
        set<pair<int, int>> s; // to keep track of minimum dist
        s.insert({0, 1});
        dist[1] = 0;
        while(!s.empty()){
            auto it = s.begin();
            int u = (*it).second;
            if(u==n)
                break;
            s.erase(s.begin());
            for(auto v: adj[u]){
                if(dist[v.first] > dist[u] + v.second){
                    dist[v.first] = dist[u] + v.second;
                    s.insert({dist[v.first], v.first});
                    parent[v.first] = u;
                }
            }
        }
        
        // for storing ans
        vector<int> ans;
        if(dist[n]!=INT_MAX){
            int path = n;
            while(path!=0){
                ans.push_back(path);
                path = parent[path];
            }
            ans.push_back(dist[n]);
            reverse(ans.begin(), ans.end());
        }
        else{
            ans.push_back(-1);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends