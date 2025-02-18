class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int>valueFreq;
        long long goodPairs=0;
        long long n=nums.size();
        long long totalPairs=(n*(n-1))/2;
        for(int i=0;i<n;i++){
            valueFreq[nums[i]-i]++;
        }
        for(auto it:valueFreq){
            if(it.second>1){
                long long temp=it.second;
                goodPairs+=(temp*(temp-1))/2;
            }
        }
        return totalPairs-goodPairs;
    }
};