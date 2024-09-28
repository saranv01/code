class Solution {
    public int minElement(int[] nums) {

        int mini=Integer.MAX_VALUE;
        for(int i=0;i<nums.length;i++){
            int j=nums[i];
            int temp=0;
            int ans=0;
            if(j!=0)
            while(j!=0){
                temp=j%10;
                ans+=temp;
                j/=10;
            }
            mini=Math.min(mini,ans);
        }
        return mini;
    }
}