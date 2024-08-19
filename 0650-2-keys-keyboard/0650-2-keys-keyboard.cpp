class Solution {
public:
    int mini=INT_MAX;
    int findStep( int all,int paste,int n){
            if(all==n){
                return 0;
            }
        if(all>n){

            return 10000;
        }
        int pasteAll=2+findStep(all*2,all,n);
        int pasteCur=1+findStep(all+paste,paste,n);
        return min(pasteAll,pasteCur);
    }
    int minSteps(int n) {
        if (n==1)return 0;
        return 1+findStep(1,1,n);
    }
};