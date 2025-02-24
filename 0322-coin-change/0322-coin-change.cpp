class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<vector<int>>memo(amount+1,vector<int>(coins.size(),1e9));
        for(int i=0;i<coins.size();i++){
            memo[0][i]=0;
        }
        for(int i=1;i<=amount;i++){
            if(i%coins[0]==0){
                memo[i][0]=i/coins[0];
            }
            else
            memo[i][0]=1e9;
        }
        for(int amt=1;amt<amount+1;amt++){
            for(int pos=1;pos<coins.size();pos++){
                int pick=1e9;
                if(amt>=coins[pos]){
                    pick=1+memo[amt-coins[pos]][pos];
                }
                int notPick=1e9;
                notPick=0+memo[amt][pos-1];
                memo[amt][pos]= min(pick,notPick);               
            }
        }
        int ans=memo[amount][coins.size()-1];
        if(ans==1e9)return -1;
        return ans;
    }
};