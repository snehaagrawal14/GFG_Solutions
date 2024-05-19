//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    
    int search(int arr[], int n, int k){
        int s = 0;
        int e = n-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid]==k)
                return mid;
            else if(arr[mid]<k)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return s;
    }
    
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        
        int pos = search(arr, n, k);
        if(arr[pos]-k < k-arr[pos-1])
            return arr[pos];
        else if(arr[pos]-k > k-arr[pos-1])
            return arr[pos-1];
        else
            return arr[pos];
        
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends