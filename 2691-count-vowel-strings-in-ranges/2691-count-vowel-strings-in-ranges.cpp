class Solution {
public:
    bool isVowel(char a){
        return (a=='a'||a=='e'||a=='i'||a=='o'||a=='u'); 
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        vector<int>ans(queries.size(),0);
        vector<int>prefixSums(words.size()+1,0);
        for(int i=1;i<=words.size();i++){
            if(isVowel(words[i-1][0])&&isVowel(words[i-1][(words[i-1].size()-1)])){
                prefixSums[i]=prefixSums[i-1]+1;
            }
            else
            prefixSums[i]=prefixSums[i-1];
        }

        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            ans[i]=prefixSums[r+1]-prefixSums[l];

        }
        return ans;
    
    }
};