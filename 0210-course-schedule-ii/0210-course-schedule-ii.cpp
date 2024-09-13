class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            cnt++;
            ans.push_back(node);
            q.pop();
            for(auto ad:adjList[node]){
                indegree[ad]--;
                if(indegree[ad]==0){
                    q.push(ad);
                }
            }
        }

        if(cnt==numCourses)return ans;
        return {};
    }
};