class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>stk;

        int result=0;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="/"||tokens[i]=="*"){
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                char e=tokens[i][0];
                switch(e){
                    case '+':
                        result=y+x;
                        break;
                    case '-':
                        result=y-x;
                        break;
                    case '*':
                        result=y*x;
                        break;
                    case '/':
                        result=y/x;
                        break;
                }
                stk.push(result);

            }
            else{
                int a=stoi(tokens[i],nullptr,10);
                if (tokens.size()==1)return stoi(tokens[0]);
                stk.push(a);
            }
        }
        return result;
    }
};