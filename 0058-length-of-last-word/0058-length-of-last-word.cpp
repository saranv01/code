class Solution {
public:
    int lengthOfLastWord(string s) {
        string lastW;

        int j=s.size()-1;
        int i;
        while(s[j]==' '){
            j--;
        }

        for(i=j;i>=0;i--){
            if(s[i]!=' '){
                
            }
            if(s[i]==' '){
                break;
            }
        }
       j++;
       i++;
        return j-i;

    }
};