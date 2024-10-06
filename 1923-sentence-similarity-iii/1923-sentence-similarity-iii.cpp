class Solution {
public:
    vector<string>sStream(string& sentence){
        vector<string>sset;
        stringstream ss(sentence);
        string str;


        while(getline(ss,str,' ')){
            sset.push_back(str);
        }
        return sset;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string>sset1;
        vector<string>sset2;
        sset1=sStream(sentence1);
        sset2=sStream(sentence2);
        if(sset1.size()>sset2.size()){
          return areSentencesSimilar(sentence2,sentence1);
        }
        int start1 = 0, start2 = 0;
        int end1 = sset1.size() - 1, end2 = sset2.size() - 1;
        while(start1<sset1.size()&&sset1[start1]==sset2[start2]){
            start1++;
            start2++;
        }
        while(end1>=0&&sset1[end1]==sset2[end2]){
            end1--;
            end2--;
        }
        return !(end1>=start1);

    }
};