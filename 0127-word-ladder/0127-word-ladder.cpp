class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        queue<string> strq;
        set<string> stwords(wordList.begin(), wordList.end());
        strq.push(beginWord);
        int cnt = 1;
        while (!strq.empty()) {
            int k = strq.size();
            cnt++;
            while (k--) {

                string curWord = strq.front();

                strq.pop();

                for (int i = 0; i < curWord.size(); i++) {
                    for (int j = 0; j < 26; j++) {
                        string newword = curWord;
                        newword[i] = 'a' + j;
                        if (stwords.find(newword)!=stwords.end()) {
                            if (newword == endWord)
                                return cnt;
                            strq.push(newword);
                            stwords.erase(newword);
                        }
                    }
                }
            }
        }
        return 0;
    }
};