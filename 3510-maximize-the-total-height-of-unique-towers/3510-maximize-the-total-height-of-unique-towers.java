class Solution {
    public long maximumTotalSum(int[] maximumHeight) {
        int n=maximumHeight.length;
        Arrays.sort(maximumHeight);
        long ans=0;
        int temp;
        int maxi=maximumHeight[n-1];
        for(int j=n-1;j>=0;j--){
            temp=maximumHeight[j];
            maxi=Math.min(temp,maxi);
            if(maxi<=0)return -1;
            ans+=maxi;
            maxi--;
        }
        return ans;
    }
}