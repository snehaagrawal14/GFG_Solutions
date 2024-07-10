//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
    int solve(vector<vector<int>> mat, int i, int j, int &ans){
        if(i>=mat.size() || j>=mat[0].size())
        return 0;
        
        int right=solve(mat, i, j+1, ans);
        int diagonal=solve(mat, i+1, j+1, ans);
        int down=solve(mat, i+1, j, ans);
        
        if(mat[i][j]==1){
            int temp=1 + min(right, min(diagonal, down));
            ans=max(ans, temp);
            return temp;
        }
        else
        return 0;
    }
    
    
    int solveMem(vector<vector<int>> mat, int i, int j, int &ans, vector<vector<int>> &dp){
        if(i>=mat.size() || j>=mat[0].size())
        return 0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        int right=solveMem(mat, i, j+1, ans, dp);
        int diagonal=solveMem(mat, i+1, j+1, ans, dp);
        int down=solveMem(mat, i+1, j, ans, dp);
        
        if(mat[i][j]==1){
            dp[i][j]=1 + min(right, min(diagonal, down));
            ans=max(ans, dp[i][j]);
            return dp[i][j];
        }
        else
        return 0;
    }
    
    
    int solveTab(vector<vector<int>> mat, int n, int m){
        int ans=0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(mat[i][j]==1){
                    int right=(j+1<m) ? dp[i][j+1] : 0;
                    int down=(i+1<n) ? dp[i+1][j] : 0 ;
                    int diagonal=(i+1<n && j+1<m) ? dp[i+1][j+1] : 0;
                    dp[i][j]= 1 + min(right, min(down, diagonal));
                    ans=max(ans, dp[i][j]);
                }
                else
                dp[i][j]=0;
            }
        }
        return ans;
    }
    
    
    int solveSpace(vector<vector<int>> mat, int n, int m){
        int ans=0;
        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(mat[i][j]==1){
                    int right=(j+1<m) ? curr[j+1] : 0;
                    int down=(i+1<n) ? next[j] : 0;
                    int diagonal=(i+1<n && j+1<m) ? next[j+1] : 0;
                    curr[j]=1 + min(right, min(down, diagonal));
                    ans=max(ans, curr[j]);
                }
                else
                curr[j]=0;
            }
            next=curr;
        }
        return ans;
        
    }
    
    
    
    

    int solveInM(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxSide = 0;
        int prev = 0;
        vector<int> dp(cols, 0);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int temp = dp[j];
                if (i == 0 || j == 0) {
                    dp[j] = matrix[i][j];
                }
                else if (matrix[i][j] == 1) {
                    dp[j] = min(min(dp[j], dp[j-1]), prev) + 1;
                }
                else {
                    dp[j] = 0;
                }
                maxSide = max(maxSide, dp[j]);
                prev = temp;
            }
        }
        return maxSide;
    }
    
    
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        //int ans=0;
        //vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        //int x=solve(mat, 0, 0, ans, dp);
        //return ans;
        return solveInM(mat);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends