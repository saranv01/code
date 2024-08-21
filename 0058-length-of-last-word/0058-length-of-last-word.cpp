class Solution {
public:
    int lengthOfLastWord(string s) {
        int j=s.size()-1;
        int i;
        while(s[j]==' '){
            j--;
        }
        for(i=j;i>=0;i--){
            if(s[i]==' '){
                break;
            }
        }
        return j-i;
    }
};