class Solution {
public:
    bool isValid(string s) {
      stack<char>stk;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                stk.push(s[i]);
            }
            else if(stk.empty())return 0;
            else {
                if(s[i]==')'){
                    if(stk.top()=='(')stk.pop();
                    else return 0;
                }
                if(s[i]==']'){
                    if(stk.top()=='[')stk.pop();
                    else return 0;
                }
                if(s[i]=='}'){
                    if(stk.top()=='{')stk.pop();
                    else return 0;
                }                
            }
        }
        if(stk.size()==0)
        return 1;    
        return 0;
    }
};
