class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
     stack<int>stk;
     vector<int>res;
     for(int i=0;i<asteroids.size();i++){
        if(asteroids[i]>0){
            stk.push(asteroids[i]);
        }
        else{
            while(!stk.empty()&&stk.top()<abs(asteroids[i])){
                stk.pop();
            }
            if(!stk.empty()&&stk.top()>=abs(asteroids[i])){
                if(stk.top()==abs(asteroids[i])){
                    stk.pop();
                }
                continue;
            }

            if(stk.empty())res.push_back(asteroids[i]);
        }
     }  

     stack<int>forReverse;

     while(!stk.empty()){
        forReverse.push(stk.top());
        stk.pop();
     }
     while(!forReverse.empty()){
        res.push_back(forReverse.top());
        forReverse.pop();
     }
     return res;
    }
};