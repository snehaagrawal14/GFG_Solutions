//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    
    int mod = 1000000007;
    
    int solve(string s1, string s2, int i, int j, vector<vector<int>> &dp){
        if(j==s2.size())
            return 1;
        
        if(i==s1.size())
            return 0;
           
        if(dp[i][j] != -1)
            return dp[i][j];
            
        int ans = 0;
        if(s1[i]==s2[j])
            ans = (ans%mod + solve(s1, s2, i+1, j+1, dp) % mod) % mod;
        ans = (ans%mod + solve(s1, s2, i+1, j, dp) % mod) % mod;
        return dp[i][j] = ans;
    }
    
  public:
    int countWays(string s1, string s2) {
        
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(s1, s2, 0, 0, dp);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends