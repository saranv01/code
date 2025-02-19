class Solution {
public:
    string getHappyString(int n, int k) {
        queue<string>q;
        int tempk=k;
        q.push("a");
        q.push("b");
        q.push("c");
        while(!q.empty()){
            string current=q.front();
            q.pop();
            if(current.length()<=n){
                if(current.length()==n){
                    tempk--;
                    if(tempk==0) return current;
                    continue;
                }
                if(current.back()=='a'){
                    q.push(current+"b");
                    q.push(current+"c");
                }
                else if(current.back()=='b'){
                    q.push(current+"a");
                    q.push(current+"c");
                }
                else if(current.back()=='c'){
                    q.push(current+"a");
                    q.push(current+"b");
                }                
            }

        }
        return "";
    }
};