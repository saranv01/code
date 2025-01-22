class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        
        vector<vector<int>> ans(n, vector<int>(m, -1)); 
        queue<pair<int, int>> q;
        
  
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
 
        vector<int> delx = {0, 1, 0, -1};
        vector<int> dely = {1, 0, -1, 0};
        
    
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            
            for (int k = 0; k < 4; k++) {
                int newx = i + delx[k];
                int newy = j + dely[k];
                
      
                if (newx < 0 || newx >= n || newy < 0 || newy >= m || ans[newx][newy] != -1) {
                    continue;
                }
                

                ans[newx][newy] = ans[i][j] + 1;
                q.push({newx, newy});
            }
        }
        
        return ans;
    }
};
