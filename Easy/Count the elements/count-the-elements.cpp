//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        
        // finding maximum element
        int maxi=INT_MIN;
        int i=0;
        int j=0;
        while(i<n && j<n)
            maxi = max(maxi, max(a[i++], b[j++]));
            
        // creating array of length (maximum element) and initializing with frequency of elements of array b
        vector<int> hash(maxi+1, 0);
        for(auto i: b)
            hash[i]++;
        
        // updating hash
        for(int i=1; i<=maxi; i++)
            hash[i] += hash[i-1];
        
        // creating ans array
        vector<int> ans;
        for(auto i: query){
            int ele = a[i];
            ans.push_back(hash[ele]);
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends