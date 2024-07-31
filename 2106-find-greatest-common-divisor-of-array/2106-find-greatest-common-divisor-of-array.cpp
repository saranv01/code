class Solution {
public:
    int findGCD(vector<int>& nums) {
       int A = *max_element(nums.begin(), nums.end());
       int B = *min_element(nums.begin(), nums.end());
       int q,r;
       while(B){
        q=A/B;
        r=A%B;
        A=B;
        B=r;
       }    
       return A;   
    }
};