class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>ballColor;
        unordered_map<int,int>colorBallFreq;
        vector<int>result;
        for(int i=0;i<queries.size();i++){
            if(ballColor.find(queries[i][0])!=ballColor.end()){

                colorBallFreq[ballColor[queries[i][0]]]--;
                if(colorBallFreq[ballColor[queries[i][0]]]==0){
                    colorBallFreq.erase(ballColor[queries[i][0]]);
                }     
                ballColor.erase(queries[i][0]);
            }
            ballColor[queries[i][0]]=queries[i][1];
            colorBallFreq[queries[i][1]]++;
            result.push_back(colorBallFreq.size());
        }
        return result;
    }
};