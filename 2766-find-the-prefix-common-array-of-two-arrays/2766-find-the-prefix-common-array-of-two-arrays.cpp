class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>Container;
        vector<int>preSums(A.size(),0);
        if(A[0]==B[0]){
            preSums[0]=1;
        }
        Container[A[0]]++;
        Container[B[0]]++;   
        for(int i=1;i<A.size();i++){
            preSums[i]=preSums[i-1];
            if(Container.find(A[i])!=Container.end()){
                preSums[i]=preSums[i-1]+1;
            }
            Container[A[i]]++;
            if(Container.find(B[i])!=Container.end()){
                if(preSums[i-1]+1==preSums[i])preSums[i]++;
                else
                preSums[i]=preSums[i-1]+1;
            }
            Container[B[i]]++;           

        }
        return preSums;
    }
};