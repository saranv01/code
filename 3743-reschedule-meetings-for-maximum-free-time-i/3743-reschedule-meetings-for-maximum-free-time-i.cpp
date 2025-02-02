class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int>gap;
        int maxFree=0;
        gap.push_back(startTime[0]-0);
        for(int i=0;i<startTime.size()-1;i++){
            gap.push_back(startTime[i+1]-endTime[i]);
        }
        gap.push_back(eventTime-endTime[endTime.size()-1]);
        for(int i=0;i<=k;i++){
            maxFree+=gap[i];
        }
        for(auto it:gap){
            cout<<"gap"<<it<<endl;
        }
        int j=0;
        int temp=maxFree;
        for(int i=k+1;i<gap.size();i++){
            temp=temp-gap[j++]+gap[i];
            maxFree=max(maxFree,temp);
        
        }
        return maxFree;
    }
};