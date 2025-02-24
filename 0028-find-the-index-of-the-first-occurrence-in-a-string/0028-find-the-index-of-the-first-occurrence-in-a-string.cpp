class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size()<needle.size())return -1;
        for(int i=0;i<haystack.size()-needle.size()+1;i++){
            if(haystack[i]==needle[0]){
                int k=needle.size()-1;
                int i2=1;
                while(k--){
                    if(haystack[(i2)+i]==needle[i2]){
                        i2++;
                    }
                    else{
                        break;
                    }
                }
                if(k==-1)return i;
            }
        }
        return -1;
    }
};