class Solution {
public:
    int nCr(int row,int col){
        int result=1;
        for(int i=0;i<col;i++){
            result*=row-i;
            result/=i+1;
        }
        return result;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result(numRows);
        for(int i=0;i<numRows;i++){
            for(int j=0;j<=i;j++){
                result[i].push_back(nCr(i,j));
            }
        }
        return result;
    }
};