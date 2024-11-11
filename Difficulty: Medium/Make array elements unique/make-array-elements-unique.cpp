//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        unordered_set<int> s;
        int op = 0;
        int maxi = -1;
        for(auto i: arr){
            int inc = 0;
            if(s.find(i)!=s.end()){
                inc = maxi + 1 - i;
                op += inc;
            }
            maxi = i + inc;
            s.insert(maxi);
        }
        
        
        return op;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends