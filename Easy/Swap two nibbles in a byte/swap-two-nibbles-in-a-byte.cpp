//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int swapNibbles(int n) {
        
        int ans = 0;
        int count = 4;
        int i = 1;
        while(count--){
            ans = (n&1)<<(i++) | ans;
            n = n>>1;
        }
        ans = ans<<3;
        ans = ans|n;
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
        Solution ob;
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends