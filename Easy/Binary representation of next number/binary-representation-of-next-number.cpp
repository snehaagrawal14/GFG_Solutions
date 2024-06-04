//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        
        int carry = 1;
        int i = s.size()-1;
        while(i>=0 && carry){
            int a = s[i]-'0';
            if(a==1){
                s[i] = '0';
                carry = 1;
            }
            else{
                s[i] = '1';
                carry = 0;
            }
            i--;
        }
        if(carry)
            return to_string(carry)+s;
        i = 0;
        while(i<s.size() && s[i]=='0')
            i++;
        return s.substr(i);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends