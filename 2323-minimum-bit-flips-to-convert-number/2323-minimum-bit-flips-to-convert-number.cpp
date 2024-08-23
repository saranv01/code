class Solution {
public:
    int minBitFlips(int start, int goal) {
     int fliped=start^goal;
     int cnt=0;
     for(int i=0;i<32;i++){
        if(1&fliped)cnt++;
        fliped>>=1;
     }   
     return cnt;
    }
};