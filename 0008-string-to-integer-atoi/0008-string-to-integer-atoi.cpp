class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int sig=0;
        long long res=0;
        while(s[i]==' '){
            i++;
        }
            if(s[i]=='-'){
            sig=1;
            i++;
        }
        else if(s[i]=='+'){
            
            sig=0;
            i++;
        }
        while(s[i]=='0'){
            i++;
        }

        while(isdigit(s[i])){
            if(res>INT_MAX){
                if(sig)return INT_MIN;
                return INT_MAX;
            }
            res=(10*res+s[i]-'0');
            i++;
        }
        if(sig) res=res*-1;
        if(res>INT_MAX) return INT_MAX;
        if(res<INT_MIN) return INT_MIN;
        return (int) res;
    }
};