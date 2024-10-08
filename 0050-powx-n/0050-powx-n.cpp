class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
    
        int bol=1;
        long long nn=n ;
        if(n<0){
            nn=(long)n*-1;;
            bol=0;
        }

        while(nn!=0){
            if(nn%2==0){
                nn=nn/2;
                x=x*x;
            }
            else{
                nn=nn-1;
                ans=ans*x;
            }
        }
        if(!bol){
            ans=1.0/ans;
        }
        return ans;
    }
};