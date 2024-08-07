class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int>ump;
        set <string>ban(banned.begin(),banned.end());

        string temp="";
        for(int i=0;i<=paragraph.length();i++){
            char ch=tolower(paragraph[i]);
            if(!isalpha(ch) || ch=='\0'){
                if(ban.find(temp)==ban.end()&&temp!=""){
                    ump[temp]++;
                }
                temp="";
                continue;
            }

            temp.push_back(ch);
          
        }

        int max=-1;
        string maxi;
        for(auto x:ump){
            if(x.second>max){
                max=x.second;
                maxi=x.first;
            }
        }
        return maxi;
        
    }
};