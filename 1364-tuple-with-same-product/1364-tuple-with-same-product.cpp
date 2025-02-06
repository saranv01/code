class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>prodfreq;
        int result=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                prodfreq[nums[i]*nums[j]]++;
            }
        }
        for(auto [prodValue, prodFreq]:prodfreq){
            int pairsOfEqualProduct=(prodFreq-1)*prodFreq/2;
            result+=pairsOfEqualProduct*8;
        }
        return result;
    }
};