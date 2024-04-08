//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    
    int solve(int n, int a[], int curr, int prev){
        if(curr==n){
            return 0;
        }
        
        int include=0;
        if(prev==-1 || a[prev]<a[curr]){
            include=1+solve(n, a, curr+1, curr);
        }
        int exclude=solve(n, a, curr+1, prev);
        return max(include, exclude);
    }
    
    
    int solveMem(int n, int a[], int curr, int prev, vector<vector<int>> &dp){
        if(curr==n){
            return 0;
        }
        if(dp[curr][prev+1]!=-1)
        return dp[curr][prev+1];
        
        int include=0;
        if(prev==-1 || a[prev]<a[curr]){
            include=1+solveMem(n, a, curr+1, curr, dp);
        }
        int exclude=solveMem(n, a, curr+1, prev, dp);
        dp[curr][prev+1] = max(include, exclude);
        return dp[curr][prev+1];
    }
    
    
    int solveTab(int n, int a[]){
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int curr=n-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
                int include=0;
                if(prev==-1 || a[prev]<a[curr]){
                    include=1+dp[curr+1][curr+1];
                }
                int exclude=dp[curr+1][prev+1];
                dp[curr][prev+1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
    
    
    
    int solveSpace(int n, int a[]){
        vector<int> nextRow(n+1, 0);
        vector<int> currRow(n+1, 0);
        for(int curr=n-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
                int include=0;
                if(prev==-1 || a[prev]<a[curr]){
                    include=1+nextRow[curr+1];
                }
                int exclude=nextRow[prev+1];
                currRow[prev+1] = max(include, exclude);
            }
            nextRow=currRow;
        }
        return currRow[0];
    }
    
    
    int binarySearch(int n, vector<int> &seq, int x){
        int s=0;
        int e=n-1;
        int index=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(seq[mid]>=x){
                index=mid;
                e=mid-1;
            }
            else
            s=mid+1;
        }
        return index;
    }
    
    
    int dpWithBinarySearch(int n, int a[]){
        vector<int> subSeq;
        for(int i=0; i<n; i++){
            int len=subSeq.size();
            if(subSeq.empty() || subSeq[len-1]<a[i])
            subSeq.push_back(a[i]);
            else{
                int index=binarySearch(len, subSeq, a[i]);
                subSeq[index]=a[i];
            }
        }
        return subSeq.size();
    }
    
    
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        //vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return dpWithBinarySearch(n, a);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends