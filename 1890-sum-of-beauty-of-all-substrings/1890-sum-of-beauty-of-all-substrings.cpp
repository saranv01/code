class Solution {
public:
    int helper(string s){
        int arr[26]={0};
        for(char x:s){
            arr[x-'a']++;
        }
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i:arr){
            if(i<mini&&i>0){
                mini=i;
            }
            if(i>maxi){
                maxi=i;
            }
        }
        if(mini==INT_MAX) return 0;
        return maxi-mini;
    }
    int beautySum(string s) {
        int cnt=0;
        for(int i=0;i<s.size();i++){
            string temp="";
            for(int j=i;j<s.size();j++){
                temp+=s[j];
                cnt+=helper(temp);
            }
        }

        return cnt;
    }
};