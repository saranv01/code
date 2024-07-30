class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> s1;
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                s1.push_back(tolower(s[i]));
            }
        }
        for(int i=0;i<s1.size()/2;i++){
 
            if(s1[i]!=s1[s1.size()-i-1]){
          
                return false;
            }
        }
        return true;
    }
};