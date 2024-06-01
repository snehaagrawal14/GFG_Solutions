//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        
        int x = 0;
        int y = 0;
        int freq[26] = {0};
        for(auto i: s){
            freq[i-'a']++;
        }
        
        for(int i=0; i<26; i+=2){
            if(freq[i]>0 && freq[i]%2!=0)
                y++;
            if(freq[i+1]>0 && freq[i+1]%2==0)
                x++;
        }
        
        if((x+y)%2==0)
            return "EVEN";
        else
            return "ODD";
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends