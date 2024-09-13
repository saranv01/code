class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //bfs and khan's algo
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adjList(numCourses);
        queue<int>q;
        for(auto it : prerequisites){
            adjList[it[1]].push_back(it[0]);
        }
        for(int i=0;i<numCourses;i++){
            for(auto it: adjList[i]){
                indegree[it]++;
            }
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            cnt++;
            q.pop();
            for(auto ad:adjList[node]){
                indegree[ad]--;
                if(indegree[ad]==0){
                    q.push(ad);
                }
            }
        }

        if(cnt==numCourses)return true;
        return false;
        
    }
};