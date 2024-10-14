class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
      int cnt=0;
      sort(g.begin(),g.end());
      sort(s.begin(),s.end());
      for(int i=0,j=0;i<g.size()&&j<s.size();){
        if(g[i]<=s[j]){
            i++;
            j++;
            cnt++;
        }
        else{
            j++;
        }
      }   
      return cnt;
    }
};