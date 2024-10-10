class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int largest[nums.size()]; int smallest[nums.size()];

        int maxi=0;

        smallest[0]=nums[0]; largest[nums.size()-1]=nums[nums.size()-1];
        for(int i=1;i<nums.size();i++){
            smallest[i]=min(smallest[i-1],nums[i]);
        }
        for(int i=nums.size()-2;i>=0;i--){
            largest[i]=max(largest[i+1],nums[i]);
        }
        int i=0; int j=0; 
        while(i<nums.size()&&j<nums.size()){
            if(smallest[i]<=largest[j]){
                maxi=max(maxi,j-i);
                j++;
            }
            else{
                i++;
            }
        }
        return maxi;
    
    }
};