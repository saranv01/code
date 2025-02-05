class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2)return true;
        int cnt=0;
        char sc1,sc2,tc1,tc2;
        if(s1.length()!=s2.length())return false;
        for(int i=0;i<s1.length();i++){
            if(cnt>2)return false;
            if(cnt==0&&s1[i]!=s2[i]){
                cnt++;
                sc1=s1[i];
                tc1=s2[i];
            }
            else if(cnt==1&&s1[i]!=s2[i]){
                cnt++;
                sc2=s1[i];
                tc2=s2[i];
            }
            else if(s1[i]!=s2[i]){
                cnt++;
            }
        }
        if(cnt>2)return false;
        if(sc1==tc2&&sc2==tc1)return true;
        return false;

    }
};