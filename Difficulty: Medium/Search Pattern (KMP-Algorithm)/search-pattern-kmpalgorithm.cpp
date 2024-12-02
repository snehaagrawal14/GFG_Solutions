//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> search(string& pat, string& txt) {
        
        vector<int> ans;
        int n = txt.size();
        int m = pat.size();
        int i = 0;
        // int j = 0;
        // int index = 0;
        string temp;
        // while(i<m){
        //     temp.push_back(txt[i++]);
        // }
        for(;i<m; i++){
            temp.push_back(txt[i]);
        }
        // while(i<n){
        //     if(temp == pat){
        //         ans.push_back(index);
        //     }
        //     index++;
        //     temp.erase(temp.begin());
        //     temp.push_back(txt[i++]);
        // }
        for(;i<n; i++){
            if(temp[0]==pat[0] && temp == pat)
                ans.push_back(i-m);
            temp.erase(temp.begin());
            temp.push_back(txt[i]);
        }
        if(temp == pat){
            ans.push_back(i-m);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends