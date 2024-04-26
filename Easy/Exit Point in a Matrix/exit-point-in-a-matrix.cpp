//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        
        // it will keep track of current position
        int i=0;
        int j=0;
        
        // prev_ i and prev_ j keeps the track of last position from where we leave our matrix.
        int prev_i=0;
        int prev_j=0;
        
        char direction='R'; // for keeping track of direction in which we are moving.
        
        // if we are inside matrix
        while(i>=0 && j>=0 && i<n && j<m){
            prev_i = i;
            prev_j = j;
            
            // if we encounter 0 then we are moving in same direction.
            if(matrix[i][j]==0){
                if(direction=='R'){
                    j++;
                }
                else if(direction=='D'){
                    i++;
                }
                else if(direction=='L'){
                    j--;
                }
                else{
                    i--;
                }
            }
            
            // if we encounter 1 we are changing it into 0 and change the direction to right of currect direction.
            else{
                matrix[i][j] = 0;
                if(direction=='R'){
                    direction='D';
                    i++;
                }
                else if(direction=='D'){
                    direction='L';
                    j--;
                }
                else if(direction=='L'){
                    direction='U';
                    i--;
                }
                else{
                    direction='R';
                    j++;
                }
            }
        }
        
        
        return {prev_i, prev_j};
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends