class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
     
        int n=tickets.size();
        int ans=0;
        while(tickets[k]!=0){
            for(int i=0; i<n; i++){
                if(tickets[k]==0)
                    break;
                else if(tickets[i]>0){
                    tickets[i]--;
                    ans++;
                }
            }
        }
        
        return ans;
        
    }
};