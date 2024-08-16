class Solution {
public:
    int maxDepth(string s) {
        stack<char>stk;
        int maxi=0;
        for(char x:s){
            if(x=='('){
                stk.push('(');
            }
            else if(x==')'){
                stk.pop();
            }
            maxi=max(maxi,(int)stk.size());
        }
        return maxi;
    }
};