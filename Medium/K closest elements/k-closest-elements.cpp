//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    
    int search(vector<int> arr, int n, int x){
        int s = 0;
        int e = n-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid]==x)
                return mid;
            else if(arr[mid]<x)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return s;
    }
    
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        
        vector<int> ans;
        int pos = search(arr, n, x);
        int i = pos-1;
        int j = pos;
        if(arr[pos]==x)
            j = pos+1;
            
        while(k--){
            if(j>=n || i>=0 && j<n && x-arr[i]<arr[j]-x)
                ans.push_back(arr[i--]);
            else
                ans.push_back(arr[j++]);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends