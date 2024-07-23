class Solution {
public:
    string losingPlayer(int x, int y) {
        bool flag=true;
        while(x>0&&y>=4){
        x=x-1;
        y=y-4;
        flag=!flag;
        }
        if(flag)return "Bob";
        return "Alice";

        
    }
};