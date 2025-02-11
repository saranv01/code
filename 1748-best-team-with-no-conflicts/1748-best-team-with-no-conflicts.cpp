class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<int> scoresTillDp(n);
        vector<pair<int, int>> PlayerSA(n);

        for (int i = 0; i < n; i++) {
            PlayerSA[i] = {scores[i], ages[i]};
        }
        sort(PlayerSA.begin(), PlayerSA.end(),
             [](pair<int, int>& A, pair<int, int>& B) {
                 if (A.second == B.second)
                     return A.first < B.first;
                 return A.second < B.second;
             });
        for (int i = 0; i < n; i++) {
            scoresTillDp[i] = PlayerSA[i].first;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (((PlayerSA[j].first <= PlayerSA[i].first &&
                      PlayerSA[j].second <= PlayerSA[i].second)) &&
                    (scoresTillDp[j] + PlayerSA[i].first > scoresTillDp[i])

                ) {
                    scoresTillDp[i] = scoresTillDp[j] + PlayerSA[i].first;
                }
            }
        }
        return *max_element(scoresTillDp.begin(), scoresTillDp.end());
    }
};