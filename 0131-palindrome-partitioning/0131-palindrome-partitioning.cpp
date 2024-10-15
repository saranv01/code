class Solution {
private:
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
public:
    void makePalindromes(string s, int pos, vector<string>& palindrome, vector<vector<string>>&palindromes, int n){
        if(pos==n){
            palindromes.push_back(palindrome);
            return;
        }
        for(int i=pos;i<n;i++){
            if(isPalindrome(s,pos,i)){
            palindrome.push_back(s.substr(pos,i-pos+1));
            makePalindromes(s,i+1,palindrome,palindromes,n);
            palindrome.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>palindrome;
        vector<vector<string>>palindromes;
        makePalindromes(s,0,palindrome,palindromes,s.length());
        return palindromes;
    }
};