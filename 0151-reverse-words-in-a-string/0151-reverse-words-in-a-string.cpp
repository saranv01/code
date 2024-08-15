class Solution {
public:
    string reverseWords(string s) {
        string ss="";
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                temp+=s[i];
            }

            if(s[i]==' '&&temp.size()>0){
                while(s[i+1]==' ')i++;
                ss=temp+" "+ss;
                temp="";

            }

        }
        if(temp.size()>0)
        ss=temp+" "+ss;

        if(ss.size()>0&&ss.back()==' ') ss.pop_back();
        return ss;
    }
};