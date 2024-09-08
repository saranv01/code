class MinStack {
public:
    long long minVal;
    stack<long long>stk;
    MinStack() {
     while (stk.empty() == false) stk.pop();
      minVal = INT_MAX;     
        
    }
    
    void push(int val) {
        if(!stk.size()){
            stk.push((long long)val);
            minVal=(long long)val;
        }
        else if(minVal>val){
            long long t= 2*(long long)val-minVal;
            minVal=(long long) val;
            stk.push(t);
        }
        else{
            stk.push((long long)val);
        }
    }
    
    void pop() {
        if(!stk.empty()){
            long long t=stk.top();
            stk.pop();
        if(minVal>t){
            minVal=2*minVal-t;
        }        
        }

    }
    
    int top() {
        if(!stk.empty()){
            long long t=stk.top();
            if(t<minVal){
                return minVal;
            }
            else return stk.top();
        }
        return NULL;
    }
    
    int getMin() {
        if(!stk.empty())return minVal;
        return NULL;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */