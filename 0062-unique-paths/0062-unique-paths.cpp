class Solution {
public:
    int nCr(int n, int r){
        long long ans=1;
        if(r>n-r){
            r=n-r;
        }
        for(int i=0;i<r;i++){
            ans=ans*(n-i)/(i+1);
            
        }
        return (int) ans;
    }
    int uniquePaths(int m, int n) {
        return nCr(n+m-2,m-1);
    }
};