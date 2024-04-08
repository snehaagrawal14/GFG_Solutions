//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    
    int solve(int i, int j, bool myChance, int arr[], vector<vector<int>> &dp){
        if(i>j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        int ans=0;
        
        if(myChance){
            int a=arr[i] + solve(i+1, j, false, arr, dp);
            int b=arr[j] + solve(i, j-1, false, arr, dp);
            ans+=max(a,b);
        }
        else{
            int a=solve(i+1, j, true, arr, dp);
            int b=solve(i, j-1, true, arr, dp);
            ans+=min(a,b);
        }
        
        return dp[i][j]=ans;
        
    }
    
    public:
    long long maximumAmount(int n, int arr[]){
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n-1, true, arr, dp);
        
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends