class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>>isReachable(numCourses,vector<bool>(numCourses,false));
        vector<bool>result;
        for(auto it:prerequisites){
            isReachable[it[0]][it[1]]=true;
        }
        for(int k=0;k<numCourses;k++){
            for(int i=0;i<numCourses;i++){
                for(int j=0;j<numCourses;j++){
                    isReachable[i][j]=isReachable[i][j]||isReachable[i][k]&&isReachable[k][j];
                }
            }
        }
        for(int i=0;i<queries.size();i++){
            result.push_back(isReachable[queries[i][0]][queries[i][1]]);
        }
        return result;
    }
};