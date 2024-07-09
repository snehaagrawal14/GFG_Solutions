//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        
        int n = arr.size();
        int mini = INT_MAX;
        int ans = INT_MIN;
        sort(arr.begin(), arr.end());
        for(int i=0; i<n-2; i++){
            int s = i + 1;
            int e = n - 1;
            while(s<e){
                int sum = arr[i]+arr[s]+arr[e];
                if(sum == target)
                    return target;
                else if(sum > target){
                    if(mini > sum-target){
                        mini = sum-target;
                        ans = sum;
                    }
                    else if(mini == sum-target)
                        ans = max(ans, sum);
                    e--;
                }
                else{
                    if(mini > target-sum){
                        mini = target-sum;
                        ans = sum;
                    }
                    else if(mini == sum-target)
                        ans = max(ans, sum);
                    s++;
                }
            }
        }
        return ans;
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends