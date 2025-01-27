class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        //floyd warshal
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





        // if(prerequisites.size()==0){
        //     vector<bool>r(queries.size(),false);
        //     return r;
        // }
        // vector<bool> result(queries.size());
        // vector<vector<int>>adj(numCourses);
        // vector<int>indegree(numCourses,0);
        // vector<pair<int,int>>orders;
        // queue<int>q;
        // for(auto it:prerequisites){
        //     adj[it[0]].push_back(it[1]);
        //     indegree[it[1]]++;
        // }
        // for(int i=0;i<numCourses;i++){
        //     if(indegree[i]==0){
        //         q.push(i);
        //         orders.push_back({i,0});
        //     }
        // }
        // int k=0;        
 
        // while(!q.empty()){
        //     k++;
        //     int x=q.size();
        //     while(x--){

            
        //     int node=q.front();
        //     // orders.push_back(node);
        //     q.pop();
        //     for(auto it:adj[node]){
        //         int a=it;
        //         indegree[a]--;
        //         if(indegree[a]==0){
        //             q.push(a);
        //             orders.push_back({a,k});
        //         }
        //     }
        //     }
        // }
        // for(int i=0;i<queries.size();i++){
        //     if(orders.size()!=numCourses){
        //         result[i]=false;
        //         continue;  
        //     }
        //     else{
        //         pair<int,int>f={-1,-1};
        //         pair<int,int>s={-1,-1};
        //         for(int j=0;j<orders.size();j++){
        //             if(queries[i][0]==orders[j].first){
        //                 f={j,orders[j].second};
        //             }
        //             if(queries[i][1]==orders[j].first){
        //                 s={j,orders[j].second};
        //             }
        //         }
        //         if(f.first<s.first&&f.second<s.second)result[i]=true;
        //         else result[i]=false;
        //     }
        // }
        // return result;
    }
};