class Solution {
public:
    vector<string> letterCombinations(string digits) {
            if(digits.size()<1)return{};
            vector<string>buttons={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
            vector<string>ans={""};
            for(auto digit:digits){
                vector<string>temp;
                for(auto letter:buttons[digit-'0'-2]){
                    for(auto it:ans){
                        temp.push_back(it+letter);
                    }
  
                }
                ans=temp;
            }

            return ans;
    }
};